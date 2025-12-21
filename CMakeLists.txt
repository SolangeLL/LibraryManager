cmake_minimum_required(VERSION 3.23)

project(LibraryManager)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.1.1
)
FetchContent_MakeAvailable(fmt)

add_executable(LibraryManager)

target_include_directories(
    LibraryManager PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_sources(LibraryManager PRIVATE
    src/main.cpp
    src/services/LoanService.cpp
)

target_link_libraries(LibraryManager PRIVATE fmt::fmt)