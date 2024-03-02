"""
ATTACK EVALUATION ::::::: !!!!!! ::::::: !!!!!! :::::::
"""
import os
import pickle

import numpy as np

import Configuration as config
import classification.LearnSetups.LearnSetup
import classification.utils_load_learnsetup
import evasion.utils_launch_attacks
from evasion.AttackEval import AttackEvalImpersonation, AttackEvalFixedDodging, AttackEvalAbstract
from evasion.AttackLogging import Global_Logging, SharedCounters
from evasion.AttackMode import AttackMode
from evasion.BlackBox.AttackSettings import HilllClimbingAnonymizeSettings, MCTSAnonymSettings
from evasion.BlackBox.AttackSettings import SimAnnealingSettings, MCTSClassicSettings
from evasion.EvasionAlgorithm import EvasionAlgorithm

############################################################# ##########################################################

TEST_MODE = False  # choose true, if you just want to test s.th. without overwriting final results.... <<< Choose

# PROBLEM_ID = "3264486_5736519012712448"
# print("Load default problem id, as in python console mode. Will not parse args", file=sys.stderr)

parser = evasion.utils_launch_attacks.getProblemIDParser()
args = parser.parse_args()
PROBLEM_ID = args.problemid[0]

ch = 1
threshold_sel: float = [1.0, 800][ch]  # <<< Choose
learn_method: str = ["RF", "RNN"][ch]  # <<< Choose
feature_method: str = ["Usenix", "CCS18"][ch]  # <<< Choose
modelsuffix = "modelsuffix_c_only_formatted_macrosremoved_commentsremoved"
impersonation_with_examplefile: bool = True
IMPERSONATION = False
LOAD_ONLY_UNSUC_AUTHORS = False
evasion_algorithm: EvasionAlgorithm = EvasionAlgorithm.MCTS_Classic

############################################################# #############################################################
attackdir = os.path.join(config.attackdirConfig, "_".join(["blackbox", PROBLEM_ID, feature_method, learn_method,
                                                           str(threshold_sel), str(IMPERSONATION),
                                                           evasion_algorithm.name]))
if IMPERSONATION is True:
    attackdir = attackdir + "_" + str(impersonation_with_examplefile)
config.createattackdir(attdir=attackdir)

if TEST_MODE is False:
    if IMPERSONATION is True:
        if LOAD_ONLY_UNSUC_AUTHORS is False:
            no_authors, possible_authors, authorspairs = evasion.utils_launch_attacks.loadauthorpairs_impersonation(
                learnmodelspath=config.learnmodelspath, feature_method=feature_method,
                learn_method=learn_method, threshold_sel=threshold_sel)
        else:
            unsucprefix = "_".join(["authorpairs_unsuccessful", PROBLEM_ID,
                                    str(impersonation_with_examplefile), evasion_algorithm.name])
            no_authors, possible_authors, authorspairs = evasion.utils_launch_attacks.loadauthorpairs(
                learnmodelspath=config.learnmodelspath, prefix="UnsuccessfulAuthors/Impersonation/" + unsucprefix,
                feature_method=feature_method, learn_method=learn_method, threshold_sel=threshold_sel)

    else:
        if LOAD_ONLY_UNSUC_AUTHORS is False:
            possible_authors, no_authors, authorspairs = None, None, None
            # possible_authors = ["Ankzz"]
            # no_authors = None if possible_authors is None else len(possible_authors)
        else:
            unsucprefix = "_".join(["authorpairs_unsuccessful", PROBLEM_ID, evasion_algorithm.name])
            no_authors, possible_authors, authorspairs = evasion.utils_launch_attacks.loadauthors_dodging(
                learnmodelspath=config.learnmodelspath, prefix="UnsuccessfulAuthors/Dodging/" + unsucprefix,
                feature_method=feature_method, learn_method=learn_method, threshold_sel=threshold_sel)

else:
    possible_authors = ["ACMonster", "4yn"]  # , "AnonymousBunny"] #, "AnonymousBunny", "ALOHA.Brcps"]
    no_authors = None
    authorspairs = None

resultsupperpath: str = config.evasionattackpath if TEST_MODE is False else os.path.join(config.attackdirConfig,
                                                                                         "results")
resultsdir = os.path.join(resultsupperpath, "blackbox", evasion_algorithm.name, feature_method, learn_method,
                          ("impersonation" if IMPERSONATION else "dodging"))
if IMPERSONATION is True:
    resultsdir = os.path.join(resultsdir, "withexample_" + str(impersonation_with_examplefile))
config.createattackdir(attdir=resultsdir)

############################################################# ##########################################################
# II. Get features #
testlearnsetup: classification.LearnSetups.LearnSetup.LearnSetup = classification.utils_load_learnsetup.load_learnsetup(
    learnmodelspath=config.learnmodelspath,
    feature_method=feature_method,
    learn_method=learn_method,
    problem_id=PROBLEM_ID,
    threshold_sel=threshold_sel)

