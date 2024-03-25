# On Challenges in Anonymizing Source Code

This is the repository for the submission "I still know it's you! On
Challenges in Anonymizing Source Code". This document contains
instructions on how to generate the datasets and results present in
the submission.

## Requirements

Our implementation builds on the code transformation framework
[Code Imitator](https://github.com/EQuiw/code-imitator). We have
modified and extended the framework, so that the different protection
techniques can be applied and evaluated in a unified manner. This
repository contains the resulting modified framework.

To setup the framework, we refer the reader to the
[build instructions](src/README.md) provided in the Github
repository. Additionally, in `src/LibToolingAST` the new files
[hooks.cpp](src/LibToolingAST/hooks.cpp) and
[libnocstd.c](src/LibToolingAST/libnocstd.c) have to be compiled. The
corresponding compiler calls are at the top of these files and they are also
incorporated into the cmake builds.

Finally the obfuscators [Stunnix](http://stunnix.com/prod/cxxo/) and
[Tigress](https://tigress.wtf/download.html) need to be downloaded and
installed. We developed fixes to compensate limitations of the
evaluation version of Stunnix. These are discussed below.

We provide a [Dockerfile](docker/Dockerfile) to setup the framework in a container.
This requires to use [BuildKit](https://docs.docker.com/build/buildkit/). As this
is sometimes not included in the installation, make sure the 
[buildx plugin](https://github.com/docker/buildx) is available at your CLI.

## Creating Datasets (Anonymization methods)

Next, we describe briefly how to generate the datasets we used in our
analysis with the candidates for anonymization. All files can afterwards be controlled for
output-equivalence by running [test_obfuscated_c.py](data/test_obfuscated_c.py).


### Tigress (Obfuscation 1)

First the dataset must be prepared to run tigress. Therefore call
[prepare_tigress.sh](data/tigress_tools/prepare_tigress.sh) (or the
`_advanced` option for our improvements) on every file.  Afterwards
run [obfuscate_tigress.sh](data/tigress_tools/obfuscate_tigress.sh) on
every prepared file. There are three options:

1. `--random` will activate a random seed. Without this option the
   seed is fixed.
2. `--rename` to obfuscate the files "inplace". Otherwise a new file
   `..obf.c` will be created.
3. `--advanced` to activate our improvements.

### Stunnix (Obfuscation 2)

First follow the instructions by Stunnix to obfuscate files. We used the evaluation
edition for our experiments, which you can download [here](http://stunnix.com/prod/cxxo/).
Afterwards run
[stunnix_postprocessing.sh](data/stunnix_tools/stunnix_postprocessing.sh) with the
output directory as argument.

### Normalization

For this purpose, run
[execute_transformers.py](src/PyProject/anonymize/execute_transformers.py)
with 
```bash
python anonymize/execute_transformers.py generate --numbering
```

### Coding style imitation

For this purpose, please refer to the
[READMEs of Imitator](https://github.com/EQuiw/code-imitator/blob/master/src/PyProject/README_EVASION.md).

## Train attribution models

See [original documentation](https://github.com/EQuiw/code-imitator/blob/master/src/PyProject/README_ATTRIBUTION.md) 
for code-imitator. We added
[feature_extraction_single_c.sh](data/extractfeatures_single_c.sh) to
extract features from C files.

## Classifications (Attribution methods)

One single file can be classified using
[classify.py](src/PyProject/anonymize/utils/classify.py).  To classify
whole datasets (on multiple models),
[this script](src/PyProject/anonymize/obfuscator_classify_dump.py)
will do all classifications for datasets and models specified in
[a copy of this file (named obfus_config.yaml)](src/PyProject/anonymize/obfus_config_example.yaml).

## Common issues

- Sometimes, DNS resolution is not working while building the image. Try to add
  `--network host` to your command, this should resolve this problem in most cases.