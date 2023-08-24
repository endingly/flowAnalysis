cmake_minimum_required(VERSION 3.26.0)

project(cpp20_demo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


file(GLOB_RECURSE SRC "src/*.cppm")

add_executable(cpp20_demo ${SRC})
target_include_directories(cpp20_demo PUBLIC include)
target_compile_options(
    cpp20_demo PRIVATE
    /interface
    /TP
    /reference
)