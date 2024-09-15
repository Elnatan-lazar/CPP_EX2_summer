// mail:elnatan100@gmail.com
#include "Node.hpp"
#include "Tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <string>
#include "complex.hpp"

using namespace std;

int main()
{
    /**
     * Binary Tree Example:
     **/
    Node<double> primary_node = Node<double>(3.14);
    Tree<double> binary_tree;
    binary_tree.add_root(primary_node);

    Node<double> leaf1 = Node<double>(2.71);
    Node<double> leaf2 = Node<double>(1.41);
    Node<double> leaf3 = Node<double>(1.73);
    Node<double> leaf4 = Node<double>(0.577);
    Node<double> leaf5 = Node<double>(1.618);

    binary_tree.add_sub_node(primary_node, leaf1);
    binary_tree.add_sub_node(primary_node, leaf2);
    binary_tree.add_sub_node(leaf1, leaf3);
    binary_tree.add_sub_node(leaf1, leaf4);
    binary_tree.add_sub_node(leaf2, leaf5);

    // Print tree traversals
    cout << "***** Binary Tree of Doubles *****" << endl;
    cout << "Pre-Order Traversal:" << endl;
    for (auto itr = binary_tree.begin_pre_order(); itr != binary_tree.end_pre_order(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "Post-Order Traversal:" << endl;
    for (auto itr = binary_tree.begin_post_order(); itr != binary_tree.end_post_order(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "In-Order Traversal:" << endl;
    for (auto itr = binary_tree.begin_in_order(); itr != binary_tree.end_in_order(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "BFS Traversal:" << endl;
    for (auto itr = binary_tree.begin_bfs_scan(); itr != binary_tree.end_bfs_scan(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "DFS Traversal:" << endl;
    for (auto itr = binary_tree.begin_dfs_scan(); itr != binary_tree.end_dfs_scan(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "HEAP Traversal:" << endl;
    for (auto itr = binary_tree.begin_heap(); itr != binary_tree.end_heap(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }
    cout << binary_tree << endl;

    /**
     * Example of a Three-Ary Tree:
     */
    Tree<int, 3> ternary_tree;
    Node<int> int_root = Node<int>(10);
    ternary_tree.add_root(int_root);

    Node<int> t_leaf1 = Node<int>(20);
    Node<int> t_leaf2 = Node<int>(30);
    Node<int> t_leaf3 = Node<int>(40);
    Node<int> t_leaf4 = Node<int>(50);
    Node<int> t_leaf5 = Node<int>(60);

    ternary_tree.add_sub_node(int_root, t_leaf1);
    ternary_tree.add_sub_node(int_root, t_leaf2);
    ternary_tree.add_sub_node(int_root, t_leaf3);
    ternary_tree.add_sub_node(t_leaf1, t_leaf4);
    ternary_tree.add_sub_node(t_leaf2, t_leaf5);

    cout << "***** 3-ary Tree of Integers *****" << endl;
    cout << "DFS Traversal:" << endl;
    for (auto itr = ternary_tree.begin_dfs_scan(); itr != ternary_tree.end_dfs_scan(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "BFS Traversal:" << endl;
    for (auto itr = ternary_tree.begin_bfs_scan(); itr != ternary_tree.end_bfs_scan(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }
    cout << ternary_tree << endl;

    /**
     * Binary tree with Complex Numbers:
     */
    Complex complex1(3, 4);
    Complex complex2(-2, 7);
    Complex complex3(1.5, -3.5);
    Complex complex4(0.6, 2.2);
    Complex complex5(-3, 9);
    Complex complex6(5, -1);
    Complex complex7(2, 8);

    Tree<Complex> complex_tree;
    Node<Complex> c_root = Node<Complex>(complex1);
    complex_tree.add_root(c_root);
    complex_tree.add_sub_node(c_root, complex2);
    complex_tree.add_sub_node(c_root, complex3);
    complex_tree.add_sub_node(complex2, complex4);
    complex_tree.add_sub_node(complex2, complex5);
    complex_tree.add_sub_node(complex3, complex6);
    complex_tree.add_sub_node(complex3, complex7);

    cout << "***** Binary Tree of Complex Numbers *****" << endl;
    cout << "Pre-Order Traversal:" << endl;
    for (auto itr = complex_tree.begin_pre_order(); itr != complex_tree.end_pre_order(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "Post-Order Traversal:" << endl;
    for (auto itr = complex_tree.begin_post_order(); itr != complex_tree.end_post_order(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "In-Order Traversal:" << endl;
    for (auto itr = complex_tree.begin_in_order(); itr != complex_tree.end_in_order(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "BFS Traversal:" << endl;
    for (auto itr = complex_tree.begin_bfs_scan(); itr != complex_tree.end_bfs_scan(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "DFS Traversal:" << endl;
    for (auto itr = complex_tree.begin_dfs_scan(); itr != complex_tree.end_dfs_scan(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "HEAP Traversal:" << endl;
    for (auto itr = complex_tree.begin_heap(); itr != complex_tree.end_heap(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << complex_tree << endl;

    /**
     * Example of a "vichele" Tree:
     */
    string vichele = "vichele";
    string car = "car";
    string bus = "bus";
    string plane = "plane";
    string boat = "boat";
    string tank = "tank";
    string motro = "motro";

    Tree<string, 5> vichele_structure;
    Node<string> f_node = Node<string>(car);
    Node<string> s_node = Node<string>(bus);
    Node<string> d_node = Node<string>(plane);
    Node<string> c_node = Node<string>(boat);
    Node<string> r_node = Node<string>(tank);
    Node<string> l_node = Node<string>(motro);
    Node<string> u_root = Node<string>(vichele);
    vichele_structure.add_root(u_root);
    vichele_structure.add_sub_node(u_root, f_node);
    vichele_structure.add_sub_node(f_node, s_node);
    vichele_structure.add_sub_node(s_node, d_node);

    cout << "***** 5-ary Tree of vichele structure*****" << endl;
    cout << "BFS Traversal:" << endl;
    for (auto itr = vichele_structure.begin_bfs_scan(); itr != vichele_structure.end_bfs_scan(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << "DFS Traversal:" << endl;
    for (auto itr = vichele_structure.begin_dfs_scan(); itr != vichele_structure.end_dfs_scan(); ++itr)
    {
        cout << (*itr)->get_value() << endl;
    }

    cout << vichele_structure << endl;

    return 0;
}
