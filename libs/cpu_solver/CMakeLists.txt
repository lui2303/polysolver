add_library(cpu_solver STATIC
    src/solver.cpp
)

target_compile_features(cpu_solver PUBLIC cxx_std_20)

target_include_directories(cpu_solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)