# cmake_minimum_required(VERSION 3.26.0)

# project(paraller_computing VERSION 0.1.0 LANGUAGES CUDA CXX)

set(CMAKE_CUDA_ARCHITECTURES 80)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_EXTENSIONS OFF)

file(GLOB_RECURSE _paraller_computing_source "src/*.cu")
add_library(paraller_computing ${_paraller_computing_source})
target_include_directories(paraller_computing PUBLIC include)