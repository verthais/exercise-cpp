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

function format()
{
    if which clang-format > /dev/null; then
        find ./src \
        -type f \
        -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)' \
        -exec clang-format -style=WebKit -i {} \;
    else
        echo "Please install clang-format."
        exit 1
    fi
}
