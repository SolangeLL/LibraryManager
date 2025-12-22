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

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(LibraryManager PRIVATE -Wall -Wextra)
endif()
if ( MSVC )
    target_compile_options(LibraryManager PRIVATE /W4)
endif()

target_include_directories(
    LibraryManager PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_sources(LibraryManager PRIVATE
    src/main.cpp
    src/services/LoanService.cpp
    src/services/InputService.cpp
    src/commands/Add.cpp
    src/commands/Borrow.cpp
    src/commands/Delete.cpp
    src/commands/Display.cpp
    src/commands/Login.cpp
    src/commands/Return.cpp
    src/commands/Help.cpp
    src/repositories/InMemoryBookRepository.cpp
    src/utils/BookFactory.cpp
)

target_link_libraries(LibraryManager PRIVATE fmt::fmt)