// mail:elnatan100@gmail.com
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

/**
 * @class Node
 * @brief Represents a generic node in a k-ary tree.
 *
 * The Node class can store a value of any type and can have multiple children.
 * It provides methods to add children, both by value and by existing nodes,
 * and a method to retrieve the stored value. The destructor ensures that all
 * dynamically allocated child nodes are properly deleted.
 *
 * @tparam T Type of the value stored in the node.
 */
template <typename T>
class Node
{

public:
    T value;                      ///< The value stored in the node.
    std::vector<Node *> children; ///< Vector to store pointers to child nodes.

    /**
     * @brief Constructor that initializes the node with a given value.
     * @param val The value to initialize the node with.
     */
    Node(T val) : value(val) {}

    /**
     * @brief Retrieves the value stored in the node.
     * @return The value stored in the node.
     */
    T get_value() const
    {
        return value;
    }

    /**
     * @brief Adds an existing node as a child to this node.
     * @param node The node to add as a child.
     *
     * This method accepts a reference to an existing Node object and adds it
     * to the list of children. It is assumed that the node passed in will
     * be managed elsewhere, and the node will not be deleted in this class's destructor.
     */
    void add_child(const Node<T> &child)
    {
        children.push_back(new Node<T>(child));
    }

    int get_num_childern()
    {
        return children.size();
    }

    /**
     * @brief Destructor that deletes all child nodes to prevent memory leaks.
     *
     * The destructor iterates over all child nodes and deletes them, ensuring
     * that the dynamically allocated memory is properly managed.
     */
    ~Node()
    {
        for (Node *child : children)
        {
            delete child;
        }
    }
    // return  childrens
    std::vector<Node<T> *> get_children() const { return children; }
};

#endif // NODE_HPP
