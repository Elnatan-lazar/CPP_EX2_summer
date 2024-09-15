# Tree Project

This project focuses on generic programming, iterators, and the use of the STL library.

## Overview

A tree is a connected graph without cycles. In this project, we implemented a container representing a **k-ary tree** (where each node has at most `k` children). For example, a binary tree is a 2-ary tree. This generic tree can contain keys of any type (numbers, strings, classes). By default, the tree is binary (`k=2`), but the key type and maximum number of children can be specified when creating the container.

## Implemented Iterators

- **Pre-Order Iterator**: Traverses the tree in this order: `current node -> left subtree -> right subtree`.  
  - For binary trees only. In a general tree, performs a standard DFS starting from the root.

- **Post-Order Iterator**: Traverses in this order: `left subtree -> right subtree -> current node`.  
  - For binary trees only. In a general tree, performs a standard DFS starting from the root.

- **In-Order Iterator**: Traverses in the order of `left subtree -> current node -> right subtree`.  
  - For binary trees only. For general trees, it returns a standard DFS traversal starting from the root.

- **BFS Iterator**: Traverses the tree level by level (left to right). Works for general trees.

- **DFS Iterator**: Performs a depth-first search (DFS) traversal on the tree. Works for general trees.

- **Heap Iterator**: Converts a binary tree into a min-heap using the standard algorithm library from the STL.

## `Tree` Class Methods

- **`add_root`**: Adds the root node to the tree.
- **`add_sub_node`**: Adds a child to a specified parent node.
- **`begin_pre_order` / `end_pre_order`**: Returns iterators for traversing the tree in pre-order.
- **`begin_post_order` / `end_post_order`**: Returns iterators for post-order traversal.
- **`begin_in_order` / `end_in_order`**: Returns iterators for in-order traversal.
- **`begin_bfs_scan` / `end_bfs_scan`**: Returns iterators for BFS traversal.
- **`begin_dfs_scan` / `end_dfs_scan`**: Returns iterators for DFS traversal.
- **`myHeap`**: Accepts iterators for a binary tree and returns iterators for the resulting heap.
- **`<< operator`**: Outputs the tree's structure using a GUI, implemented with the SFML library.

## Project Classes

1. **Node Class**: Represents a "node" in the tree, containing generic data and a vector of children. This is a member field within the `Tree` class.

2. **Complex Class**: Represents complex numbers to experiment with non-primitive types in the tree. It includes operator implementations for tree traversal.

3. **Tree Class**: Represents the k-ary tree. Contains all iterator implementations and the output operator.  
   - Each traversal method has a helper function that updates a vector to store nodes in the required order. The iterators then operate over this vector. The `begin` iterator points to the start of the vector, while `end` points to the end (or `null`).

4. **Test Class**: Contains various test cases for edge scenarios, including:
   - Adding a large number of nodes beyond tree boundaries.
   - Adding a child to a non-existent parent.
   - Handling an empty tree, and more.

5. **Supporting Classes**: Additional classes such as `doctest` and `testCounter` assist the `Test` class.

## Usage Commands

- **`make tree`**: Runs the main program, demonstrating different tree types and traversal methods.
- **`./test`**: Executes the test suite for the project.

## Example Output

Below is an example of the tree's structure visualized using the GUI:

![gui](https://github.com/user-attachments/assets/44064000-6fdc-4f5d-996e-265e254971ac)

## Memory leak check
![341111319-16f8fbf0-fce1-4644-b1a6-20b494ac0ebf](https://github.com/user-attachments/assets/90945dbb-6ca0-421c-ba3e-216db1ce116e)


## Dependencies

- [SFML Library](https://www.sfml-dev.org/): For GUI visualization.
- Standard Template Library (STL) for container and algorithm functionalities.

## Getting Started

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/tree-project.git
    ```
2. Build the project:
    ```bash
    make tree
    ```
3. Run the test suite:
    ```bash
    ./test
    ```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

