FROM: ubuntu:latest

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends -y \
cmake \ 
valgrind \ 
git \ 
g++ \ 
clang \
cppcheck \
doxygen \
graphviz \
libgtest-dev \
&& apt-get clean && rm -rf /var/lib/apt/lists/*
