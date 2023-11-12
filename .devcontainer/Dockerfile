#
# Copyright © 2023 inpyjama.com. All Rights Reserved.
# Author: Piyush Itankar <piyush@inpyjama.com>
#

FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu

ENV DEBIAN_FRONTEND=noninteractive

# Install main dependencies and some useful tools
RUN sudo apt-get update
RUN sudo apt-get install --no-install-recommends -y \
  ca-certificates \
  sudo \
  gdb-multiarch \
  binutils-common \
  make \
  curl \
  git-core \
  wget \
  nano \
  ssh \
  tree \
  less \
  build-essential \
  python3 \
  python3-dev \
  python3-pip \
  binutils \
  make \
  zsh \
  xxd \
  strace \
  man \
  cpio \
  libncurses5

RUN yes | unminimize
