// mail:elnatan100@gmail.com
#include "doctest.h"
#include "complex.hpp"
#include "Node.hpp"
#include "Tree.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
/**
 * TEST CLASS
 * This class represent a tests cases
 */

TEST_CASE("Binary Tree Operations")
{
    Node<double> root_node(1.1);
    Tree<double> tree;
    tree.add_root(root_node);

    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    SUBCASE("Pre-order Traversal")
    {
        std::vector<double> expected = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        std::vector<double> result;

        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("Post-order Traversal")
    {
        std::vector<double> expected = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
        std::vector<double> result;

        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("In-order Traversal")
    {
        std::vector<double> expected = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
        std::vector<double> result;

        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("BFS Traversal")
    {
        std::vector<double> expected = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        std::vector<double> result;

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("DFS Traversal")
    {
        std::vector<double> expected = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        std::vector<double> result;

        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("Heap Traversal")
    {
        std::vector<double> expected = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        std::vector<double> result;

        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            result.push_back((*node)->get_value());
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Non-Binary Tree Operations")
{
    Node<int> root_node(1);
    Tree<int, 3> tree;
    tree.add_root(root_node);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    SUBCASE("BFS Traversal")
    {
        std::vector<int> expected = {1, 2, 3, 4, 5, 6};
        std::vector<int> result;

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("DFS Traversal")
    {
        std::vector<int> expected = {1, 2, 5, 3, 6, 4};
        std::vector<int> result;

        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }
    // checks that if the tree is not binary- it return dfs iter
    SUBCASE("pre-Order Traversal")
    {
        std::vector<int> expected = {1, 2, 5, 3, 6, 4};
        std::vector<int> result;

        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }
    SUBCASE("in-Order Traversal")
    {
        std::vector<int> expected = {1, 2, 5, 3, 6, 4};
        std::vector<int> result;

        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }
    SUBCASE("post-Order Traversal")
    {
        std::vector<int> expected = {1, 2, 5, 3, 6, 4};
        std::vector<int> result;

        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }
}

TEST_CASE("EXCEPTIONS")
{
    SUBCASE("test add 4 nodes to three ary tree")
    {
        Node<int> root_node(1);
        Tree<int, 3> tree;
        tree.add_root(root_node);

        Node<int> n1(2);
        Node<int> n2(3);
        Node<int> n3(4);
        Node<int> n4(5);

        tree.add_sub_node(root_node, n1);
        tree.add_sub_node(root_node, n2);
        tree.add_sub_node(root_node, n3);
        CHECK_THROWS(tree.add_sub_node(root_node, n4));
    }
    SUBCASE("test add 3 nodes to binary tree-same node")
    {
        Node<double> root_node(1.1);
        Tree<double> tree;
        tree.add_root(root_node);

        Node<double> n1(1.2);
        Node<double> n2(1.3);
        Node<double> n3(1.4);
        Node<double> n4(1.5);
        Node<double> n5(1.6);

        tree.add_sub_node(root_node, n1);
        tree.add_sub_node(root_node, n2);
        CHECK_THROWS(tree.add_sub_node(root_node, n1));
    }
    SUBCASE("test add node to unexsisted node in the tree")
    {
        Node<double> root_node(1.1);
        Tree<double> tree;
        Node<double> n1(1.2);
        Node<double> n2(1.3);
        CHECK_THROWS(tree.add_sub_node(root_node, n1));
        CHECK_THROWS(tree.add_sub_node(n2, n1));
    }
    SUBCASE("test add node to itself")
    {
        Node<double> root_node(1.1);
        Tree<double> tree;
        CHECK_THROWS(tree.add_sub_node(root_node, root_node));
    }
}

TEST_CASE("Complex tree")
{
    Complex c1(1, 2);
    Complex c2(1, 4);
    Complex c3(0.3, 4);
    Complex c4(7, 1.2);
    Complex c5(1, 2.1);
    Complex c6(9, 11);
    Complex c7(12, 1);

    Tree<Complex> tree;
    Node<Complex> complex_root = Node<Complex>(c1);
    Node<Complex> n1 = Node<Complex>(c2);
    Node<Complex> n2 = Node<Complex>(c3);
    Node<Complex> n3 = Node<Complex>(c4);
    Node<Complex> n4 = Node<Complex>(c5);
    Node<Complex> n5 = Node<Complex>(c6);
    Node<Complex> n6 = Node<Complex>(c7);
    tree.add_root(complex_root);
    // Node<Complex> n12 = Node<Complex>(c2);
    tree.add_sub_node(complex_root, n1);
    tree.add_sub_node(complex_root, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.add_sub_node(n2, n6);
    SUBCASE("Pre-order Traversal")
    {
        std::vector<Complex> expected = {c1, c2, c4, c5, c3, c6, c7};
        std::vector<Complex> result;

        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("Post-order Traversal")
    {
        std::vector<Complex> expected = {c4, c5, c2, c6, c7, c3, c1};
        std::vector<Complex> result;
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("In-order Traversal")
    {
        std::vector<Complex> expected = {c4, c2, c5, c1, c6, c3, c7};
        std::vector<Complex> result;

        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("BFS Traversal")
    {
        std::vector<Complex> expected = {c1, c2, c3, c4, c5, c6, c7};
        std::vector<Complex> result;

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("DFS Traversal")
    {
        std::vector<Complex> expected = {c1, c2, c4, c5, c3, c6, c7};
        std::vector<Complex> result;

        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            result.push_back((*node)->get_value());
        }

        CHECK(result == expected);
    }

    SUBCASE("Heap Traversal")
    {
        std::vector<Complex> expected = {c7, c3, c4, c5, c2, c6, c1};
        std::vector<Complex> result;

        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            result.push_back((*node)->get_value());
        }
        CHECK(result == expected);
    }
}
