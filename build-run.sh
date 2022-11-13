#!/bin/bash

docker build --rm -t docker-cpp-dev .
docker run docker-cpp-dev
docker rm $(docker ps -a -q)
