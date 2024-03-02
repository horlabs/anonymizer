import csv
import sys
import threading
from pathlib import Path
from typing import Union, List, Optional
import time

import numpy as np
import yaml
from tensorflow import Session
from tqdm import tqdm
from typing_extensions import TypedDict, Literal

import ConfigurationGlobalLearning as Config
import utils.classify
from classification.LearnSetups.LearnSetup import LearnSetup
from featureextractionV2.StyloFeatures import StyloFeatures


class ModelType(TypedDict):
    suffix: str
    short: str
    type: Literal["c", "cpp"]
    method: Optional[Literal["RNN", "RF"]]
    problems: Optional[List[str]]


class ProblemsType(TypedDict):
    c: List[str]
    cpp: List[str]


class DatasetType(TypedDict):
    dir: str
    short: str
    suffix: str
    models: Optional[List[str]]
    attack: Optional[bool]
    ignore_unchanged: Optional[bool]


class DatasetsType(TypedDict):
    c: Optional[List[DatasetType]]
    cpp: Optional[List[DatasetType]]


class ConfigType(TypedDict):
    datasets: DatasetsType
    problems: ProblemsType
    models: List[ModelType]
    learning_methods: List[Literal["RNN", "RF"]]


no_authors = 81
title_row: List[str] = ["file", "label", "position_author", ]
for i in range(no_authors):
    title_row.append(f"{i}")
lock_rnn: threading.Lock = threading.Lock()
lock_rf: threading.Lock = threading.Lock()
lock_rnn_starting: threading.Lock = threading.Lock()
lock_all_started: threading.Lock = threading.Lock()


def format_floats(rows: List[List[Union[str, int, float]]]) -> List[List[Union[str, int, float]]]:
    for i in range(len(rows)):
        rows[i] = [f"{x:0.10f}" if type(x) == np.float64 or type(x) == np.float32 else x for x in rows[i]]
    return rows


def RF_worker(problem: str, model: ModelType, dataset: DatasetType,
              modelpath: Path, datasetpath: Path, joerndats: Path,
              ignore_unchanged: bool = False):
    short_id: str = f"{model['short']}|{dataset['short']}|{model['type'].upper()}|{problem}\nRF"
    filename: str = short_id.replace("|", "-").replace("\n", "-") + ".csv"
    rows: List[List[Union[str, int, float]]] = []

    with lock_rf:
        learnsetup: LearnSetup = utils.classify.get_learnsetup(problem, "Usenix", "RF", 1.0,
                                                               learnmodelspath=str(modelpath))
    iids = []
    if joerndats is not None:
        dataset_features: StyloFeatures = learnsetup.data_final_train.create_stylo_object_from_train_object(
            src=str(datasetpath),
            inputdir=str(joerndats),
            outputdir="/tmp/test",
            verbose=False
            )
        dataset_features.createtfidffeatures(trainobject=learnsetup.data_final_train)
        dataset_features.selectcolumns(trainobject=learnsetup.data_final_train, index=None)
        iids = learnsetup.data_final_test.getiids()
    else:
        not_attacked = yaml.safe_load(open(datasetpath.joinpath("not_attacked.yaml")))
        for author in datasetpath.iterdir():
            if not author.is_dir():
                continue
            if ignore_unchanged and f"{problem}_{author.name}.c" in not_attacked[problem]:
                continue
            for f in author.iterdir():
                if not f.name.endswith("_advex.c"):
                    continue
                if problem not in f.name:
                    continue

                iids.append((author.name, str(f), f.name))
        print(iids)

    with lock_all_started:
        pass

    for iid in tqdm(iterable=iids, desc=short_id, delay=60, mininterval=60, maxinterval=300,
                     file=open("/dev/null", "w")):
        if isinstance(iid, tuple):
            dataset_features = utils.classify.get_features(iid[0], iid[1], learnsetup)
            iid = iid[2]
        if iid not in dataset_features.getiids():
            continue
        author = dataset_features.getauthors()[dataset_features.getiids() == iid][0]
        label = learnsetup.data_final_test.getlabels()[learnsetup.data_final_test.getauthors() == author][0]
        features = dataset_features.getfeaturematrix()[dataset_features.getiids() == iid]
        probas = learnsetup.predict_probas(features)
        probas_sorted_indices = np.argsort(probas)[::-1]
        index = np.where(probas_sorted_indices == label)[0][0]
        row: List[Union[str, int, float]] = [iid, label, index]
        row.extend(probas)

        rows.append(row)

    rows = format_floats(rows)

    with open(Path(Config.repo_path).joinpath("data", "csvs", filename), "w") as f:
        # print("Write", filename)
        writer = csv.writer(f)
        writer.writerow(title_row)
        writer.writerows(rows)


