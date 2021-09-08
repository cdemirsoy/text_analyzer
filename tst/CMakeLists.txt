set(BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.hpp *.cpp)

set(SOURCES ${TEST_SOURCES})

set(SOURCES_FILES ${PROJECT_SOURCE_DIR}/tst/main.cpp ${PROJECT_SOURCE_DIR}/tst/MainUtilityTest.cpp ${PROJECT_SOURCE_DIR}/tst/SortedListTest.cpp ${PROJECT_SOURCE_DIR}/tst/TextAnalyzerTest.cpp)
set(HEADER_FILES  ${PROJECT_SOURCE_DIR}/include/MainUtility.hpp ${PROJECT_SOURCE_DIR}/include/SortedList.hpp ${PROJECT_SOURCE_DIR}/include/TextAnalyzer.hpp)

include_directories(${PROJECT_SOURCE_DIR}/include)


add_executable(${BINARY} ${SOURCES_FILES} ${HEADER_FILES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

add_custom_command(TARGET TextAnalyzer_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:TextAnalyzer_test> ${PROJECT_SOURCE_DIR}/bin/TextAnalyzer_test
    COMMENT "Created ${PROJECT_SOURCE_DIR}/bin/TextAnalyzer_test"
)