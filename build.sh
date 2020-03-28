#!/usr/bin/bash

function build()
{
    if [ ! -d build ]; then
        mkdir build
    fi

    cd build
    cmake ..
    make

    if [ ! -z "${1}" ]; then
        ./${1}
    fi

    cd -
}

function clean()
{
    rm -r ./build/*
}
