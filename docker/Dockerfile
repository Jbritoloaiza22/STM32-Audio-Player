FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    make \
    git \
    wget \
    curl \
    ca-certificates \
    python3 \
    python3-pip \
    ruby-full \
    xz-utils \
    gnupg \
    lsb-release \
    software-properties-common \
    && rm -rf /var/lib/apt/lists/*

# Install Ceedling for unit testing
RUN gem install ceedling

# Install LLVM / clang-format
RUN wget https://apt.llvm.org/llvm.sh && \
    chmod +x llvm.sh && \
    ./llvm.sh 22 && \
    apt-get update && \
    apt-get install -y clang-format-22 && \
    ln -sf /usr/bin/clang-format-22 /usr/bin/clang-format

# Install ARM GNU Toolchain
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu/12.2.mpacbti-rel1/binrel/arm-gnu-toolchain-12.2.mpacbti-rel1-x86_64-arm-none-eabi.tar.xz \
    && tar -xf arm-gnu-toolchain-12.2.mpacbti-rel1-x86_64-arm-none-eabi.tar.xz -C /opt \
    && mv /opt/arm-gnu-toolchain-* /opt/arm-toolchain \
    && rm arm-gnu-toolchain-12.2.mpacbti-rel1-x86_64-arm-none-eabi.tar.xz

ENV PATH="/opt/arm-toolchain/bin:${PATH}"

WORKDIR /workspace