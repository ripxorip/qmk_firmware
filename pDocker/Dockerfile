FROM debian:bullseye

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
    build-essential \
    gcc \
    unzip \
    wget \
    zip \
    gcc-avr \
    binutils-avr \
    avr-libc \
    dfu-programmer \
    dfu-util \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    bear \
    ccls \
    git

RUN apt-get install -y sudo

ARG USERNAME=buster
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid 1000 buster
RUN useradd -s /bin/bash --uid 1000 --gid 1000 -m buster

# Setup USER
RUN echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME
USER ${USERNAME}

RUN git config --global user.name "Philip Karlsson Gisslow"
RUN git config --global user.email "philipkarlsson@me.com"

RUN sudo mkdir /workspace
RUN sudo chown -R buster:buster /workspace

# Run using - docker run -dit -v /workspace:/home/buster/dev/docker/qmk/workspace -w /workspace qmk