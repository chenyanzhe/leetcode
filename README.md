# LeetCode

![Language](https://img.shields.io/badge/language-C++-f34b7d.svg)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](./LICENSE.md)
[![Docs](https://readthedocs.org/projects/leetcode-book/badge/)](http://leetcode-book.readthedocs.org/)
![Progress](https://img.shields.io/badge/progress-247%20%2F%20289-orange.svg)

Solutions to LeetCode in C++.

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

## Problems

* [Tree](#tree)

### Tree

  #  | Title           | Difficulty    |
-----|---------------- | ------------- |
 94  | [Binary Tree Inorder Traversal](src/BinaryTreeInorderTraversal.cpp) | Medium |
 95  | [Unique Binary Search Trees II](src/UniqueBinarySearchTreesII.cpp) | Medium |
 96  | [Unique Binary Search Trees](src/UniqueBinarySearchTrees.cpp) | Medium |
 98  | [Validate Binary Search Tree](src/ValidateBinarySearchTree.cpp) | Medium |
 99  | [Recover Binary Search Tree](src/RecoverBinarySearchTree.cpp) | Hard |
 100 | [Same Tree](src/SameTree.cpp) | Easy |
 101 | [Symmetric Tree](src/SymmetricTree.cpp) | Easy |
 102 | [Binary Tree Level Order Traversal](src/BinaryTreeLevelOrderTraversal.cpp) | Easy |
 103 | [Binary Tree Zigzag Level Order Traversal](src/BinaryTreeZigzagLevelOrderTraversal.cpp) | Medium |
 104 | [Maximum Depth of Binary Tree](src/MaximumDepthOfBinaryTree.cpp) | Easy |
 105 | [Construct Binary Tree from Preorder and Inorder Traversal](src/ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp) | Medium |
 106 | [Construct Binary Tree from Inorder and Postorder Traversal](src/ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp) | Medium |
 107 | [Binary Tree Level Order Traversal II](src/BinaryTreeLevelOrderTraversalII.cpp) | Easy |
 108 | [Convert Sorted Array to Binary Search Tree](src/ConvertSortedArrayToBinarySearchTree.cpp) | Medium |
 110 | [Balanced Binary Tree](src/BalancedBinaryTree.cpp) | Easy |
 111 | [Minimum Depth of Binary Tree](src/MinimumDepthOfBinaryTree.cpp) | Easy |
