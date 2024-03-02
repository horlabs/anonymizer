import typing

from featureextractionV2.ClangTypes.StyloClangFeaturesAbstract import StyloClangFeaturesAbstract

from featureextractionV2.FeatureNames import FeatureName
import numpy as np
from scipy import sparse
import utils_authorship

import featureextractionV2.utils_extraction_testtime
from featureextractionV2.StyloFeatures import StyloFeatures


class StyloASTMaxPropertyFeature(StyloClangFeaturesAbstract):

    def __init__(self,
        inputdata: typing.Union[str, list],
        verbose: bool,
        trainobject: typing.Optional['StyloClangFeaturesAbstract'],
        featureclassidentifier: str, tf: bool, idf: bool):

        self.verbose: bool = verbose
        super(StyloASTMaxPropertyFeature, self).__init__(inputdata=inputdata, verbose=verbose, tf=tf, idf=idf,
                                                    trainobject=trainobject, featureclassidentifier=featureclassidentifier)


    def getunique_key(self) -> str:
        return "_".join([self.featureclassidentifier, str(self.tf), str(self.idf)])


    # @Overwrite
    def read_data_from_source(self, inputdata, trainobject):

        self._featurematrix, self._colnames, self._authors, self._iids = self.__extract_max_depth_ast_node(inputdata)
        return self._featurematrix, self._colnames, self._authors, self._iids


    def __extract_max_depth_ast_node(self, inputdata):
        """
        Extracts the max depth of each ast node per file-programmer
        File format of json. For each author one line, each line has the pattern: <name> <id_id> <max-depth>
        Uses param: curfilepath: the path to the json file
        :return: features, authors, iids
        """

        if not isinstance(inputdata, str) and not isinstance(inputdata, list):
            raise Exception("Unvalid inputdata type")

        if isinstance(inputdata, str):
            with open(inputdata, "r") as f:
                ast_node_lines = [line.rstrip('\n') for line in f]
        else:
            ast_node_lines = [line.rstrip('\n') for line in inputdata]

        features = []
        authors = []
        iids = []

        for cl in range(len(ast_node_lines)):
            try:
                features.append(ast_node_lines[cl].split(" ")[2])
                authors.append(ast_node_lines[cl].split(" ")[0].replace("_advex", ""))
                iids.append(ast_node_lines[cl].split(" ")[1])
            except Exception as e:
                import sys
                print("Error in file {} in row: {}".format(inputdata, cl), file=sys.stderr)
                print("{0}".format(e), file=sys.stderr)
                raise e


        # sort entries
        authors = np.array(authors)
        iids = np.array(iids)
        feature_matrix = sparse.csr_matrix(np.array(features, dtype=np.float32)).transpose()
        feature_matrix, iids, authors = utils_authorship.sortmatrix(matrix1=feature_matrix, matrix1ids=iids,
                                                                    matrix1authors=authors)

        # D. tf-idf transf.
        featurename: FeatureName = FeatureName(colname=self.featureclassidentifier, coltype="continous",
                                               colorigin=self.featureclassidentifier)
        # feature_matrix, feature_names = self._apply_tf_idf_normalization(featmatrix=feature_matrix,
        #                                                                  featurenames=[featurename])

        return feature_matrix, [featurename], authors, iids

    def create_stylo_object_from_train_object(self,
                                              src: str,
                                              inputdir: typing.Optional[str],
                                              outputdir: str,
                                              verbose: bool = None) -> 'StyloFeatures':

        dict_clang = featureextractionV2.utils_extraction_testtime.extractfeatures_clang(
            src=src, input_dir=inputdir, output_dir=outputdir, featureclassidentifier=self.featureclassidentifier
        )

        clangmatrix_att = StyloASTMaxPropertyFeature(inputdata=dict_clang[self.featureclassidentifier + ".dat"],
                                                     verbose=self.verbose,
                                                     trainobject=self, tf=self.tf, idf=self.idf,
                                                     featureclassidentifier=self.featureclassidentifier)

        if self.codestyloreference is not None:
            x = self.codestyloreference.create_stylo_object_from_train_object(src=src, inputdir=inputdir,
                                                                              outputdir=outputdir)
            clangmatrix_att.setnextstylo(x)

        return clangmatrix_att
