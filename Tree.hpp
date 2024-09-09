// mail:elnatan100@gmail.com
#ifndef Tree_HPP
#define Tree_HPP
#include "Node.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <queue>
#include <stack>
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
    vector<Node<T> *> pre_order_nodes;  // Nodes in pre-order traversal.
    vector<Node<T> *> post_order_nodes; // Nodes in post-order traversal.
    vector<Node<T> *> in_order_nodes;   // Nodes in in-order traversal.
    vector<Node<T> *> bfs_nodes;        // Nodes in breadth-first traversal.
    vector<Node<T> *> dfs_nodes;        // Nodes in depth-first traversal.
    vector<Node<T> *> heap_nodes;       // Nodes sorted in heap order.

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

    typename vector<Node<T> *>::iterator begin_bfs_scan()
    {
        bfs_nodes.clear(); // Clear previous results

        if (root == nullptr)
        {
            return bfs_nodes.end(); // Return end iterator if root is null
        }

        queue<const Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            const Node<T> *current = q.front(); // Get the front node
            q.pop();                            // Remove the front node

            // Add the current node to the result vector
            bfs_nodes.push_back(const_cast<Node<T> *>(current));

            // Push all children of the current node into the queue
            for (const auto &child : current->get_children())
            {
                q.push(child); // Assuming get_children() returns a collection of Node<T>* pointers
            }
        }

        return bfs_nodes.begin(); // Return iterator to the first element
    }

    typename vector<Node<T> *>::iterator end_bfs_scan()
    {
        bfs_nodes.clear(); // Clear previous results

        if (root == nullptr)
        {
            return bfs_nodes.end(); // Return end iterator if root is null
        }

        queue<const Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            const Node<T> *current = q.front(); // Get the front node
            q.pop();                            // Remove the front node

            // Add the current node to the result vector
            bfs_nodes.push_back(const_cast<Node<T> *>(current));

            // Push all children of the current node into the queue
            for (const auto &child : current->get_children())
            {
                q.push(child); // Assuming get_children() returns a collection of Node<T>* pointers
            }
        }

        return bfs_nodes.end(); // Return iterator to the first element
    }

    typename vector<Node<T> *>::iterator begin_dfs_scan()
    {
        dfs_nodes.clear(); // Clear previous results

        if (root == nullptr)
        {
            return dfs_nodes.end(); // Return end iterator if root is null
        }

        stack<const Node<T> *> s;
        s.push(root);

        while (!s.empty())
        {
            const Node<T> *current = s.top(); // Get the top node (LIFO)
            s.pop();                          // Remove the top node

            // Add the current node to the result vector
            dfs_nodes.push_back(const_cast<Node<T> *>(current));

            // Push all children of the current node into the stack
            // Reverse the order of children if you want to maintain left-to-right traversal
            const auto &children = current->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it)
            {
                s.push(*it); // Assuming get_children() returns Node<T>* pointers
            }
        }

        return dfs_nodes.begin(); // Return iterator to the first element
    }

    typename vector<Node<T> *>::iterator end_dfs_scan()
    {
        dfs_nodes.clear(); // Clear previous results

        if (root == nullptr)
        {
            return dfs_nodes.end(); // Return end iterator if root is null
        }

        stack<const Node<T> *> s;
        s.push(root);

        while (!s.empty())
        {
            const Node<T> *current = s.top(); // Get the top node (LIFO)
            s.pop();                          // Remove the top node

            // Add the current node to the result vector
            dfs_nodes.push_back(const_cast<Node<T> *>(current));

            // Push all children of the current node into the stack
            // Reverse the order of children if you want to maintain left-to-right traversal
            const auto &children = current->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it)
            {
                s.push(*it); // Assuming get_children() returns Node<T>* pointers
            }
        }

        return dfs_nodes.end(); // Return iterator to the first element
    }

    typename vector<Node<T> *>::iterator begin_pre_order()
    {
        pre_order_nodes.clear();
        if (!is_binary_tree)
        {
            return begin_dfs_scan();
        }
        pre_order_help(root);
        return pre_order_nodes.begin();
    }

    typename vector<Node<T> *>::iterator end_pre_order()
    {
        pre_order_nodes.clear();
        if (!is_binary_tree)
        {
            return end_dfs_scan();
        }
        pre_order_help(root);
        return pre_order_nodes.end();
    }

    void pre_order_help(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        pre_order_nodes.push_back(node);
        for (auto child : node->get_children())
        {
            pre_order_help(child); // Recursively visit each child
        }
    }

    typename vector<Node<T> *>::iterator begin_post_order()
    {
        post_order_nodes.clear();
        if (!is_binary_tree)
        {
            return begin_dfs_scan();
        }
        post_order_help(root);
        return post_order_nodes.begin();
    }

    typename vector<Node<T> *>::iterator end_post_order()
    {
        post_order_nodes.clear();
        if (!is_binary_tree)
        {
            return end_dfs_scan();
        }
        post_order_help(root);
        return post_order_nodes.end();
    }

    void post_order_help(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }

        for (auto child : node->get_children())
        {
            post_order_help(child); // Recursively visit each child
        }
        post_order_nodes.push_back(node);
    }

    void add_sub_node(const Node<T> &parent, const Node<T> &child)
    {
        try
        {
            if (root == nullptr)
            {
                // Throw an exception if parent is null
                throw invalid_argument("tree is empty, add root first");
            }
            Node<T> *parent_ptr = find_node(root, parent.get_value());

            // check if the parent in the tree
            if (parent_ptr == nullptr)
            {
                throw invalid_argument("the parent not it the tree");
            }

            // Check if the parent node has reached the maximum number of children
            if (parent_ptr->get_num_childern() >= K)
            {
                // Throw an exception if the maximum number of children is exceeded
                throw invalid_argument("Cannot add more children to this node");
            }

            // Add the child node to the parent node's list of children
            parent_ptr->add_child(child);
        }
        catch (const invalid_argument &e)
        {
            // Handle the specific exception type (invalid_argument)
            cerr << "Error: " << e.what() << endl;
        }
    }

    typename vector<Node<T> *>::iterator begin_in_order()
    {
        in_order_nodes.clear();
        if (!is_binary_tree)
        {
            return begin_dfs_scan();
        }
        in_order_help(root);
        return in_order_nodes.begin();
    }

    typename vector<Node<T> *>::iterator end_in_order()
    {
        in_order_nodes.clear();
        if (!is_binary_tree)
        {
            return end_dfs_scan();
        }
        in_order_help(root);
        return in_order_nodes.end();
    }

    void in_order_help(Node<T> *node)
    {
        if (node == nullptr)
        {
            return;
        }
        switch (node->get_children().size())
        {
        case (0):
            in_order_nodes.push_back(node);
            break;
        case (1):
            in_order_help(node->get_children()[0]);
            in_order_nodes.push_back(node);
            break;
        default:
            in_order_help(node->get_children()[0]);
            in_order_nodes.push_back(node);
            in_order_help(node->get_children()[1]);
            break;
        }
    }

    typename vector<Node<T> *>::iterator end_heap()
    {
        heap_nodes.clear();
        myHeap(root);
        return heap_nodes.end();
    }

    typename vector<Node<T> *>::iterator begin_heap()
    {
        heap_nodes.clear();
        myHeap(root);
        return heap_nodes.begin();
    }

    void myHeap(Node<T> *node)
    {
        if (node == nullptr)
            return;
        myHead_helper(); // Use DFS to populate the result vector
        auto comp = [](Node<T> *L, Node<T> *R)
        { return L->get_value() > R->get_value(); };
        make_heap(heap_nodes.begin(), heap_nodes.end(), comp); // Create a heap from the result vector
    }

    typename vector<Node<T> *>::iterator myHead_helper()
    {
        heap_nodes.clear(); // Clear previous results

        if (root == nullptr)
        {
            return heap_nodes.end(); // Return end iterator if root is null
        }

        queue<const Node<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            const Node<T> *current = q.front(); // Get the front node
            q.pop();                            // Remove the front node

            // Add the current node to the result vector
            heap_nodes.push_back(const_cast<Node<T> *>(current));

            // Push all children of the current node into the queue
            for (const auto &child : current->get_children())
            {
                q.push(child); // Assuming get_children() returns a collection of Node<T>* pointers
            }
        }

        return heap_nodes.begin(); // Return iterator to the first element
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
    friend ostream &operator<<(ostream &os, Tree<T, K> &tree)
    {
        Node<T> *root = tree.getRoot();

        if (root == nullptr)
        {
            os << "Error: Tree is empty." << endl;
            return os;
        }
        os << "Generate GUI..." << endl;

        sf::Font font;
        if (!font.loadFromFile("ALBAS.TTF"))
        {
            cerr << "Failed to load font file " << endl;
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
        map<Node<T> *, sf::Vector2f> positions;
        float start_x = window.getSize().x / 2;
        float start_y = NODE_RADIUS * 2;
        float horizontal_spacing = window.getSize().x / 2.5; // Increased horizontal spacing
        calculate_positions(this->root, positions, start_x, start_y, horizontal_spacing);

        for (auto &entry : positions)
        {
            draw_node(window, entry.first, entry.second, font, positions);
        }
    }

    void calculate_positions(Node<T> *node, map<Node<T> *, sf::Vector2f> &positions, float x, float y, float horizontal_spacing)
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

    void draw_node(sf::RenderWindow &window, Node<T> *node, sf::Vector2f position, sf::Font &font, const map<Node<T> *, sf::Vector2f> &positions)
    {
        sf::CircleShape circle(NODE_RADIUS);
        circle.setFillColor(sf::Color::Green);
        circle.setOrigin(NODE_RADIUS, NODE_RADIUS);
        circle.setPosition(position);

        sf::Text text;
        text.setFont(font);
        if constexpr (is_same<T, string>::value)
        {
            text.setString(node->get_value());
        }
        else
        {
            ostringstream oss;
            oss << fixed << setprecision(1) << node->get_value();
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