cmake_minimum_required(VERSION 3.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(testSamaraHAL)
enable_testing()

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_VERBOSE_MAKEFILE true)

enable_language(C CXX ASM)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED on)
set(CXX_EXTENSIONS off)
set(C_STANDARD 17)
set(C_STANDARD_REQUIRED on)
set(C_EXTENSIONS off)

set(TEST_SOURCES
    testGPIO.c
    testGPIOcxx.cpp
)

add_compile_options(
    #optimization settings
    -Og

    #debugging settings
    -g

    #warnings
    -Wall
    -Wpedantic
    -Werror
    -Wfloat-equal
)

add_subdirectory(.. ../build/SAMARA_HAL)

foreach(TEST_SOURCE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    set(TEST_EXECUTABLE "${TEST_NAME}.elf")

    add_executable(${TEST_EXECUTABLE} ${TEST_SOURCE})

    target_link_libraries(${TEST_EXECUTABLE} SAMARA_HAL)

    add_test(NAME ${TEST_NAME} COMMAND "./${TEST_NAME}.elf")

endforeach(TEST_SOURCE TEST_SOURCES)


