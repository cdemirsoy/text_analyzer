set(BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.hpp *.cpp)

set(SOURCES ${TEST_SOURCES})

set(SOURCES_FILES ${PROJECT_SOURCE_DIR}/tst/main.cpp ${PROJECT_SOURCE_DIR}/tst/MainUtilityTest.cpp)
set(HEADER_FILES  ${PROJECT_SOURCE_DIR}/include/MainUtility.hpp ${PROJECT_SOURCE_DIR}/include/SortedList.hpp ${PROJECT_SOURCE_DIR}/include/TextAnalyzer.hpp)

include_directories(${PROJECT_SOURCE_DIR}/include)


add_executable(${BINARY} ${SOURCES_FILES} ${HEADER_FILES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)