from featureextractionV2.StyloFeatures import StyloFeatures
import numpy as np
import typing


class StyloFeaturesProxy(StyloFeatures):
    """
    Handler to call all feature objects.

    We could easily implement a caching principle here, so that the feature matrix calculation is only
    done if something changes (e.g. by a tf-idf call). But we would need to implement here
    some sort of observer design pattern so that this class always knows if a referenced
    StyloFeatures object has changed.
    """

    def __init__(self, codestyloreference: StyloFeatures):
        super(StyloFeaturesProxy, self).__init__()
        self.codestyloreference = codestyloreference


    def getunique_key(self) -> str:
        return "_".join(["merged"])


    def getfeaturematrix(self):
        return self.codestyloreference.getfeaturematrix()

    def getcolnames(self):
        return self.codestyloreference.getcolnames()

    def getcolnamesraw(self):
        return self.codestyloreference.getcolnamesraw()

    def getauthors(self):
        return self.codestyloreference.getauthors()

    def getiids(self):
        return self.codestyloreference.getiids()

    def getlabels(self):
        return self.codestyloreference.getlabels()

    def createtfidffeatures(self, trainobject: typing.Optional['StyloFeatures']) -> None:
        if trainobject is not None:
            self.codestyloreference.createtfidffeatures(trainobject=trainobject.codestyloreference)
        else:
            self.codestyloreference.createtfidffeatures(trainobject=None)

    def selectcolumns(self, index: typing.Optional[np.ndarray], trainobject: typing.Optional['StyloFeatures']) -> None:
        if trainobject is not None:
            self.codestyloreference.selectcolumns(index=index, trainobject=trainobject.codestyloreference)
        else:
            self.codestyloreference.selectcolumns(index=index, trainobject=None)

    def __getitem__(self, index):
        return StyloFeaturesProxy(codestyloreference=self.codestyloreference[index])

    def create_stylo_object_from_train_object(self,
                                              src: str,
                                              inputdir: typing.Optional[str],
                                              outputdir: str,
                                              verbose: bool = None) -> 'StyloFeatures':
        assert self.codestyloreference is not None
        x: StyloFeatures = self.codestyloreference.create_stylo_object_from_train_object(
            src=src, inputdir=inputdir, outputdir=outputdir, verbose=verbose)
        return StyloFeaturesProxy(x)
