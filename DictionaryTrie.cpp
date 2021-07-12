/**
 * TODO: File Header
 *
 * Author:
 */
#include "DictionaryTrie.hpp"
#include <iostream>

/* TODO */
DictionaryTrie::DictionaryTrie() {
    root = NULL;
}

/* TODO */
bool DictionaryTrie::insert(string word, unsigned int freq) {
    Node* curr = this->root;
    int index = 0;
    char letter = word[index];
    while (true) {
        // left child
        if (letter < curr->label){
            if (curr->left != NULL) {
                curr = curr->left;
            } else {
                Node* newNode = new Node(word[index]);
                curr->left = newNode;
                curr = curr->left;
                index++;

                for (size_t i = index; i < word.length(); i++)
                {
                    Node* midNode = new Node(word[i]);
                    curr->mid = midNode;
                    curr = curr->mid;
                }

                curr->is_word = true;
                curr->frequency = freq;
                break;
            }
        // right child
        } else if (letter > curr->label) {
             if (curr->right != NULL) {
                curr = curr->right;
            } else {
                Node* newNode = new Node(word[index]);
                curr->right = newNode;
                curr = curr->right;
                index++;

                for (size_t i = index; i < word.length(); i++) {
                    Node* midNode = new Node(word[i]);
                    curr->mid = midNode;
                    curr = curr->mid;
                }

                curr->is_word = true;
                curr->frequency = freq;
                break;
            }
        // middle child
        } else {
            if (index == word.length() - 1) {
                if (curr->is_word == true){
                    break;
                }
                curr->is_word = true;
                curr->frequency = freq;
                return true;
            } else {
                if (curr->mid != NULL) {
                    curr = curr->mid;
                    index++;
                    letter = word[index];
                } else {
                    for (size_t i = index; i < word.length(); i++) {
                        Node* midNode = new Node(word[i]);
                        curr->mid = midNode;
                        curr = curr->mid;
                    }

                    curr->is_word = true;
                    curr->frequency = freq;
                    break;
                }
            } 
        }
    }
    return false;
}

/* TODO */
bool DictionaryTrie::find(string word) const {
    Node* curr = this->root;
    int index = 0;
    char letter = word[index];
    while (true)
    {
        if (letter < curr->label){
            if (curr->left != NULL) {
                curr = curr->left;
                index++;
            } else {
                return false;
            }
        } else if (letter > curr->label) {
            if (curr->right != NULL) {
                curr = curr->right;
                index++;
            } else {
                return false;
            }
        } else {
            if ((index == word.length() - 1) && (curr->is_word == true)) {
                return true;
            } else {
                if ((curr->mid != NULL) && (index != word.length() - 1)) {
                    curr = curr->mid;
                    letter = word[index];
                    index++;
                } else {
                    return false;
                }
            } 
        }
    }
}

/* TODO */
vector<string> DictionaryTrie::predictCompletions(string prefix,
                                                  unsigned int numCompletions) {
    return {};
}

/* TODO */
DictionaryTrie::~DictionaryTrie() {}
