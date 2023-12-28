FROM debian:stretch
LABEL maintainer="BTCturquoise Developers <dev@btcturquoiseverse.com>"
LABEL description="Dockerised BTCturquoiseCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
