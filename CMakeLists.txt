cmake_minimum_required(VERSION 3.10)

# project info
project(DS-Proj2)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    add_compile_options(/W4)
    add_compile_options(/O2)
else()
    add_compile_options(-Wall)
    add_compile_options(-O3)
endif()


add_executable(main main.cpp)

add_executable(karytest KAryTest.cpp)

add_custom_target(run $<TARGET_FILE:main>)
add_custom_target(runtest $<TARGET_FILE:karytest>)