FROM ubuntu:16.04

LABEL maintainer="Rafael Stahl"
LABEL version="1.0"

# Want bash substitutions.
SHELL ["/bin/bash", "-c"]

# Install required packages.
RUN apt-get update && apt-get install -y --no-install-recommends \
  wget \
  gcc \
  g++ \
  make \
  cmake \
  libboost-all-dev \
  xz-utils \
  bzip2 zip \
  git ssh \
  python-dev python-pip python-setuptools \
  openjdk-8-jre \
  texlive-latex-base \
  graphviz \
  zlib1g-dev \
  libtinfo-dev \
  doxygen \
  libcurl4-openssl-dev \
  subversion \
  apt-transport-https ca-certificates curl software-properties-common \
  && \
  curl -fsSL https://download.docker.com/linux/ubuntu/gpg | apt-key add - && \
  add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable" && \
  apt-get update && \
  apt-get install -y docker-ce && \
  apt-get remove -y python-pip python-setuptools && \
  apt-get clean && rm -rf /var/lib/apt/lists/*

# Update CMake.
ARG CMAKE_VER=3.14.6
RUN wget https://cmake.org/files/v${CMAKE_VER::-2}/cmake-${CMAKE_VER}.tar.gz && \
  tar xf cmake-${CMAKE_VER}.tar.gz && \
  cd cmake-${CMAKE_VER} && \
  mkdir build && cd build && cmake -DCMAKE_USE_SYSTEM_CURL=YES .. && make -j$(nproc) install && \
  hash -r && \
  cd ../.. && rm -rf cmake-${CMAKE_VER} && rm cmake-${CMAKE_VER}.tar.gz

# Install SystemC.
ARG SYSTEMC_VER=2.3.3
RUN wget http://www.accellera.org/images/downloads/standards/systemc/systemc-${SYSTEMC_VER}.gz && \
  tar xf systemc-${SYSTEMC_VER}.gz && \
  cd systemc-${SYSTEMC_VER} && \
  mkdir build && cd build && \
  ../configure && \
  make -j$(nproc) install && \
  cd ../.. && \
  rm -rf systemc-${SYSTEMC_VER} && rm systemc-${SYSTEMC_VER}.gz


ENV LD_LIBRARY_PATH="/usr/local/lib:${LD_LIBRARY_PATH}"
