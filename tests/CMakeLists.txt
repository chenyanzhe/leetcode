include_directories(${LeetCode_SOURCE_DIR}/src)

add_executable(Test main.cpp
  TwoSumTest.cpp
  AddTwoNumbersTest.cpp
)

target_link_libraries(Test Solutions)
