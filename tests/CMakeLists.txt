include_directories(${LeetCode_SOURCE_DIR}/include)

file(GLOB SOURCES "*.cpp")

add_executable(Test ${SOURCES})

target_link_libraries(Test Solutions)
set_property(TARGET Test PROPERTY CXX_STANDARD 11)
set_property(TARGET Test PROPERTY CXX_STANDARD_REQUIRED ON)
