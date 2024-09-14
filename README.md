# Tree Traversal Program - README

## Overview
This project implements a tree container that supports various types of trees with both `Complex` numbers and regular `double` values. The program provides different tree traversal algorithms including:
- **Pre-Order Traversal**
- **Post-Order Traversal**
- **Breadth-First Search (BFS) Traversal**
- **Depth-First Search (DFS) Traversal**

Two trees are created: one with `Complex` numbers and one with `double` values. Both are displayed in separate GUI windows using the Qt framework.

## Class Hierarchy

### 1. `Tree<T>` (Template Class)
The `Tree` class is a templated container for storing trees of arbitrary types (`T`). It supports various traversal methods and the ability to add nodes dynamically. The `Tree` class makes use of the `Node` class internally to represent the nodes of the tree.

- **Template Parameter**: `T` - The type of data stored in the tree (e.g., `Complex` or `double`).

#### Public Methods:
- **add_root(const T& value)**: Adds a root node with the value `value`.
- **add_sub_node(const T& parent_val, const T& child_val)**: Adds a child node to the node with `parent_val`.
- **begin_pre_order(), end_pre_order()**: Returns iterators to traverse the tree in pre-order (root → left → right).
- **begin_post_order(), end_post_order()**: Returns iterators to traverse the tree in post-order (left → right → root).
- **begin_in_order(), end_in_order()**: Returns iterators to traverse the tree in in-order (only valid for binary trees).
- **begin_bfs_scan(), end_bfs_scan()**: Returns iterators to traverse the tree using BFS (level by level).
- **begin_dfs_scan(), end_dfs_scan()**: Returns iterators to traverse the tree using DFS.

### 2. `Node<T>` (Template Class)
The `Node` class represents a node in the tree. It stores a value of type `T` and a list of child nodes. The `Tree` class manages nodes, and the `Node` class is designed for internal use.

- **Template Parameter**: `T` - The type of data stored in the node (e.g., `Complex` or `double`).

#### Public Members:
- **value**: Stores the data of type `T` in the node.
- **children**: A vector that stores pointers to the child nodes.

#### Public Methods:
- **Node(const T& value)**: Constructor that initializes the node with a given value.
- **get_value() const**: Returns the value stored in the node.

### 3. `Complex` Class
The `Complex` class represents a complex number with real and imaginary parts. It is used as an example of a custom data type in the `Tree` class.

#### Public Members:
- **double real**: The real part of the complex number.
- **double imag**: The imaginary part of the complex number.

#### Public Methods:
- **Complex(double real = 0, double imag = 0)**: Constructor that initializes the complex number with real and imaginary parts.
- **getReal() const**: Returns the real part.
- **getImag() const**: Returns the imaginary part.
- **operator==(const Complex& other) const**: Overloaded equality operator to compare two complex numbers. Uses an epsilon to handle floating-point precision.
- **operator<<**: Overloaded output operator for printing complex numbers in the form `real + imag i`.

### 4. `TreeWidget` (Qt `QWidget` Class)
The `TreeWidget` class is responsible for displaying the traversal results of a tree in a Qt GUI window. It is a templated class that works for both `Complex` and `double` types.

#### Constructor:
- **TreeWidget(Tree<T>& tree, const QString& title)**: Constructs a GUI window that displays the results of all traversals (pre-order, post-order, BFS, and DFS) for the given tree. The title of the window is provided as a string.

## Libraries Used

### 1. Qt Framework:
- **QtCore**: Provides core non-GUI functionality such as string manipulation and basic data structures.
- **QtWidgets**: Provides the GUI components like `QWidget`, `QLabel`, and `QVBoxLayout`.
  
   Install with:
   ```bash
   sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
