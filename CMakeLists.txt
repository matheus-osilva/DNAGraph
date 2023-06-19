cmake_minimum_required(VERSION 3.25)
project(DNAGraph)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DNAGraph
        createedges.cpp
        createedges.h
        dna.cpp
        dna.h
        main.cpp SymbolGraph.cpp SymbolGraph.h  Digraph.cpp Digraph.h)
