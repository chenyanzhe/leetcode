include_directories(${LeetCode_SOURCE_DIR}/src)

file(GLOB SOURCES "*.cpp")

add_executable(Test ${SOURCES})

target_link_libraries(Test Solutions)