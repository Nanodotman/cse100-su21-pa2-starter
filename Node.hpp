/**
 * Author: Daniel Sosa-Cobo
 */
#ifndef NODE_HPP
#define NODE_HPP

#include <unordered_map>

using namespace std;

/**
 * The class header for creating Nodes
 */
class Node {
    public:
        bool is_word;       	// Node's "word" label
        unsigned int frequency;	// A count of how many times the word appeared.
        char label;
        Node* left;
        Node* mid;
        Node* right;
        Node(char ch);
		Node();          		// Node constructor
		~Node();         		// Node destructor
};

#endif  // NODE_HPP
