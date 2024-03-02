import os
import typing

import numpy as np

import Configuration as Config
import evasion.utils_attack as ua
from anonymize.utils import classify
from evasion.Author import Author
from evasion.BBAttackHandler import BBAttackHandler
from evasion.BBAttackInstance import BBAttackInstance as EBBAttackInstance
from evasion.BlackBox.AttackSettings import AttackSettings


# todo: inherit from evasion.BBAttackInstance
class BBAttackInstance(EBBAttackInstance):
    """
        A single attack instance.
    This class represents a directory where the source file will be saved and modified iteratively.
    The log files will be present in this directory, the input and output files,
    and when we extract the features, all the *.dat files will be saved in this directory.
    In other words, this class represents a particular state in the sequence of code transformations.

    Usually, an attack starts with such an attack instance (then the whole directory will be created under
    attackdirauth). Then, if we do a hill climbing attack/MCTS attack, we run various transformers.
    So we use the clone function to clone this attack instance to a new temporary sub-directory where the sub-directory
    represents a novel attack instance where the transformer was used.
    """

    def __init__(self, sourceauthor: Author, targetauthor: Author,
                 attackdirauth: str, bbattackhandler: 'BBAttackHandler',
                 attacksettings: 'AttackSettings') -> None:
        """
        Inits a single attack instance. If dodging attack, use the same Author object for sourceauthor and targetauthor.
        :param sourceauthor: the source author.
        :param targetauthor: the target author.
        :param attackdirauth: the path where attack happens
        :param bbattackhandler: a reference to attack handler -- the object that uses this attack instance.
        """

        self.attacksettings = attacksettings

        self.scores_in_score: typing.List[typing.Tuple[int, float]] = None

        super(BBAttackInstance, self).__init__(sourceauthor=sourceauthor, targetauthor=targetauthor,
                                               attackdirauth=attackdirauth, bbattackhandler=bbattackhandler,
                                               anonymize=True)

    # def __del__(self):
    # TODO -- and check how we do it with global attackinstance, if we clone, it should not be deleted..
    #     cleandirstr = os.path.realpath(os.path.join(self.attackdirauth, os.path.pardir))
    #     cleandirstrpar = os.path.realpath(os.path.join(cleandirstr, os.path.pardir))
    #
    #     print("~~~~~~~~~~~~~ ++ I will remove path:" + cleandirstr)
    #     if os.path.exists(cleandirstr):
    #         shutil.rmtree(cleandirstr)

    def clone(self, attackdirauth: str, newlogdir: str) -> 'BBAttackInstance':
        """
        TODO rewrite this method to correct deep_copy way...
        Clones this object / directory to new sub directory.
        Used for running a transformation without impact on the original source file.
        Used during hill climbing, if we try several transformations and choose the best.
        :param attackdirauth: the new attackdir
        :param newlogdir: new log directory path
        :return: returns a new BBAttackInstance
        """

        newobjinstance: 'BBAttackInstance' = super(BBAttackInstance, self).clone(attackdirauth, newlogdir)
        newobjinstance.attacksettings = self.attacksettings
        newobjinstance.scores_in_score = self.scores_in_score

        return newobjinstance

    # todo: merge anonymizing score in here?
    def get_model_prediction(self, source_file: str, target_class: int,
                             verbose: int = 1, already_extracted: bool = False) -> None:  # -> typing.Tuple[float, int]:

        self.get_anonymizing_score(source_file, verbose, already_extracted)

    def get_anonymizing_score(self, source_file: str,
                              verbose: int = 1,
                              already_extracted: bool = False) -> None:  # -> typing.Tuple[float, int]:

        # A. Load features TODO, use feature_paths instead of already_extracted...
        self.attack_data_merged = ua.load_new_features_merged(datasetpath=Config.datasetpath,
                                                              attackdirauth=os.path.dirname(source_file),
                                                              verbose=False, cppfile=source_file,
                                                              train_object=self.bbattackhandler.learnsetup.data_final_train,
                                                              already_extracted=already_extracted)

        # B. Evaluate and update score and class of target class

        probas = self.bbattackhandler.learnsetup.predict_probas(
            self.attack_data_merged.getfeaturematrix()[0, :])

        # B1. Find best neighborhood and calculate anonymity score
        neighborhood = classify.get_neighborhood(probas, self.attacksettings.anonymity_set_size - 1,
                                                 self.sourceauthor.true_class)
        anonymity_score = classify.get_anonymity_score(probas, neighborhood, self.sourceauthor.true_class)

        best_indices = [*neighborhood, self.sourceauthor.true_class]
        best_probas = [probas[x] for x in best_indices]
        # print(best_probas)

        self.scoreprednew = anonymity_score  # best_score  # max(best_probas) - min(best_probas)
        self.classprednew = self.bbattackhandler.learnsetup.predict(
            feature_vec=self.attack_data_merged.getfeaturematrix()[0, :])
        self.scores_in_score = list(zip(best_indices, best_probas))  # ToDo: Remove?

        if verbose >= 1:
            print("\t Pred:{} /({})".format(round(self.scoreprednew, 4), self.classprednew))
