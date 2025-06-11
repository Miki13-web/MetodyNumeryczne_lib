cmake_minimum_required(VERSION 3.10)
project(MetodyNumeryczne_lib)

set(CMAKE_CXX_STANDARD 17)

# Ścieżki
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# Biblioteka statyczna
add_library(numlib STATIC ${SOURCES})

# Przykłady
file(GLOB EXAMPLES "examples/*.cpp")
foreach(example_file ${EXAMPLES})
    get_filename_component(example_name ${example_file} NAME_WE)
    add_executable(${example_name} ${example_file})
    target_link_libraries(${example_name} numlib)
endforeach()

# Testy
file(GLOB TESTS "tests/*.cpp")
foreach(test_file ${TESTS})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} numlib)
endforeach()