# Data Check: check whether nan are there
print(np.min(testlearnsetup.data_final_train.getfeaturematrix()),
      np.max(testlearnsetup.data_final_train.getfeaturematrix()))  # make sure there are no NaN's
print(np.min(testlearnsetup.data_final_test.getfeaturematrix()),
      np.max(testlearnsetup.data_final_test.getfeaturematrix()))

############################################################# ##########################################################
# III. Attack -- Code Transformations #

seed_range = (30, 31)
seed_range = (1337, 1338)
if IMPERSONATION:
    attackeval: AttackEvalAbstract = AttackEvalImpersonation(testlearnsetup=testlearnsetup,
                                                             attack_dir=attackdir,
                                                             no_authors=no_authors,
                                                             selected_authors=possible_authors,
                                                             verbose=False,
                                                             seed=31)
    attack_mode__ = AttackMode.IMPERSONATION_WITH_EXAMPLE_FILES if impersonation_with_examplefile is True \
        else AttackMode.IMPERSONATION_WITHOUT_EXAMPLE_FILES
    if evasion_algorithm == EvasionAlgorithm.SimAnnealing:
        attack_settings: SimAnnealingSettings = SimAnnealingSettings(
            max_iterations=25,
            early_stop=10,
            sim_annealing=False,
            sim_annealing_params=(10, 1, 1 / 2),
            attack_mode=attack_mode__
        )
    elif evasion_algorithm == EvasionAlgorithm.MCTS_Classic:
        if feature_method != "CCS18" and feature_method != "Usenix":
            raise Exception("Set up error")
        attack_settings: MCTSClassicSettings = MCTSClassicSettings(
            max_outer_iterations=15,
            max_inner_iterations=10,
            number_of_sequences_in_random_playout_0=135,
            number_of_sequences_in_random_playout_further=25,
            path_length_in_random_playout=5,
            repeat_template_transformers=20 if feature_method == "Usenix" else 12,
            attack_mode=attack_mode__,
            early_stop=14
        )
    else:
        raise Exception("Wrong Evasion Algorithm")

else:
    check_author: bool = True
    if evasion_algorithm == EvasionAlgorithm.SimAnnealing:
        attack_settings: SimAnnealingSettings = SimAnnealingSettings(
            max_iterations=36,
            early_stop=None,
            sim_annealing=False,
            sim_annealing_params=(10, 1, 1 / 2),
            attack_mode=AttackMode.DODGING
        )
    elif evasion_algorithm == EvasionAlgorithm.MCTS_Classic:
        if feature_method != "CCS18" and feature_method != "Usenix":
            raise Exception("Set up error")
        attack_settings: MCTSClassicSettings = MCTSClassicSettings(
            max_outer_iterations=35,
            max_inner_iterations=30,
            number_of_sequences_in_random_playout_0=40,
            number_of_sequences_in_random_playout_further=5,
            path_length_in_random_playout=3,
            repeat_template_transformers=20 if feature_method == "Usenix" else 12,
            attack_mode=AttackMode.DODGING,
            early_stop=30
        )
    elif evasion_algorithm == EvasionAlgorithm.MCTS_anonym:
        if feature_method != "CCS18" and feature_method != "Usenix":
            raise Exception("Set up error")
        check_author = False
        attack_settings: MCTSAnonymSettings = MCTSAnonymSettings(
            max_outer_iterations=35,
            max_inner_iterations=30,
            number_of_sequences_in_random_playout_0=40,
            number_of_sequences_in_random_playout_further=5,
            path_length_in_random_playout=3,
            repeat_template_transformers=20 if feature_method == "Usenix" else 12,
            attack_mode=AttackMode.DODGING,
            anonymity_set_size=5,
            max_distance=0.01,
            early_stop=30
        )
    elif evasion_algorithm == EvasionAlgorithm.HillClimbing_anonym:
        check_author = False
        attack_settings: HilllClimbingAnonymizeSettings = HilllClimbingAnonymizeSettings(
            max_iterations=36,
            early_stop=None,
            anonymity_set_size=4,
            max_distance=0.01,
            sim_annealing=False,
            sim_annealing_params=(10, 1, 1 / 2),
            attack_mode=AttackMode.DODGING
        )
    else:
        raise Exception("Wrong Evasion Algorithm")
    attackeval: AttackEvalAbstract = AttackEvalFixedDodging(testlearnsetup=testlearnsetup,
                                                            attack_dir=attackdir,
                                                            no_authors=no_authors,
                                                            selected_authors=possible_authors,
                                                            check_author=check_author,
                                                            verbose=False,
                                                            seed=31)

################
# Now start attacks
# a. first, we need a global logger that logs success / error of all instances in one file for a better overview
#   but we also have an individual logger for each instance with much more detailed logs
logpath = os.path.join(attackdir, "logs")
global_logger = Global_Logging.logger_sequential_init(logfilepath=logpath)

# save settings
attack_settings.dump(logpath)

# b. generate all instances, put them into a list...
# This was originally used for multiprocessing, but now we use gnu parallel to avoid all the python problems
# with multiprocessing.
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
