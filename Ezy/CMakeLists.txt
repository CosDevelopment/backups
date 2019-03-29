cmake_minimum_required(VERSION 3.12)
project(Ezy)

set(CMAKE_CXX_STANDARD 14)

include_directories(EzyC)
include_directories(EzyC/Unimplemented)
include_directories(libs)

add_executable(Ezy
        EzyC/Unimplemented/Compile.cpp
        EzyC/Unimplemented/Compile.hpp
        EzyC/Unimplemented/Log.cpp
        EzyC/Unimplemented/SymbolTable.cpp
        EzyC/Unimplemented/SymbolTable.hpp
        EzyC/Common.hpp
        EzyC/Qlog.hpp
        EzyC/Syntax.cpp
        EzyC/Syntax.hpp
        EzyC/Tokenizer.cpp
        EzyC/Tokenizer.hpp
        libs/rang.hpp
        main.cpp)
