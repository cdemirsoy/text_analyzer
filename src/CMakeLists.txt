set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.hpp)

set(SOURCES_FILES ${PROJECT_SOURCE_DIR}/src/MainUtility.cpp ${PROJECT_SOURCE_DIR}/src/TextAnalyzer.cpp ${PROJECT_SOURCE_DIR}/src/SortedList.cpp ${PROJECT_SOURCE_DIR}/src/main.cpp)
set(HEADER_FILES  ${PROJECT_SOURCE_DIR}/include/MainUtility.hpp ${PROJECT_SOURCE_DIR}/include/SortedList.hpp ${PROJECT_SOURCE_DIR}/include/TextAnalyzer.hpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${BINARY}_run ${SOURCES_FILES} ${HEADER_FILES})

add_library(${BINARY}_lib STATIC ${SOURCES_FILES} ${HEADER_FILES})