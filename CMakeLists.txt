cmake_minimum_required(VERSION 3.26.0)

project(flowAnalysis VERSION 0.1.0 LANGUAGES CUDA CXX)

# project settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES)
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif()

option(ENBALE_STACK_TRACE "enable stack trace" OFF)
option(ENABLE_TEST "enable test" ON)

# package settings
find_package(fmt CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
if(ENBALE_STACK_TRACE)
    find_package(Backward CONFIG REQUIRED)
endif()



file(GLOB_RECURSE SRC "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(
    ${PROJECT_NAME} PUBLIC 
    fmt::fmt
    $<$<BOOL:${ENBALE_STACK_TRACE}>:Backward::Backward>
    Eigen3::Eigen
    nlohmann_json::nlohmann_json
    paraller_computing
    glog::glog
)
target_compile_options(${PROJECT_NAME} PUBLIC -openmp)

add_subdirectory(sub_extension/parallel_computing)

if(ENBALE_STACK_TRACE)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ENABLE_STACK_TRACE)
endif()

if(ENABLE_TEST)
    add_subdirectory(test)
    add_subdirectory(benchmark)
endif()