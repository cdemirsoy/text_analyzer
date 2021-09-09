cmake_minimum_required(VERSION 3.10)
project(TextAnalyzer)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -std=c++17")
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -Wall -pedantic -Wextra -std=c++17")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

set(CMAKE_OUTPUT ${CMAKE_SOURCE_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_SOURCE_DIR}/build/CMakeFiles/TextAnalyzer.dir)
message("-- Object files will be output to: ${OBJECT_DIR}")

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build
    )
add_custom_command(TARGET gcov
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/MainUtility.cpp -o ${CMAKE_SOURCE_DIR}/build/src/CMakeFiles/TextAnalyzer_lib.dir/MainUtility.gcno
        | grep -A 5 "MainUtility.cpp" > CoverageSummary.tmp
    COMMAND echo "working?"

    COMMAND cat CoverageSummary.tmp
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage  # Need separate command for this line
    )
add_dependencies(gcov TextAnalyzer_run)
# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

# Create the gcov-clean target. This cleans the build as well as generated 
# .gcda and .gcno files.
add_custom_target(scrub
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

# Testing
enable_testing()

#add_test(output_test ${CMAKE_CURRENT_BINARY_DIR}/TextAnalyzer_run)
#set_tests_properties(output_test PROPERTIES PASS_REGULAR_EXPRESSION "0;5;10")



add_test(output_test ${CMAKE_CURRENT_BINARY_DIR}/tst/TextAnalyzer_test)
set_tests_properties(output_test PROPERTIES PASS_REGULAR_EXPRESSION "0;5;10")