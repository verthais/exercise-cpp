#!/bin/bash
# Copyright (c) 2019 verthais

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

function help()
{
    echo "Usage: ./build.sh [option]"
    echo ""
    echo "Run this script in the root folder There is no default options."
    echo ""
    echo "Options:"
    echo "build   <exercise>   build the project. This command might run the project"
    echo "                     if the executable name is given."
    echo "clean                cleans the build directory."
    echo "format               runs clang-format with -style=Webkit on project files."
    echo "help                 prints this help."
}

if [[ -z "$_" ]]; then
    echo "Script is being sourced."
else
    case "${1}" in
    "format") format;;
    "clean") clean;;
    "build") build "$2";;
    "help") help;;

    *) echo "Invalid argument."
       help
       exit 1;;
    esac
fi