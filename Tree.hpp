// mail:elnatan100@gmail.com
#ifndef Tree_HPP
#define Tree_HPP
#include "Node.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <queue>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <type_traits>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;
const float NODE_RADIUS = 61.0f;
/**
 * TREE CLASS
 * A generic tree class template. By default, it represents a binary tree.
 * T = The type of the values stored in the tree nodes.
 * K = The maximum number of children per node (default is 2 for binary tree).
 */

template <typename T, int K = 2>
class Tree
{
private:
    Node<T> *root; // The root node of the tree.
    bool is_binary_tree;
    std::vector<Node<T> *> pre_order_nodes;  // Nodes in pre-order traversal.
    std::vector<Node<T> *> post_order_nodes; // Nodes in post-order traversal.
    std::vector<Node<T> *> in_order_nodes;   // Nodes in in-order traversal.
    std::vector<Node<T> *> bfs_nodes;        // Nodes in breadth-first traversal.
    std::vector<Node<T> *> dfs_nodes;        // Nodes in depth-first traversal.
    std::vector<Node<T> *> heap_nodes;       // Nodes sorted in heap order.

    /**
     * @brief Helper function to recursively delete nodes in the tree.
     * @param node The current node to delete.
     *
     * This function recursively deletes all children of a node and then deletes the node itself.
     */
    void delete_tree(Node<T> *node)
    {
        if (node == nullptr)
        {
            return; // Base case: if the node is null, do nothing.
        }

        // Recursively delete all children of this node.
        for (Node<T> *child : node->children)
        {
            delete_tree(child);
        }

        // Delete the current node.
        delete node;
    }

    Node<T> *find_node(Node<T> *node, const T &value)
    {
        if (node == nullptr)
            return nullptr;
        if (node->get_value() == value)
            return node; // Return the node if the value matches
        for (auto child : node->get_children())
        {
            Node<T> *found = find_node(child, value); // Recursively search each child
            if (found != nullptr)
                return found;
        }
        return nullptr; // Return nullptr if the value is not found
    }

public:
    /**
     * Default constructor
     * Initializes the tree as a binary tree (K=2 by default).
     */
    Tree() : root(nullptr), is_binary_tree(K == 2) {}
    /**
     * Destructor
     */
    ~Tree()
    {
        delete_tree(root);
    }
    /**
     * @brief Helper function to recursively delete nodes in the tree.
     * @param node The current node to delete.
     *
     * This function recursively deletes all children of a node and then deletes the node itself.
     */

    /**
     * Add a root node to the tree.
     **/
    void add_root(const Node<T> &node)
    {
        try
        {
            if (root != nullptr)
            {
                throw runtime_error("Root node already exists.");
            }
            root = new Node<T>(node.get_value());
        }
        catch (const invalid_argument &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void add_sub_node(const Node<T> &parent, const Node<T> &child)
    {
        try
        {
            if (root == nullptr)
            {
                // Throw an exception if parent is null
                throw std::invalid_argument("tree is empty, add root first");
            }
            Node<T> *parent_ptr = find_node(root, parent.get_value());

            // check if the parent in the tree
            if (parent_ptr == nullptr)
            {
                throw std::invalid_argument("the parent not it the tree");
            }

            // Check if the parent node has reached the maximum number of children
            if (parent_ptr->get_num_childern() >= K)
            {
                // Throw an exception if the maximum number of children is exceeded
                throw std::invalid_argument("Cannot add more children to this node");
            }

            // Add the child node to the parent node's list of children
            parent_ptr->add_child(child);
        }
        catch (const std::invalid_argument &e)
        {
            // Handle the specific exception type (invalid_argument)
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    /**
     * Get the root node of the tree.
     */
    Node<T> *getRoot() const
    {
        return root;
    }
    /**
     * Draw the tree to an SFML window.
     * @param window The SFML window to draw on.
     */

    // cout operator
    friend std::ostream &operator<<(std::ostream &os, Tree<T, K> &tree)
    {
        Node<T> *root = tree.getRoot();

        if (root == nullptr)
        {
            os << "Error: Tree is empty." << std::endl;
            return os;
        }
        os << "Generate GUI..." << std::endl;

        sf::Font font;
        if (!font.loadFromFile("ALBAS.TTF"))
        {
            std::cerr << "Failed to load font file " << std::endl;
            return os;
        }
        sf::RenderWindow window(sf::VideoMode(800, 800), "**********MY_TREE**********");
        window.setVerticalSyncEnabled(true); // Attempt to enable vertical sync

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::Black);
            tree.drawTree(window, font);
            window.display();
        }
        return os;
    }

    void drawTree(sf::RenderWindow &window, sf::Font &font)
    {
        if (this->root == nullptr)
            return;

        // Create a map to store positions of each node
        std::map<Node<T> *, sf::Vector2f> positions;
        float start_x = window.getSize().x / 2;
        float start_y = NODE_RADIUS * 2;
        float horizontal_spacing = window.getSize().x / 2.5; // Increased horizontal spacing
        calculate_positions(this->root, positions, start_x, start_y, horizontal_spacing);

        for (auto &entry : positions)
        {
            draw_node(window, entry.first, entry.second, font, positions);
        }
    }

    void calculate_positions(Node<T> *node, std::map<Node<T> *, sf::Vector2f> &positions, float x, float y, float horizontal_spacing)
    {
        if (node == nullptr)
            return;

        positions[node] = sf::Vector2f(x, y);
        float child_x = x - ((node->get_children().size() - 1) * horizontal_spacing / 2);
        float child_y = y + NODE_RADIUS * 3; // Increased vertical spacing

        for (auto child : node->get_children())
        {
            calculate_positions(child, positions, child_x, child_y, horizontal_spacing / 2);
            child_x += horizontal_spacing;
        }
    }

    void draw_node(sf::RenderWindow &window, Node<T> *node, sf::Vector2f position, sf::Font &font, const std::map<Node<T> *, sf::Vector2f> &positions)
    {
        sf::CircleShape circle(NODE_RADIUS);
        circle.setFillColor(sf::Color::Green);
        circle.setOrigin(NODE_RADIUS, NODE_RADIUS);
        circle.setPosition(position);

        sf::Text text;
        text.setFont(font);
        if constexpr (std::is_same<T, std::string>::value)
        {
            text.setString(node->get_value());
        }
        else
        {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1) << node->get_value();
            text.setString(oss.str());
        }
        text.setCharacterSize(25);
        text.setFillColor(sf::Color::Black);
        text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
        text.setPosition(position);

        window.draw(circle);
        window.draw(text);

        for (auto child : node->get_children())
        {
            sf::Vertex line[] = {
                sf::Vertex(position),
                sf::Vertex(positions.at(child))};
            window.draw(line, 2, sf::Lines);
        }
    }
};

#endif // Tree_HPP