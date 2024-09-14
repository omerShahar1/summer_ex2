//omer shahar
//207689621
//omerzshahar@gmail.com

#include "node.hpp"
#include "tree.hpp"
#include "Complex.hpp"  // Include the Complex class
#include <iostream>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <sstream>

// Template TreeWidget class to handle both Complex and Double trees
class TreeWidget : public QWidget {
public:
    template<typename T>
    TreeWidget(Tree<T>& tree, const QString& title) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        std::stringstream ss;

        // Pre-order traversal
        ss << "Pre-order traversal:\n";
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            ss << (*node)->get_value() << "\n";
        }

        // Post-order traversal
        ss << "\nPost-order traversal:\n";
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            ss << (*node)->get_value() << "\n";
        }

        // BFS traversal
        ss << "\nBFS traversal:\n";
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
            ss << (*node)->get_value() << "\n";
        }

        // DFS traversal
        ss << "\nDFS traversal:\n";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
            ss << (*node)->get_value() << "\n";
        }

        QLabel *label = new QLabel(QString::fromStdString(ss.str()));
        layout->addWidget(label);
        setWindowTitle(title);
        setLayout(layout);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create Complex number tree
    Complex root_complex(1.1, 2.2);
    Tree<Complex> tree_complex;
    tree_complex.add_root(root_complex);

    Complex n1_complex(3.3, 4.4);
    Complex n2_complex(5.5, 6.6);
    Complex n3_complex(7.7, 8.8);
    Complex n4_complex(9.9, 10.1);
    Complex n5_complex(11.11, 12.12);

    tree_complex.add_sub_node(root_complex, n1_complex);
    tree_complex.add_sub_node(root_complex, n2_complex);
    tree_complex.add_sub_node(n1_complex, n3_complex);
    tree_complex.add_sub_node(n1_complex, n4_complex);
    tree_complex.add_sub_node(n2_complex, n5_complex);

    // Create and show the GUI for the Complex tree
    TreeWidget complexWidget(tree_complex, "Complex Number Tree - All Traversals");
    complexWidget.show();

    // Create Double number tree
    double root_double = 1.1;
    Tree<double> tree_double;
    tree_double.add_root(root_double);

    double n1_double = 3.3;
    double n2_double = 5.5;
    double n3_double = 7.7;
    double n4_double = 9.9;
    double n5_double = 11.11;

    tree_double.add_sub_node(root_double, n1_double);
    tree_double.add_sub_node(root_double, n2_double);
    tree_double.add_sub_node(n1_double, n3_double);
    tree_double.add_sub_node(n1_double, n4_double);
    tree_double.add_sub_node(n2_double, n5_double);

    // Create and show the GUI for the Double tree
    TreeWidget doubleWidget(tree_double, "Double Number Tree - All Traversals");
    doubleWidget.show();

    return app.exec();
}
