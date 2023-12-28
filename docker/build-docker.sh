#!/usr/bin/env bash

export LC_ALL=C

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/.. || exit

DOCKER_IMAGE=${DOCKER_IMAGE:-btcturquoise/btcturquoised-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/btcturquoised docker/bin/
cp $BUILD_DIR/src/btcturquoise-cli docker/bin/
cp $BUILD_DIR/src/btcturquoise-tx docker/bin/
strip docker/bin/btcturquoised
strip docker/bin/btcturquoise-cli
strip docker/bin/btcturquoise-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
