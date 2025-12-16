cmake_minimum_required(VERSION 3.23)

project(LibraryManager)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryManager)

target_include_directories(
    LibraryManager PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_sources(LibraryManager PRIVATE
    src/main.cpp
    src/services/LoanService.cpp
)