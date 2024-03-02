FROM ubuntu:18.04
RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y  git \
        vim \
        wget \
        xz-utils \
        parallel \
        cmake \
        libncurses5-dev \
        libstdc++-5-dev \
        libtinfo-dev \
        lib32z1-dev \
        build-essential \
        python3.6 \
        python3-pip \
        default-jdk
RUN update-alternatives --install /usr/bin/python python `which python3.6` 1
RUN yes 'will cite' | parallel --citation

RUN wget -q https://releases.llvm.org/5.0.0/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04.tar.xz
RUN tar -xf clang+llvm-5.0.0-linux-x86_64-ubuntu16.04.tar.xz -C /
RUN rm clang+llvm-5.0.0-linux-x86_64-ubuntu16.04.tar.xz
ENV PATH=$PATH:/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/bin
RUN echo "export PATH=\$PATH:/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/bin" >> /root/.bashrc

RUN wget -q https://boostorg.jfrog.io/artifactory/main/release/1.65.1/source/boost_1_65_1.tar.gz
RUN tar -xf boost_1_65_1.tar.gz -C /
RUN rm boost_1_65_1.tar.gz

RUN git clone https://github.com/include-what-you-use/include-what-you-use.git /iwyu
WORKDIR /iwyu
RUN git checkout clang_5.0
RUN mkdir build
WORKDIR /iwyu/build
RUN cmake -G "Unix Makefiles" -DIWYU_LLVM_ROOT_PATH=/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/ ..
RUN make

WORKDIR /code-imitator
COPY data/ /code-imitator/data
RUN mkdir /code-imitator/src
COPY src/README.md /code-imitator/src/
COPY src/CodeStyloJava /code-imitator/src/CodeStyloJava
COPY src/ExternalTransformers /code-imitator/src/ExternalTransformers
WORKDIR /code-imitator/src/CodeStyloJava
RUN javac -cp SCAA/commons.io_2.0.1.jar:. -d classes Naive\ Baseline/src/*.java
COPY docker/manifest.txt .
RUN jar cfm naive_baseline.jar manifest.txt -C classes .
RUN echo "export CMD_DIR_NAIVEBASELINEJAR=/code-imitator/src/CodeStyloJava/naive_baseline.jar" >> /root/.bashrc

COPY src/LibToolingAST /code-imitator/src/LibToolingAST
RUN mkdir /code-imitator/src/LibToolingAST/cmake-build-release

WORKDIR /code-imitator/src/LibToolingAST/cmake-build-release
RUN cmake .. -DMY_CLANG_ROOT_DIR=/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04 -DMY_BOOST_ROOT_DIR=/boost_1_65_1
RUN make

COPY src/PyProject /code-imitator/src/PyProject
ENV PYTHONPATH=/code-imitator/src/PyProject
RUN echo "export PYTHONPATH=/code-imitator/src/PyProject" >> /root/.bashrc
WORKDIR /code-imitator/src/PyProject
RUN python -m pip install -r requirements.txt
COPY docker/config.ini .
RUN python UnitTests/testFeatureExtractionv2.py
RUN python UnitTests/test_learningv2.py
RUN python UnitTests/EvasionTesting/test_MCTS.py

WORKDIR /code-imitator
