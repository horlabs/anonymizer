import json
import os
from pathlib import Path
import sys
# import importlib
import typing

import numpy as np
from sklearn.model_selection import StratifiedKFold

import ConfigurationGlobalLearning as Config
import classification.NovelAPI.utils_classification
import evasion.utils_launch_attacks
from ConfigurationLearning.ConfigurationLearning import ConfigurationLearning
from classification import StratifiedKFoldProblemId
from featureextractionV2 import utils_extraction
from featureextractionV2.StyloFeatures import StyloFeatures
from featureextractionV2.StyloFeaturesProxy import StyloFeaturesProxy

############### Input ##############
parser = evasion.utils_launch_attacks.getProblemIDParser()
args = parser.parse_args()
PROBLEM_ID_LOADED = args.problemid[0]

############### Variable Definition ##############

configuration_learning: ConfigurationLearning = ConfigurationLearning(
    repo_path=Config.repo_path,
    dataset_features_dir=os.path.join(Config.repo_path, "data/dataset_github"),
    suffix_data="_github_macrosremoved",
    learnmodelspath=Config.learnmodelspath,
    use_lexems=False,
    use_lexical_features=False,
    stop_words=Config.stop_words_codestylo,
    probsperprogrammer=Config.probsperprogrammer,
    no_of_programmers=81,#30,
    noofparallelthreads=23,#8,
    hyperparameters={"n_estimators": [30, 250, 300, 350],
                     "max_features": [0.1, 0.2, 0.3, 0.4, 0.5, "log2", "sqrt"],
                     "max_depth": [10, 15, 20, 25, 30, 40, 50],  # 50
                     "min_samples_leaf": [2, 4, 6, 8, 10, 12, 14],
                     }
)


learn_method: str = ["RF", "SVM", "DNN"][0]
feature_method: str = ["Usenix", "CCS18"][0]
threshold_sel: typing.Union[int, float] = [1.0, 800][0]

# Directory where model files will be stored, set None if you do not want to save anything, or specify a path.
if configuration_learning.learnmodelspath is not None:
    modelsavedir = os.path.join(configuration_learning.learnmodelspath, feature_method + "_" + learn_method)
    os.makedirs(modelsavedir) if not os.path.exists(modelsavedir) else print("Use existing dir for models", file=sys.stderr)
else:
    modelsavedir = None


############## Get lexical, layout and syntactic features ##############

if feature_method == "Usenix":
    features_merged: StyloFeaturesProxy = utils_extraction.extract_link_train_test_usenix_features(
        config_learning=configuration_learning)

elif feature_method == "CCS18":
    assert configuration_learning.use_lexems is not True
    unigrammmatrix_train: StyloFeatures = utils_extraction.extract_train_test_unigram(
        config_learning=configuration_learning, tf=True, idf=True, ngram_range=(1, 3))
    features_merged: StyloFeaturesProxy = StyloFeaturesProxy(codestyloreference=unigrammmatrix_train)

else:
    raise Exception("feature_method")


############## Split dataset into train - test set with our our grouped stratified k-fold ##############
advex_items = np.char.endswith(features_merged.getiids(), "_advex.c")
normal_items = np.where(~advex_items)[0]
advex_items = np.where(advex_items)[0]

if PROBLEM_ID_LOADED != "github":
    skf2 = StratifiedKFoldProblemId.StratifiedKFoldProblemId(iids=features_merged.getiids(), n_splits=8, 
                                                             random_state=411,
                                                             nocodesperprogrammer=configuration_learning.probsperprogrammer)
else:
    split = []
    #  TODO: make this an argument
    split_file = os.path.join(configuration_learning.datasetpath, "train_test_split.json")
    # mit np.where die indizes finden
    with open(split_file) as f:
        content = json.load(f)
    train_files = [Path(x).name for x in content["train"]]
    test_files = [Path(x).name for x in content["test"]]
    train_items = np.argwhere(np.in1d(features_merged.getiids(), train_files)).reshape((len(train_files),))
    test_items = np.argwhere(np.in1d(features_merged.getiids(), test_files)).reshape((len(test_files),))
    #print(test_items)
    split.append((train_items, test_items))
    # für testzwecke ausgeben
    #print("No splits:", len(split))
    normal_items = train_items
    skf2 = StratifiedKFold(n_splits=7, shuffle=True, random_state=411)
print("No splits:", skf2.get_n_splits())


############## Do training + testing on each split ##############
accuracy = {}

if PROBLEM_ID_LOADED != "github":
    splits = list(skf2.split(features_merged.getiids()[normal_items], features_merged.getlabels()[normal_items]))
    split_test_iids = None

    for i in range(skf2.get_n_splits()):
        if split_test_iids is None:
            split_test_iids = features_merged.getiids()[normal_items][splits[i][1]]
        else:
            split_test_iids = np.vstack((split_test_iids, features_merged.getiids()[normal_items][splits[i][1]]))

    np.save(os.path.join(modelsavedir, "test_iids_" + str(threshold_sel) + "_" + PROBLEM_ID_LOADED + ".npy"), split_test_iids)

for i, (train_index, test_index) in enumerate(skf2.split(features_merged.getiids()[normal_items], features_merged.getlabels()[normal_items]) if PROBLEM_ID_LOADED != "github" else split):
    curproblemid = "_".join(features_merged.getiids()[test_index[0]].split("_")[0:2])
    if curproblemid == PROBLEM_ID_LOADED or PROBLEM_ID_LOADED == "github" or i == int(PROBLEM_ID_LOADED):
        test_index = sorted(list(normal_items[test_index]) + (list(advex_items[test_index] if len(advex_items) > 0 else [])))
        train_index = sorted(list(normal_items[train_index]) + (list(advex_items[train_index]) if len(advex_items) > 0 else []))
        from collections import Counter
        cnt = Counter(features_merged.getlabels()[test_index])
        if len(features_merged.getlabels()[test_index]) != len(list(cnt.items())):
            print(cnt)
            assert len(set(features_merged.getlabels()[test_index])) == len(list(cnt.items()))
        assert cnt.most_common(1)[0][1] in [1,2]
        cnt = Counter(features_merged.getlabels()[train_index])
        assert cnt.most_common(1)[0][1] in [6,12]
        # the following method saves the model and config file into modelsavedir if given
        accuracy, _ = classification.NovelAPI.utils_classification.perform_standard_classification_for_split(
            features_merged=features_merged,
            train_index=train_index,
            test_index=test_index,
            problem_id_test=PROBLEM_ID_LOADED,
            configuration_learning=configuration_learning,
            modelsavedir=modelsavedir,
            threshold_sel=threshold_sel,
            learn_method=learn_method,
            skf2=skf2
        )

print(accuracy)
accuracies = np.array([x for x in accuracy.values()])
print(np.mean(accuracies))
print(np.sqrt(np.var(accuracies)))
