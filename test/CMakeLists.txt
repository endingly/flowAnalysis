add_library(${PROJECT_NAME}_lib ${SRC})
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(
    ${PROJECT_NAME}_lib PUBLIC 
    fmt::fmt
    $<$<BOOL:${ENBALE_STACK_TRACE}>:Backward::Backward>
    Eigen3::Eigen
    nlohmann_json::nlohmann_json
    paraller_computing
    glog::glog
)

file(GLOB_RECURSE TEST_SOURCES "*.cpp")
add_executable(${PROJECT_NAME}_test ${TEST_SOURCES})
target_link_libraries(
    ${PROJECT_NAME}_test
    GTest::gtest 
    GTest::gtest_main 
    ${PROJECT_NAME}_lib
)