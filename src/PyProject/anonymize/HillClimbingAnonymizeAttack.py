# import numpy as np
# from abc import ABC, abstractmethod
# import evasion.utils_attack as ua
# import evasion.utils_attack_workflow as uaw
# import Configuration as Config
import os
import random
import sys
import traceback
import typing

import numpy as np
import pandas
import sklearn.utils

import Configuration as Config
import evasion.Transformers.TransformerBase
import evasion.utils_attack as ua
# todo
from anonymize.BBAttackInstance import BBAttackInstance
from classification.LearnSetups.LearnSetup import LearnSetup
from classification.MismatchException import MismatchException
from evasion.AttackMode import AttackMode
from evasion.AttackResult import AttackResult
from evasion.AttackStatus import AttackStatus
from evasion.Author import Author
from evasion.BBAttackHandler import BBAttackHandler
from evasion.BBBatchAttackInstanceHandler import BBBatchAttackInstanceHandler
from evasion.BlackBox.AttackSettings import HilllClimbingAnonymizeSettings


# from featureextractionV2.StyloFeatures import StyloFeatures


class HillClimbingAttack(BBAttackHandler):
    """
    Our Simulated Annealing + HillClimbingAttack procedure.
    This attack allows us to conduct a classic HillClimbingAttack,
    but also to perform a Simulated Annealing variant.
    """

    def __init__(self, attackdirauth: str,
                 sourceauthor: Author, targetauthor: Author,
                 learnsetup: LearnSetup,
                 # todo
                 hillclimbingsettings: HilllClimbingAnonymizeSettings,
                 initialseed: int = 42
                 ) -> None:

        # call parent's init method
        super(HillClimbingAttack, self).__init__(
            attackdirauth=attackdirauth, sourceauthor=sourceauthor, targetauthor=targetauthor,
            learnsetup=learnsetup, max_iterations=hillclimbingsettings.max_iterations,
            attack_mode=hillclimbingsettings.attack_mode,
            initialseed=initialseed, early_stop=hillclimbingsettings.early_stop
        )

        # set true if simulated annealing for next transformer
        self.simulated_annealing: bool = hillclimbingsettings.simulated_annealing
        # tuple to specify annealing params: first: k, second: x, third: z
        # at x. iteration decrease k by setting k = k*z
        self.simulated_annealing_params: typing.List[float, int, float] = list(
            hillclimbingsettings.simulated_annealing_params)
        self.hillclimbingsettings = hillclimbingsettings

    # @Overwrite
    def run_attack(self) -> AttackResult:

        # if untargeted or targeted attack was successful
        attackresult = AttackResult(sourceauthor=self.sauthor, targetauthor=self.tauthor)

        try:
            # a. Init Attack Instance
            attackinstance = BBAttackInstance(sourceauthor=self.sauthor, attackdirauth=self.attackdirauth,
                                              targetauthor=self.tauthor, bbattackhandler=self,
                                              attacksettings=self.hillclimbingsettings)
            attackresult.initial_distance = attackinstance.original_predscore
            attackresult.final_distance = attackresult.initial_distance
            attackresult.initial_feature_vec = attackinstance.attack_data_merged.getfeaturematrix()[0,
                                               :].toarray().reshape(-1)

            overallbesttransformerindex = -1
            overallbesttransfcall = -1
            best_round = -1

            # perform hill climbing
            for i in range(0, self.max_iterations):

                # create log dir for current iteration
                if Config.savemorelogfiles is True:
                    logdir_iter = os.path.join(attackinstance.log_directory, "hill" + str(i))
                    os.makedirs(logdir_iter)
                else:
                    logdir_iter = None

                # try all possible transformations.
                attackinstances = []
                queue = []  # multiprocessing.Queue() # for saving results
                processes_list = []

                transfrange = attackinstance.transformerhandler.update_check_number_available_transformers()
                for nextransformerindex in range(0, transfrange):
                    # clone attack instance = attack dir with source files for current transformation
                    newtemppath = os.path.join(self.attackdirauth, "temp" + str(nextransformerindex),
                                               self.sauthor.author)
                    tempattackinstance = attackinstance.clone(attackdirauth=newtemppath, newlogdir=logdir_iter)
                    attackinstances.append(tempattackinstance)

                    # choose transformer
                    currenttransformerobj: evasion.Transformers.TransformerBase = tempattackinstance.transformerhandler. \
                        get_specified_transformation_per_index(index=nextransformerindex)

                    processes_list.append((tempattackinstance, nextransformerindex, currenttransformerobj,
                                           i * 9 + nextransformerindex * 7, queue))

                # We've set up all dir's for each transformer. Now do them sequentially or in parallel via gnu-parallel.
                # start = time.time()
                if self.noofparallelthreads > 1:
                    pool = BBBatchAttackInstanceHandler(noofcores=self.noofparallelthreads,
                                                        attackdirauth=attackinstance.attackdirauth,
                                                        inputlist=processes_list)
                    queue = pool.batch_do_transformations()
                else:
                    for x in processes_list:
                        ua.run_hill_simulation(args=x)
                # end = time.time()
                # print("{}. iteration took {} s:".format(i, (end - start)))

                # Collect results
                bestminscore, besttransformerindex, bestattackinstance, besttransfcall = self.collect_results(
                    queue=queue,
                    attackinstances=attackinstances, attackinstance=attackinstance, i=i)

                # Save the best one
                if bestminscore < attackinstance.scoreprednew:
                    attackinstance = bestattackinstance.clone(attackdirauth=attackinstance.attackdirauth,
                                                              newlogdir=attackinstance.log_directory)
                    attackresult.final_distance = bestminscore
                    overallbesttransformerindex = besttransformerindex
                    overallbesttransfcall = besttransfcall
                    best_round = i

                attackinstance.logger.logger.debug("({} => {})".format(attackinstance.scores_in_score,
                                                                       max([x[1] for x in
                                                                            attackinstance.scores_in_score]) - min(
                                                                           [x[1] for x in
                                                                            attackinstance.scores_in_score])))

                attackinstance.logger.logger.info(
                    "~~> Best Instance: {},{}:`{}` successfull with {} ({}) [Before:{}({})]".
                        format(i, besttransformerindex, besttransfcall,
                               round(attackinstance.scoreprednew, 8), attackinstance.classprednew,
                               round(attackinstance.original_predscore, 4), self.tauthor.true_class))
                attackinstance.logger.logger.debug("\n\n")

                # Clean all the temp dir's
                for attinst in attackinstances:
                    attinst.cleandir(currentbaselevel=attackinstance.attackdirauth)

                if bestminscore < self.hillclimbingsettings.max_distance:
                    attackresult.attackstatus = AttackStatus.SUCCESS
                    break

                # early stop?
                if self.check_for_early_stop(attackinstance=attackinstance, current_iteration=i,
                                             bestminscore=bestminscore) is True:
                    break

            # collect further information about source file after evasion
            attackresult.final_feature_vec = attackinstance.attack_data_merged.getfeaturematrix()[0,
                                             :].toarray().reshape(-1)
            # we expect 5 columns, adapt this value if more..
            assert attackinstance.log_chosentransformers.shape[1] == 5
            attackresult.log_chosentransformers = attackinstance.log_chosentransformers
            attackresult.extract_changes_linesofcode(pathtooriginalfile=attackinstance.original_source_file,
                                                     pathtonewfile=attackinstance.source_file)

            attackinstance.logger.logger.debug("({} => {})".format(attackinstance.scores_in_score,
                                                                   max([x[1] for x in
                                                                        attackinstance.scores_in_score]) - min(
                                                                       [x[1] for x in attackinstance.scores_in_score])))

            attackinstance.logger.logger.info("-----> {} <----- from {} to {} \n".
                                              format(attackresult.attackstatus.name, self.sauthor.author,
                                                     self.tauthor.author))
        except MismatchException as e:
            err_msg: str = "***HillClimbing: Unexpected ERROR *** anonymize {} with {}".format(
                self.sauthor.author, str(e))
            print(err_msg, file=sys.stderr)
            attackresult.attackstatus = AttackStatus.ERROR
            attackresult.error_message = [str(err_msg)]
        except Exception as e:
            err_msg: str = "***HillClimbing: Unexpected ERROR *** anonymize {} with {}".format(
                self.sauthor.author, str(e))
            print(err_msg, file=sys.stderr)
            traceback.print_tb(e.__traceback__)
            attackresult.attackstatus = AttackStatus.ERROR
            attackresult.error_message = [str(err_msg), traceback.format_exc()]

        finally:
            try:
                attackinstance.logger.close_logger()
            except Exception:
                print("Could not close logger in attackinstance", file=sys.stderr)

            return attackresult

    def collect_results(self, queue: list, attackinstances: list, attackinstance: 'BBAttackInstance', i: int):
        """
        Collect the results and chooses the next transformation. Either the best (if not unique, choose one randomly)
        or if simulated annealing, choose among k best elements.
        :return:
        """

        # print queue in logging module
        for nextransformerindex, currenttransformer, besttransfcall, \
            successtransf, scoreprednew, classprednew in queue:
            if successtransf:
                attackinstance.logger.logger.debug("{},{}:`{}` successfull with {} ({}) [Before:{}({})]".format(
                    i, nextransformerindex, besttransfcall,
                    round(scoreprednew, 4), classprednew, round(attackinstance.original_predscore, 4),
                    self.tauthor.true_class))

        # now get the next transformer
        setascending = True if (self.sauthor.true_class == self.tauthor.true_class) else False
        queuetable = pandas.DataFrame(queue, columns=["nexttransfindex", "transf", "call", "suc", "score", "cla"])
        queuetable_sorted = queuetable.sort_values(by=['score'], ascending=setascending).reset_index(
            drop=True)
        # round scores so that we get better compare values and so that we have unique zeros, and not s.th. like 1e-18
        queuetable_sorted.score = queuetable_sorted.score.round(7)

        # at least one transformer should be possible, otherwise we can stop
        if queuetable_sorted.score.iloc[0] is None:  # or: queuetable_sorted.score.isnull().all():
            for attinst in attackinstances:
                attinst.cleandir(currentbaselevel=attackinstance.attackdirauth)
            raise Exception("No transformer was possible at current iteration: {}".format(i))

        # for simulated annealing, we need to know how many values are not zero; if all are zero, take one randomly
        all_zero: bool = np.all(queuetable_sorted.score[queuetable_sorted.score.notna()] == 0)

        if not self.simulated_annealing or all_zero == True:
            # we take the best element, if multiple have the same score, take one randomly
            bestelemsindices = np.where(queuetable_sorted.score == queuetable_sorted.score[0])[0]
            if bestelemsindices.shape[0] > 1:
                random.seed(self.seed + 17 * i)
                besttableindex = random.randint(0, bestelemsindices.shape[0] - 1)
                # print(">>> Multiple Options. Take option: {}".format(besttableindex))
            else:
                besttableindex = 0
        else:
            #                       *Simulated Annealing*
            # If we get a higher value from our best neighbor, we take it.
            # If we get only smaller values, the probability of choosing a worse result
            #   is given by the distance to the previous value and the temperature.

            valuebestbefore = np.round(attackinstance.log_chosentransformers.score.iloc[-1], 7)
            temperature = self.simulated_annealing_params[0]

            if setascending is True and queuetable_sorted.score.iloc[0] < valuebestbefore:
                # we are in dodging mode, so we favor smaller scores
                # if first element is already smaller, we know that other elements will also be smaller
                besttableindex = 0
            elif setascending is False and queuetable_sorted.score.iloc[0] > valuebestbefore:
                # impersonation: we favor higher scores
                besttableindex = 0
            else:
                # we have only worse results. we choose a transformer randomly based on the score distance
                if setascending is True:
                    negative_sim_anneal_indices = \
                        np.where(queuetable_sorted.score[queuetable_sorted.score.notna()] >= valuebestbefore)[0]
                    score_values_ = np.array(queuetable_sorted.score.iloc[negative_sim_anneal_indices])
                    score_values = np.exp(-(score_values_ - valuebestbefore) / temperature)
                else:
                    negative_sim_anneal_indices = \
                        np.where(queuetable_sorted.score[queuetable_sorted.score.notna()] <= valuebestbefore)[0]
                    score_values_ = np.array(queuetable_sorted.score.iloc[negative_sim_anneal_indices])
                    score_values = np.exp((score_values_ - valuebestbefore) / temperature)

                # print("->", np.round(score_values_, 3), "\n", np.round(score_values, 3))
                attackinstance.logger.debug_details("Sim-Annealing-Scores: {};\n{}". \
                                                    format(str(np.round(score_values_, 3)),
                                                           str(np.round(score_values, 3))))

                # iterate over each transformer from neighborhood, choose it w.r.t to probability given by its score.
                negative_sim_anneal_indices, score_values = sklearn.utils.shuffle(negative_sim_anneal_indices,
                                                                                  score_values,
                                                                                  random_state=self.seed + 21 * i)
                besttableindex = negative_sim_anneal_indices[0]
                probs = score_values / 2  # just to avoid that first elements are only considered..
                np.random.seed(self.seed + 19 * i)
                for sim in range(negative_sim_anneal_indices.shape[0]):
                    if bool(np.random.binomial(n=1, p=probs[sim])) is True:
                        besttableindex = negative_sim_anneal_indices[sim]
                        break

                attackinstance.logger.debug_details("Choose index: {} with p={}". \
                                                    format(besttableindex, str(np.round(probs, 3))))

        if i % self.simulated_annealing_params[1] == 0:
            self.simulated_annealing_params[0] = max(0.01, self.simulated_annealing_params[0] *
                                                     self.simulated_annealing_params[2])
            attackinstance.logger.debug_details(">>> Decrease k to: {}".format(self.simulated_annealing_params[0]))

        bestminscore: float = queuetable_sorted.score.iloc[besttableindex]
        besttransformerindex: int = queuetable_sorted.nexttransfindex.iloc[besttableindex]
        bestattackinstance: 'BBAttackInstance' = attackinstances[besttransformerindex]
        besttransfcall: str = queuetable_sorted.call.iloc[besttableindex]

        return bestminscore, besttransformerindex, bestattackinstance, besttransfcall

    def check_for_early_stop(self, attackinstance: BBAttackInstance,
                             current_iteration: int,
                             bestminscore: float) -> bool:
        """
        Check if we made progress and if not, stop...
        :return: true if early stop, false if we can continue
        """
        if self.early_stop is not None:
            # get last x scores and check if improvement, if not, break
            if current_iteration > self.early_stop:

                assert self.early_stop > 1  # value 1 makes no sense
                value_to_cmp = np.array(attackinstance.log_chosentransformers.score)[-self.early_stop]

                if self.attack_mode == AttackMode.DODGING:
                    break_attack: bool = value_to_cmp <= bestminscore
                elif self.attack_mode == AttackMode.IMPERSONATION_WITH_EXAMPLE_FILES or \
                        self.attack_mode == AttackMode.IMPERSONATION_WITHOUT_EXAMPLE_FILES:
                    break_attack: bool = value_to_cmp >= bestminscore
                else:
                    raise Exception("Unknown attack mode here in early stop")

                if break_attack is True:
                    attackinstance.logger.logger.info("\n Early Stop: {} vs. {} at {} (from {} to {})\n".
                                                      format(value_to_cmp, bestminscore, current_iteration,
                                                             self.sauthor.author, self.tauthor.author))
                    return True
        return False
