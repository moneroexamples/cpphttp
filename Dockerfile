FROM ubuntu:18.04

# Install dependencies

ARG DEBIAN_FRONTEND=noninteractive

RUN set -ex && \
    apt-get update && \
    apt-get install --no-install-recommends -y \
         apt-utils git \
         g++ cmake libjsoncpp-dev \
         uuid-dev zlib1g-dev && \
    \
    apt-get clean -y  

RUN mkdir -p /cpphttp

COPY . /cpphttp

WORKDIR /cpphttp

RUN set -ex && \
    git submodule init && git submodule update && \
    mkdir build && cd build && \
    cmake -D BUILD_TESTS=ON .. && \
    make -j 2 && \
    make tests

EXPOSE 8080

WORKDIR /cpphttp/build

ENTRYPOINT ["./cpphttp"]
