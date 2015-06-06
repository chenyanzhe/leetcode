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
  RegularExpressionMatchingTest.cpp
  ContainerWithMostWaterTest.cpp
  IntegerToRomanTest.cpp
  RomanToIntegerTest.cpp
  LongestCommonPrefixTest.cpp
  3SumTest.cpp
  3SumClosestTest.cpp
  LetterCombinationsOfAPhoneNumberTest.cpp
  4SumTest.cpp
)

target_link_libraries(Test Solutions)
