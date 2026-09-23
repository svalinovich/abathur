cmake_minimum_required(VERSION 3.20)

project(abathur
    VERSION 0.1.0
    DESCRIPTION "Chess engine."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(abathur ${ENGINE_SOURCES})

target_include_directories(abathur
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(abathur
    PRIVATE
        -Wall
        -Wextra
        -Werror
)
