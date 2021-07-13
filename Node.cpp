/**
 * Author: Daniel Sosa-Cobo
 */

#include "Node.hpp"

/**
 * The class for creating Nodes
 */
Node::Node(void) {          // initialize instance variables
    is_word = false;
    left = NULL;
    mid = NULL;
    right = NULL;
}

Node::Node(char ch) {       // initialize instance with label
    label = ch;
    is_word = false;
    left = NULL;
    mid = NULL;
    right = NULL;
}

Node::~Node(void) {
	delete(left);
    delete(mid);
    delete(right);
}                           // now that all of my descendants have been destroyed, delete me

