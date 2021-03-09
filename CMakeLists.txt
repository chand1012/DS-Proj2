cmake_minimum_required(VERSION 3.10)

# project info
project(DS-Proj2)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall)
endif()


add_executable(main main.cpp)

add_custom_target(run $<TARGET_FILE:main>)
