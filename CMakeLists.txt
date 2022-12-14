cmake_minimum_required(VERSION 3.21)
project(CICD)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

add_executable(CICD main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Calc)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
