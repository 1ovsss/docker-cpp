FROM silkeh/clang:latest

COPY ./src /app/src

WORKDIR /app/src

RUN clang++ -Wall -std=c++11 -include format.h -march=native main.cpp -o test

CMD "./test"
