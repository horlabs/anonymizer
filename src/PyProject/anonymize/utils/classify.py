import argparse
import re
import sys
import tempfile
from pathlib import Path
from typing import Union, List

import numpy as np
import pandas as pd
from scipy.stats import entropy

import ConfigurationGlobalLearning as Config
import classification.LearnSetups.LearnSetup
import classification.utils_load_learnsetup

file_re = re.compile(
    "([0-9]+_[0-9]+)_([a-zA-Z0-9.-]+)(?:_raw_|_raw_format_){0,1}[0-9]*(?:_before|_after_transf_|_final_|_original)?(?:\.out|\.obf)?\.c(?:pp)?$")


def get_learnsetup(problem: str, feature_method: str = "Usenix", learn_method: str = "RF",
                   threshold: Union[float, int] = 1.0,
                   learnmodelspath: str = Config.learnmodelspath,
                   modelsuffix: str = None) -> classification.LearnSetups.LearnSetup.LearnSetup:
    if modelsuffix is not None:
        learnmodelspath = str(Path(learnmodelspath).joinpath("modelsuffix_" + modelsuffix))
    return classification.utils_load_learnsetup.load_learnsetup(
        learnmodelspath=learnmodelspath,
        feature_method=feature_method,
        learn_method=learn_method,
        problem_id=problem,
        threshold_sel=threshold
    )


def get_features(author, file, learnsetup):
    with tempfile.TemporaryDirectory(prefix=author + "_", dir="/tmp") as tmpdir:
        features = learnsetup.data_final_train.create_stylo_object_from_train_object(src=file,
                                                                                     inputdir=None,
                                                                                     outputdir=tmpdir)
        features.createtfidffeatures(trainobject=learnsetup.data_final_train)
        features.selectcolumns(trainobject=learnsetup.data_final_train, index=None)

    return features


def get_label_position(probas, label):
    sorted_indices = np.argsort(probas)[::-1]
    return np.where(sorted_indices == label)[0][0].item()


def get_neighborhood(probas: Union[List[float], pd.Series], size: int,
                     label: Union[int, float, np.float64, np.int64]) -> List[int]:
    if isinstance(label, np.float64) or isinstance(label, float):
        label: int = int(label)
    original_proba = probas[label]
    differences = [abs(p - original_proba) if i != label else 1.337 for i, p in enumerate(probas)]
    neighbor_indices: np.ndarray = np.argsort(differences)[:size]
    return list(neighbor_indices.tolist())


def get_anonymity_score(probas: List[float], neighborhood: List[int], label: int) -> float:
    anonymity_set = neighborhood + [label]
    anonymity_set_scores = [probas[i] for i in anonymity_set]
    anonymity_score = max(anonymity_set_scores) - min(anonymity_set_scores)
    return anonymity_score


def get_best(probas, count=50):
    best_indices = np.argsort(probas)[::-1][:count]
    best_probas = [probas[x] for x in best_indices]

    return best_indices.tolist(), best_probas


def classify(file,
             learnsetup: classification.LearnSetups.LearnSetup = None,
             features=None,
             modelsuffix: str = None):
    problem, author = file_re.search(Path(file).name).groups()
    if author.endswith(".out"):
        author = author[:-4]

    if author.endswith(".obf"):
        author = author[:-4]

    if learnsetup is None:
        learnsetup = get_learnsetup(problem, modelsuffix=modelsuffix)

    if features is None:
        features = get_features(author, file, learnsetup)

    label = learnsetup.data_final_train.getlabels()[learnsetup.data_final_train.getauthors() == author][0]

    probas = learnsetup.predict_probas(features.getfeaturematrix())

    return label.item(), probas


def main(file: str, modelsuffix: str):
    original_label, probas = classify(file, modelsuffix=modelsuffix)
    best_indices, best_probas = get_best(probas, 5)
    neighborhood = get_neighborhood(probas, 4, original_label)
    print(get_anonymity_score(probas, neighborhood, original_label))

    print(f"Diff: {max(best_probas) - min(best_probas)}")

    for idx, proba in list(zip(best_indices, best_probas)):
        print(f"{idx:4d}: {proba * 100:06.3f}")

    print(f"Prediction: {np.argmax(probas)}")
    print(f"Original:   {original_label}")
    print(f"Original label position: {get_label_position(probas, original_label)}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Get classification and probabilities for a single source file")
    parser.add_argument("modelsuffix", metavar="MODELSUFFIX", type=str, help="Suffix of model to classify")
    parser.add_argument("file", metavar="FILE", type=str, help="File to process")
    args = parser.parse_args()
    if not Path(args.file).exists():
        print("File not found", file=sys.stderr)
        exit(-1)
    if file_re.match(Path(args.file).name) is None:
        print("Filename doesn't match the specification", file=sys.stderr)
        exit(-1)
    main(args.file, args.modelsuffix)
