include_directories(${LeetCode_SOURCE_DIR}/src)

add_executable(Test main.cpp
  TwoSumTest.cpp
  AddTwoNumbersTest.cpp
  LongestSubStringWithoutRepeatingCharactersTest.cpp
  MedianOfTwoSortedArraysTest.cpp
  LongestPalindromicSubstringTest.cpp
  ZigZagConversionTest.cpp
  ReverseIntegerTest.cpp
  StringToIntegerTest.cpp
  PalindromeNumberTest.cpp
)

target_link_libraries(Test Solutions)
