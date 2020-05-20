FROM ubuntu:18.04

# Install dependencies

ARG DEBIAN_FRONTEND=noninteractive
         #g++ cmake libjsoncpp-dev \

RUN set -ex && \
    apt-get update && \
    apt-get install -y \
         apt-utils git \
         g++ cmake  \
         uuid-dev zlib1g-dev libssl-dev && \
    \
    apt-get clean -y  

RUN mkdir -p /cpphttp

COPY . /cpphttp

WORKDIR /cpphttp

RUN set -ex && \
    ./scripts/initsubmodules.sh && \
    git submodule init && git submodule update && \
    mkdir -p  build && cd build && \
    cmake -D BUILD_TESTS=ON .. && \
    make -j 1 && \
    make tests

EXPOSE 8080

WORKDIR /cpphttp/build

CMD ["./cpphttp"]