def RNN_worker(problem: str, model: ModelType, dataset: DatasetType,
               modelpath: Path, datasetpath: Path, advex: bool = False,
               ignore_unchanged: bool = False):
    lock_rnn_starting.acquire()
    short_id = f"{model['short']}|{dataset['short']}|{model['type'].upper()}|{problem}\nRNN"
    filename: str = short_id.replace("|", "-").replace("\n", "-") + ".csv"
    rows: List[List[Union[str, int, float]]] = []
    thread_session = Session()
    with thread_session.as_default():
        with lock_rnn:
            learnsetup: LearnSetup = utils.classify.get_learnsetup(problem, "CCS18", "RNN", 800,
                                                                   learnmodelspath=str(modelpath))

        iids = []
        if not advex:
            dataset_features: StyloFeatures = learnsetup.data_final_train.create_stylo_object_from_train_object(
                src=str(datasetpath),
                inputdir=None,
                outputdir="/tmp/test",
                verbose=False
                )
            dataset_features.createtfidffeatures(trainobject=learnsetup.data_final_train)
            dataset_features.selectcolumns(trainobject=learnsetup.data_final_train, index=None)
            iids = learnsetup.data_final_test.getiids()
        else:
            not_attacked = yaml.safe_load(open(datasetpath.joinpath("not_attacked.yaml")))
            for author in datasetpath.iterdir():
                if not author.is_dir():
                    continue
                if ignore_unchanged and f"{problem}_{author.name}.c" in not_attacked[problem]:
                    continue
                for f in author.iterdir():
                    if not f.name.endswith("_advex.c"):
                        continue
                    if problem not in f.name:
                        continue

                    iids.append((author.name, str(f), f.name))
            print(iids)

        if lock_rnn_starting.locked():
            lock_rnn_starting.release()

        with lock_all_started:
            pass
        
        for iid in tqdm(iterable=iids, desc=short_id, delay=0, mininterval=60, maxinterval=300,
                         file=open("/dev/null", "w")):
            if isinstance(iid, tuple):
                dataset_features = utils.classify.get_features(iid[0], iid[1], learnsetup)
                iid = iid[2]
            if iid not in dataset_features.getiids():
                continue
            author = dataset_features.getauthors()[dataset_features.getiids() == iid][0]
            label = learnsetup.data_final_test.getlabels()[learnsetup.data_final_test.getauthors() == author][0]
            features = dataset_features.getfeaturematrix()[dataset_features.getiids() == iid]
            probas = learnsetup.predict_probas(features)
            probas_sorted_indices = np.argsort(probas)[::-1]
            index = np.where(probas_sorted_indices == label)[0][0]
            row: List[Union[str, int, float]] = [iid, label, index]
            row.extend(probas)

            rows.append(row)

        rows = format_floats(rows)
        with open(Path(Config.repo_path).joinpath("data", "csvs", filename), "w") as f:
            # print("Write", filename)
            writer = csv.writer(f)
            writer.writerow(title_row)
            writer.writerows(rows)


config: ConfigType = yaml.safe_load(open("anonymize/obfus_config.yaml"))
models: List[ModelType] = config["models"]
outdir: Path = Path(Config.repo_path).joinpath("data", "csvs")
if not outdir.exists():
    outdir.mkdir(exist_ok=True)
datasets: DatasetsType = config["datasets"]
problems: ProblemsType = config["problems"]
learning_methods: List[Literal["RNN", "RF"]] = config["learning_methods"]
threads: List[threading.Thread] = []
for idx, model in enumerate(models):
    print(f"## Modelsuffix: {model['suffix']} ({idx + 1}/{len(models)})")
    for dataset in datasets[model["type"]]:
        if "models" in dataset and dataset["models"] is not None:
            if model["short"] not in dataset["models"]:
                continue
        print(f"### Dataset: dataset{dataset['suffix']} ({dataset['dir']})")
        for problem in problems[model['type']]:
            print(f"Starting problem {problem}")
            lock_all_started.acquire()
            if "problems" in model and model["problems"] is not None:
                if problem not in model["problems"]:
                    lock_all_started.release()
                    continue
            modelpath = Path(Config.learnmodelspath).joinpath("modelsuffix_" + model['suffix'])
            datasetpath = Path(Config.repo_path).joinpath(dataset["dir"], "dataset" + dataset["suffix"])
            joerndats = Path(Config.repo_path).joinpath(dataset["dir"], "libtoolingfeatures" + dataset["suffix"])

            rf_active = "RF" in learning_methods
            rnn_active = "RNN" in learning_methods

            if "method" in model and model["method"] is not None:
                rf_active = "RF" in model["method"]
                rnn_active = "RNN" in model["method"]

            if not joerndats.exists() or ("attack" in dataset and dataset["attack"]):
                joerndats = None

            # RF
            if rf_active:
                t: threading.Thread = threading.Thread(
                    target=RF_worker,
                    args=(problem, model, dataset, modelpath, datasetpath, joerndats,
                          ("ignore_unchanged" in dataset and dataset["ignore_unchanged"])))
                t.start()
                threads.append(t)

            # RNN
            if rnn_active:
                #lock_rnn_starting.acquire()
                print("Start RNN..")
                t: threading.Thread = threading.Thread(
                    target=RNN_worker,
                    args=(problem, model, dataset, modelpath, datasetpath, joerndats is None,
                          ("ignore_unchanged" in dataset and dataset["ignore_unchanged"])))
                t.start()
                threads.append(t)
                time.sleep(1)
                print("Waiting for RNN to start..", end="", flush=True)
                with lock_rnn_starting:
                    pass
                print("RNN started")

            lock_all_started.release()
            print(f"Waiting for jobs for {model['suffix']} dataset{dataset['suffix']} {problem} to finish")
            modelsuffix = model["suffix"].replace("_", "\_")
            datasetsuffix = dataset['suffix'].replace("_", "\_")
            problem = problem.replace("_", "\_")
            for thread in tqdm(threads, file=sys.stdout):
                thread.join()
            print(f"All jobs for {modelsuffix} dataset{datasetsuffix} {problem} finished")
print("Experiment finished")
