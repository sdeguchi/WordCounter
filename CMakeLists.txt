cmake_minimum_required(VERSION 3.6)
project(wordcounter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CountWords.cpp WordTree.h WordTree.cpp WordCounter.h WordCounter.cpp)
add_executable(wordcounter ${SOURCE_FILES})