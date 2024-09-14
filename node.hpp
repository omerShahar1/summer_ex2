//omer shahar
//207689621
//omerzshahar@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template<typename T>
class Node {
public:
    T value;
    std::vector<Node<T>*> children;

    Node(const T &val) : value(val) {}

    T& get_value() { return value; }

    ~Node() {
        for (Node<T>* child : children) {
            delete child;
        }
    }
};

#endif // NODE_HPP
