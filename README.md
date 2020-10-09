# Example of C++ http server 

Example setup and use of [drogon](https://github.com/an-tao/drogon) to provide json http rest server.


### Project download and compilation on Ubuntu 18.04

```bash
# go to home folder
cd ~

# drogon dependencies
sudo apt install libjsoncpp-dev uuid-dev zlib1g-dev

# for Mac OS X using brew
brew install ossp-uuid jsoncpp zlib

git clone --recurse-submodules https://github.com/moneroexamples/cpphttp

cd cpphttp

mkdir build && cd build

cmake ..

make
```
### Using docker

```bash
# go to home folder
cd ~

git clone --recurse-submodules https://github.com/moneroexamples/cpphttp

# build cpphttp docker image
docker build ./my-dev-repo/ -t "cpphttp"

# run the container (without saving)
docker run --rm  -ti -p 8080:8080 --name cpphttp cpphttp 

# test the cpphttp
curl -w '\n' localhost:8080

# kill the container
docker kill cpphttp
```

## How can you help

Constructive criticism, code and website edits are always good. They can be made through github.
