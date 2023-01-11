#!/usr/bin/env bash

# Prepare autograder environment
add-apt-repository ppa:deadsnakes/ppa
add-apt-repository ppa:ubuntu-toolchain-r/test

apt-get update
apt-get install -y \
    build-essential \
    manpages-dev \
    apt-utils \
    software-properties-common \
    libtbb-dev \
    gcc-9 \
    g++-9 \
    gdb \
    clang \
    rsync \
    tar \
    python \
    valgrind \
    catch \
    cppcheck \
    dos2unix \
    jq

# Update C++ alternatives
apt-get clean
update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 90 \
    --slave /usr/bin/g++ g++ /usr/bin/g++-9 \
    --slave /usr/bin/gcov gcov /usr/bin/gcov-9

# Install Python dependencies declared in requirements.txt
apt-get install -y python python3-pip
pip3 install -r /autograder/source/requirements.txt

# Move python uploaded grader files into the same directory as run_autograder
cp /autograder/source/grade_util.py /autograder
cp /autograder/source/bootstrap.py /autograder
cp /autograder/source/config.yml /autograder
