# LeetCode

![Language](https://img.shields.io/badge/language-C++-f34b7d.svg)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE.md)

## Getting Started

### Requirements

* C++11 compatible compiler: [g++](https://gcc.gnu.org/) (version >= 4.2), or [clang++](http://clang.llvm.org/cxx_status.html) (version >= 3.0)
* [CMake](http://www.cmake.org/) (version >= 3.0.2)

### Build Instructions

```
mkdir -p build
cd build
cmake ..
make
```

### Testing

All solutions have unit tests powered by [Catch](https://github.com/philsquared/Catch) framework. To run the tests, execute `tests/Test`.

Expected output:

```
===============================================================================
All tests passed (xxxx assertions in xxx test cases)
```

## Categories

* [Array](https://github.com/yanzhe-chen/leetcode#array)

## Array

| # | Title | Solution | Difficulty | Tag | Note |
|---|-------|----------|------------|-----|------|
1 | [Two Sum](https://leetcode.com/problems/two-sum/) | [src](./src/TwoSum.cpp) [test](./tests/TwoSumTest.cpp) | Easy ||
548 | [Split Array with Equal Sum](https://leetcode.com/problems/split-array-with-equal-sum/) | [src](./src/SplitArrayWithEqualSum.cpp) [test](./tests/SplitArrayWithEqualSumTest.cpp) | Medium | 🔒 |