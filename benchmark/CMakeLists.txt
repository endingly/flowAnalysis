find_package(benchmark CONFIG REQUIRED)

aux_source_directory(. BENCHMARK_DIR_SRCS)
add_executable(${PROJECT_NAME}_benchmark ${BENCHMARK_DIR_SRCS})
target_link_libraries(
    ${PROJECT_NAME}_benchmark 
    benchmark::benchmark 
    benchmark::benchmark_main
    ${PROJECT_NAME}_lib
)
