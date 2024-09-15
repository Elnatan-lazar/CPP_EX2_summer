This project focuses on generic programming, iterators, and utilizing the STL library.

A tree is a connected graph without cycles. In this project, I implemented a container representing a k-ary tree (a k-ary tree is one where each node has at most k children. For example, a binary tree is a 2-ary tree). The tree is generic and can contain keys of any type (e.g., numbers, strings, or classes). By default, the tree is binary (meaning k=2). When creating the container, you can specify the key type and the tree's maximum number of children.

the basic class Node conaina a templet of a that conatin value and children. 

The following iterators are implemented in Tree class:

Pre-Order Iterator: Traverses the tree in this order: current node -> left subtree -> right subtree. (This iterator operates in this manner only for binary trees; for a general tree, it returns a standard DFS traversal starting from the root.)

Post-Order Iterator: Traverses the tree in this order: left subtree -> right subtree -> current node. (This iterator also works this way only for binary trees; for general trees, it performs a standard DFS starting from the root.)

In-Order Iterator: Traverses in the order of left subtree -> current node -> right subtree. (This traversal is specific to binary trees; for general trees, it returns a standard DFS traversal beginning at the root.)

BFS Iterator: Traverses the tree level by level (left to right). This iterator works for general trees.

DFS Iterator: Performs a depth-first search (DFS) on the tree. This iterator is suitable for general trees.

Heap Iterator: Converts a binary tree into a min-heap (using the standard algorithm library from the STL).

The Tree class includes the following methods:

add_root: Adds a root to the tree. This method accepts a node of any type and places it as the root of the tree.

add_sub_node: Adds a child to a given parent node. It takes a node within the tree and a new node to create a child for the specified parent.

begin_pre_order, end_pre_order: Return iterators for traversing the tree in pre-order.

begin_post_order, end_post_order: Return iterators for traversing the tree in post-order.

begin_in_order, `end


commands:

Make tree comdand will run the Demo file
Make test will create the test
the exe file are in the project so the command ./Demo or ./test will run them.

Gui
![gui](https://github.com/user-attachments/assets/635c70a1-ab09-4666-af44-c7cf4d11e991)

leak check
![341111319-16f8fbf0-fce1-4644-b1a6-20b494ac0ebf](https://github.com/user-attachments/assets/8282a882-b44d-4425-b1d3-893ef0568786)
