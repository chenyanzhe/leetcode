include_directories(${LeetCode_SOURCE_DIR}/include)

file(GLOB SOURCES "*.cpp")

add_library(Solutions ${SOURCES})