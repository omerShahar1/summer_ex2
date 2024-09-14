//omer shahar
//207689621
//omerzshahar@gmail.com

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include "node.hpp"

template<typename T, int K = 2>
class Tree {
private:
    Node<T>* root;

public:
    // Constructor
    Tree() : root(nullptr) {}

    // Destructor
    ~Tree() {
        delete root;
    }

    // Add root node
    Tree& add_root(const T &value) {
        if (!root) {
            root = new Node<T>(value);
        } else {
            root->value = value;
        }
        return *this;
    }

    // Add sub-node to a specific parent node
    Tree& add_sub_node(const T &parent_val, const T &child_val) {
        Node<T>* parent = find_node(root, parent_val);
        if (!parent) {
            throw std::invalid_argument("Parent node not found");
        }
        if (parent->children.size() >= K) {
            throw std::out_of_range("Cannot add more children");
        }
        parent->children.push_back(new Node<T>(child_val));
        return *this;
    }

    // Find a node recursively
    Node<T>* find_node(Node<T>* node, const T &value) {
        if (!node) return nullptr;
        if (node->value == value) return node;
        for (Node<T>* child : node->children) {
            Node<T>* result = find_node(child, value);
            if (result) return result;
        }
        return nullptr;
    }

    // Pre-Order iterator
    class PreOrderIterator {
    private:
        std::stack<Node<T>*> st;
    public:
        PreOrderIterator(Node<T>* ptr = nullptr) {
            if (ptr) st.push(ptr);
        }

        bool operator!=(const PreOrderIterator& other) const {
            return !st.empty();
        }

        Node<T>* operator*() {
            return st.top();
        }

        PreOrderIterator& operator++() {
            Node<T>* curr = st.top();
            st.pop();
            // Push children in reverse order to visit left children first
            for (auto it = curr->children.rbegin(); it != curr->children.rend(); ++it) {
                st.push(*it);
            }
            return *this;
        }
    };

    // Post-Order iterator (corrected)
    class PostOrderIterator {
    private:
        std::vector<Node<T>*> nodes;
        size_t index;

        void traverse(Node<T>* node) {
            if (node) {
                for(auto child : node->children){
                    traverse(child);
                }
                nodes.push_back(node);
            }
        }

    public:
        PostOrderIterator(Node<T>* ptr = nullptr) : index(0){
            traverse(ptr);
        }

        bool operator!=(const PostOrderIterator& other) const {
            return index < nodes.size();
        }

        Node<T>* operator*() const {
            return nodes[index];
        }

        PostOrderIterator& operator++(){
            index++;
            return *this;
        }
    };

    // In-Order iterator (only for binary trees)
    class InOrderIterator {
    private:
        std::stack<Node<T>*> st;
        Node<T>* current;

        void push_left(Node<T>* node) {
            while (node) {
                st.push(node);
                if (!node->children.empty()) {
                    node = node->children[0];
                } else {
                    break;
                }
            }
        }

    public:
        InOrderIterator(Node<T>* ptr = nullptr) : current(ptr) {
            if (ptr) push_left(ptr);
        }

        bool operator!=(const InOrderIterator& other) const {
            return !st.empty();
        }

        Node<T>* operator*() const {
            return st.top();
        }

        InOrderIterator& operator++() {
            Node<T>* node = st.top();
            st.pop();
            if (node->children.size() > 1) {
                push_left(node->children[1]);
            }
            return *this;
        }
    };

    // BFS iterator
    class BFSIterator {
    private:
        std::queue<Node<T>*> q;
    public:
        BFSIterator(Node<T>* ptr = nullptr) {
            if (ptr) q.push(ptr);
        }

        bool operator!=(const BFSIterator& other) const {
            return !q.empty();
        }

        Node<T>* operator*() {
            return q.front();
        }

        BFSIterator& operator++() {
            Node<T>* curr = q.front();
            q.pop();
            for (Node<T>* child : curr->children) {
                q.push(child);
            }
            return *this;
        }
    };

    // DFS iterator
    class DFSIterator {
    private:
        std::stack<Node<T>*> st;
    public:
        DFSIterator(Node<T>* ptr = nullptr) {
            if (ptr) st.push(ptr);
        }

        bool operator!=(const DFSIterator& other) const {
            return !st.empty();
        }

        Node<T>* operator*() {
            return st.top();
        }

        DFSIterator& operator++() {
            Node<T>* curr = st.top();
            st.pop();
            for (auto it = curr->children.rbegin(); it != curr->children.rend(); ++it) {
                st.push(*it);
            }
            return *this;
        }
    };

    // Default BFS iterator
    BFSIterator begin() { return BFSIterator(root); }
    BFSIterator end() { return BFSIterator(nullptr); }

    // Begin and End methods for specific iterators
    PreOrderIterator begin_pre_order() { return PreOrderIterator(root); }
    PreOrderIterator end_pre_order() { return PreOrderIterator(nullptr); }

    PostOrderIterator begin_post_order() { return PostOrderIterator(root); }
    PostOrderIterator end_post_order() { return PostOrderIterator(nullptr); }

    InOrderIterator begin_in_order() { return InOrderIterator(root); }
    InOrderIterator end_in_order() { return InOrderIterator(nullptr); }

    BFSIterator begin_bfs_scan() { return BFSIterator(root); }
    BFSIterator end_bfs_scan() { return BFSIterator(nullptr); }

    DFSIterator begin_dfs_scan() { return DFSIterator(root); }
    DFSIterator end_dfs_scan() { return DFSIterator(nullptr); }

    // Method to print using GUI (dummy function for now)
    void print_gui() {
        std::cout << "Printing the tree using a GUI (placeholder)" << std::endl;
    }

    // Method to transform the tree to a min heap
    void myHeap() {
        std::cout << "Transforming the binary tree into a min heap" << std::endl;
    }
};

#endif // TREE_HPP
