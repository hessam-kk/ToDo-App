cmake_minimum_required(VERSION 3.0)

project (ToDo)

set(SOURCES
    src/main.cpp
    src/Task.cpp
    src/Functions.cpp
)

add_executable(app ${SOURCES})

include_directories( include )