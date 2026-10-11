cmake_minimum_required(VERSION 3.20)

project(polysolver LANGUAGES CXX)

add_subdirectory(libs/cpu_solver)

add_executable(polysolver
    src/main.cpp
)

target_compile_features(polysolver PRIVATE cxx_std_20)

target_compile_options(polysolver PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

target_link_libraries(polysolver PRIVATE cpu_solver)