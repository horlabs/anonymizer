"""
This is a test file to verify that MCTS /SimAnnealing still produces the valid results.
You need to set up the paths correctly (e.g. create ramdisk if you usually also uses a ramdisk).
This file will not save any results in the Results-Directory, only on the temporary attack dir.
Moreover, decide on the evasion algorithm (MCTS or SimAnneal).
"""
import numpy as np
import pickle
import sys
import os

from evasion.AttackEval import AttackEvalImpersonation, AttackEvalAbstract
import evasion.utils_launch_attacks
import classification.utils_load_learnsetup
import classification.LearnSetups.LearnSetup
from evasion.AttackLogging import Global_Logging, SharedCounters
import Configuration as config
from evasion.AttackMode import AttackMode
from evasion.EvasionAlgorithm import EvasionAlgorithm
from evasion.BlackBox.AttackSettings import MCTSClassicSettings
import ConfigurationGlobalLearning


############### ############### ############### ############### ###############
## The only thing you have to do is to decide on attack algorith. Then just run and check if no warnings are shown later
evasion_algorithm: EvasionAlgorithm = EvasionAlgorithm.MCTS_Classic





############################################################# ##########################################################
PROBLEM_ID = "3264486_5736519012712448"
# PROBLEM_ID = "8294486_5630967708385280"
print("Load default problem id, as in python console mode. Will not parse args", file=sys.stderr)

threshold_sel: float = 1.5
learn_method: str = "RF"
feature_method: str = "Usenix"
IMPERSONATION = True

####
attackdir = os.path.join(config.attackdirConfig, "_".join(["test_mcts_simanneal_blackbox", PROBLEM_ID, feature_method, learn_method,
                                                 str(threshold_sel), str(IMPERSONATION), evasion_algorithm.name]))
config.createattackdir(attdir=attackdir)


possible_authors = ["ACMonster", "lazyBit", "chocimir", "ALOHA.Brcps"]
no_authors = None


authorspairs = [("ACMonster", "lazyBit"), ("ALOHA.Brcps", "chocimir")] #

resultsupperpath: str = os.path.join(config.attackdirConfig, "results")
resultsdir = os.path.join(resultsupperpath, "test_mcts_simanneal_blackbox", evasion_algorithm.name, feature_method,
                          learn_method, ("impersonation" if IMPERSONATION else "dodging"))
config.createattackdir(attdir=resultsdir)



############################################################# ##########################################################
# II. Get features #
config.datasetpath = os.path.join(config.repo_path, "data/dataset_2017/dataset_2017_8_formatted_macrosremoved")
testlearnsetup: classification.LearnSetups.LearnSetup.LearnSetup = classification.utils_load_learnsetup.load_learnsetup(
    learnmodelspath=os.path.join(ConfigurationGlobalLearning.learnmodelspath, "modelsuffix_unit_test"),
    feature_method=feature_method,
    learn_method=learn_method,
    problem_id=PROBLEM_ID,
    threshold_sel=threshold_sel)

# Data Check: check whether nan are there
print(np.min(testlearnsetup.data_final_train.getfeaturematrix()), np.max(testlearnsetup.data_final_train.getfeaturematrix()))  # make sure there are no NaN's
print(np.min(testlearnsetup.data_final_test.getfeaturematrix()), np.max(testlearnsetup.data_final_test.getfeaturematrix()))

############################################################# ##########################################################
# III. Attack -- Code Transformations #

seed_range = (40, 44)
assert IMPERSONATION is True

attackeval: AttackEvalAbstract = AttackEvalImpersonation(testlearnsetup=testlearnsetup,
                                                         attack_dir=attackdir,
                                                         no_authors=no_authors,
                                                         selected_authors=possible_authors,
                                                         verbose=False,
                                                         seed=31)

attack_mode__ = AttackMode.IMPERSONATION_WITH_EXAMPLE_FILES
if evasion_algorithm == EvasionAlgorithm.MCTS_Classic:

    settings_file = "test_amcts_impersonation_Usenix.ini"
    attack_settings: MCTSClassicSettings = MCTSClassicSettings.load_settings_from_file(
        path=os.path.join(config.ini_settings_evasionattack_path, settings_file),
        attack_mode=attack_mode__
    )

else:
    raise Exception("Wrong Evasion Algorithm")





################
# Now do hill climbing / simulated annealing / MCTS attack
# a. first, we need a global logger that logs success / error of all instances in one file for a better overview
#   but we also have an individual logger for each instance with much more detailed logs
logpath= os.path.join(attackdir, "logs")
global_logger = Global_Logging.logger_sequential_init(logfilepath=logpath)

# save settings
attack_settings.dump(logpath)

# b. generate all instances, put them into a list...
procs = []
for sourceauthor, targetauthor, attackdirauthtarget in attackeval.getNextAuthorPair(fix_pair=authorspairs):
    procs.append((sourceauthor, targetauthor, attackdirauthtarget, testlearnsetup, seed_range, global_logger))
print("\n".join(["*" * 35, "Attack on {} pairs".format(len(procs)), "*" * 35]))
shared_cntr = SharedCounters.SharedCounterSingle(len(procs))


# c. now perform evasion attack
for iteration, proc in enumerate(procs):
    retresult = evasion.utils_launch_attacks.launch_attack(proc, shared_cntr, attack_settings)
    attackeval.setAuthorPairResult2(attackresult=retresult, sourceauthor=retresult.sourceauthor,
                                    targetauthor=retresult.targetauthor)

    # save the result, update the final result after each author pair.
    resultsfile = os.path.join(resultsdir, "results_" + PROBLEM_ID + "_" + str(threshold_sel) + ".pck")
    with open(resultsfile, "wb") as curf:
        pickle.dump(attackeval.authorEvasionMapping, curf)


Global_Logging.close_logger_sequential(logger=global_logger)
print("Attack finished on " + PROBLEM_ID)

### Now perform some checks ###
import evasion.AttackResult
import evasion.AttackStatus

res_1: evasion.AttackResult.AttackResult = attackeval.authorEvasionMapping.loc['ACMonster', 'lazyBit']
assert res_1.attackstatus == evasion.AttackStatus.AttackStatus.SUCCESS

if evasion_algorithm == EvasionAlgorithm.MCTS_Classic:
    expected_scores = np.array([ 0.        , 0.04779412, 0.06413399, 0.06740196, 0.06740196])
else:
    raise Exception("Evasion Algorithm not supported here in test case!")
assert np.allclose(np.array(res_1.log_chosentransformers.score), expected_scores)


res_2: evasion.AttackResult.AttackResult = attackeval.authorEvasionMapping.loc['ALOHA.Brcps', 'chocimir']
assert res_2.attackstatus == evasion.AttackStatus.AttackStatus.SUCCESS

if evasion_algorithm == EvasionAlgorithm.MCTS_Classic:
    assert np.array(res_2.log_chosentransformers.transformer_id)[-1] == 'Typedef_add_listing'

    expected_scores = np.array([ 0.        ,  0.        ,  0.        ,  0.        ,  0.02647059,  0.05588235])
else:
    raise Exception("Evasion Algorithm not supported here in test case!")

assert np.allclose(np.array(res_2.log_chosentransformers.score), expected_scores)




