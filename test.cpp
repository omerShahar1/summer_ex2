//omer shahar
//207689621
//omerzshahar@gmail.com

#include <iostream>
#include <cassert>
#include "Complex.hpp"
#include "node.hpp"
#include "tree.hpp"

// Test the Complex class
void test_complex_class() {
    Complex c1(1.1, 2.2);
    Complex c2(3.3, 4.4);
    Complex c3(1.1, 2.2);

    // Test constructor and getters
    assert(c1.getReal() == 1.1);
    assert(c1.getImag() == 2.2);
    
    // Test equality operator
    assert(c1 == c3);
    assert(!(c1 == c2));

    // Test output operator
    std::cout << "Complex number test: " << c1 << std::endl;
}

// Test the Tree class with Complex numbers
void test_tree_with_complex() {
    Tree<Complex> tree;

    // Test add_root
    Complex root(1.1, 2.2);
    tree.add_root(root);

    // Test adding sub-nodes
    Complex n1(3.3, 4.4);
    Complex n2(5.5, 6.6);
    Complex n3(7.7, 8.8);
    Complex n4(9.9, 10.1);
    Complex n5(11.11, 12.12);

    tree.add_sub_node(root, n1);
    tree.add_sub_node(root, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // Test pre-order traversal
    std::vector<Complex> pre_order_values;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        pre_order_values.push_back((*it)->get_value());
    }
    assert(pre_order_values.size() == 6);
    assert(pre_order_values[0] == root);
    assert(pre_order_values[1] == n1);
    assert(pre_order_values[2] == n3);
    assert(pre_order_values[3] == n4);
    assert(pre_order_values[4] == n2);
    assert(pre_order_values[5] == n5);

    // Test post-order traversal
    std::vector<Complex> post_order_values;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        post_order_values.push_back((*it)->get_value());
    }
    std::cout << "Post-order traversal:" << std::endl;
    for(auto &c : post_order_values){
        std::cout << c << std::endl;
    }
    assert(post_order_values.size() == 6);
    assert(post_order_values[0] == n3); // First child of n1
    assert(post_order_values[1] == n4); // Second child of n1
    assert(post_order_values[2] == n1); // Then n1 itself
    assert(post_order_values[3] == n5); // Child of n2
    assert(post_order_values[4] == n2); // Then n2 itself
    assert(post_order_values[5] == root); // Finally root

    // Test BFS traversal
    std::vector<Complex> bfs_values;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        bfs_values.push_back((*it)->get_value());
    }
    assert(bfs_values.size() == 6);
    assert(bfs_values[0] == root);
    assert(bfs_values[1] == n1);
    assert(bfs_values[2] == n2);
    assert(bfs_values[3] == n3);
    assert(bfs_values[4] == n4);
    assert(bfs_values[5] == n5);

    std::cout << "Tree class test with Complex numbers passed." << std::endl;
}

// Test the Tree class with regular numbers (doubles)
void test_tree_with_double() {
    Tree<double> tree;

    // Test add_root
    double root = 1.1;
    tree.add_root(root);

    // Test adding sub-nodes
    double n1 = 3.3;
    double n2 = 5.5;
    double n3 = 7.7;
    double n4 = 9.9;
    double n5 = 11.11;

    tree.add_sub_node(root, n1);
    tree.add_sub_node(root, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // Test pre-order traversal
    std::vector<double> pre_order_values;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        pre_order_values.push_back((*it)->get_value());
    }
    assert(pre_order_values.size() == 6);
    assert(pre_order_values[0] == root);
    assert(pre_order_values[1] == n1);
    assert(pre_order_values[2] == n3);
    assert(pre_order_values[3] == n4);
    assert(pre_order_values[4] == n2);
    assert(pre_order_values[5] == n5);

    // Test post-order traversal
    std::vector<double> post_order_values;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        post_order_values.push_back((*it)->get_value());
    }
    std::cout << "Post-order traversal (double):" << std::endl;
    for(auto val : post_order_values){
        std::cout << val << std::endl;
    }
    assert(post_order_values.size() == 6);
    assert(post_order_values[0] == n3);
    assert(post_order_values[1] == n4);
    assert(post_order_values[2] == n1);
    assert(post_order_values[3] == n5);
    assert(post_order_values[4] == n2);
    assert(post_order_values[5] == root);

    // Test BFS traversal
    std::vector<double> bfs_values;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        bfs_values.push_back((*it)->get_value());
    }
    assert(bfs_values.size() == 6);
    assert(bfs_values[0] == root);
    assert(bfs_values[1] == n1);
    assert(bfs_values[2] == n2);
    assert(bfs_values[3] == n3);
    assert(bfs_values[4] == n4);
    assert(bfs_values[5] == n5);

    std::cout << "Tree class test with double numbers passed." << std::endl;
}

int main() {
    try {
        // Run all tests
        test_complex_class();
        test_tree_with_complex();
        test_tree_with_double();
        std::cout << "All tests passed successfully!" << std::endl;
    }
    catch(const std::exception &e){
        std::cerr << "Test failed: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch(...){
        std::cerr << "Unknown error occurred during tests." << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}
