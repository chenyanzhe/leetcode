Tree
====

94. Binary Tree Inorder Traversal
---------------------------------

Given a binary tree, return the inorder traversal of its nodes' values.

We have following four strategies to solve this problem:

Recursion
~~~~~~~~~

Recursion is easiest, both for understanding and implementation.

.. code-block:: none

   InorderTraversal(root)
      InorderTraversal(root->left)
      visit(root)
      InorderTraversal(root->right)

Iteration
~~~~~~~~~

Iterative way is often asked during interview. It's done with the help of **Stack**.

.. code-block:: none

   1. Keep pushing left child into the stack (if any)
   2. Visit the top element
   3. Push right child into the stack (if any), go back to step 1

The following figure shows an example of how this works. Every node is mark with two *timestamps*,
the first one is the time it is pushed into the stack, the second one is the time it is visited.

.. image:: images/1469348911.jpg
   :width: 200pt
