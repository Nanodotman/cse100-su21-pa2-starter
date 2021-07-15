/**
 * TODO: File Header
 *
 * Author:
 */
#include "DictionaryTrie.hpp"
#include <algorithm>
#include <iostream>

/* TODO */
DictionaryTrie::DictionaryTrie() {
    root = NULL;
}

/* TODO */
void DictionaryTrie::traverse(Node* curr, vector<pair<int, string> >& v, string str) {

    if (curr == NULL) {
        return;
    }

    traverse(curr->right, v, str);

    traverse(curr->left, v, str);

    str += curr->label;

    if (curr->is_word) {
        v.push_back(make_pair(curr->frequency, str));
    }

    traverse(curr->mid, v, str);

}

/* TODO */
bool DictionaryTrie::insert(string word, unsigned int freq) {
    unsigned int i = 0;
    Node* curr = this->root;
    // insert root if inexistent
    if (this->root == NULL) {
        for (char& c : word) {
            if (this->root == NULL) {
                Node* newNode = new Node(c);
                this->root = newNode;
                curr = this->root;
                continue;
            }

            Node* newNode = new Node(c);
            curr->mid = newNode;
            curr = curr->mid;
        }
        curr->frequency = freq;
        curr->is_word = true;
    }
    else {
        while (true) {
            //word duplicate
            if (i == word.size() - 1) {
                if (curr->is_word == true) {
                    break;
                }
            }

            // left child
            if (word[i] < curr->label) {
                if (curr->left != NULL) {
                    curr = curr->left;
                }
                else {
                    Node* newNode = new Node(word[i]);
                    curr->left = newNode;
                    curr = curr->left;
                    if (i == word.size() - 1) {
                        curr->is_word = true;
                        curr->frequency = freq;
                        return true;
                    }
                    // insert the rest of the word
                    for (size_t j = i + 1; j < word.size(); j++) {
                        Node* newNode = new Node(word[j]);
                        curr->mid = newNode;
                        curr = curr->mid;
                        if (j == word.size() - 1) {
                            curr->is_word = true;
                            curr->frequency = freq;
                            return true;
                        }
                    }
                }
            }
            // right child
            else if (word[i] > curr->label) {
                if (curr->right != NULL) {
                    curr = curr->right;
                }
                else {
                    Node* newNode = new Node(word[i]);
                    curr->right = newNode;
                    curr = curr->right;
                    if (i == word.size() - 1) {
                        curr->is_word = true;
                        curr->frequency = freq;
                        return true;
                    }
                    // insert the rest of the word
                    for (size_t j = i + 1; j < word.size(); j++) {
                        Node* newNode = new Node(word[j]);
                        curr->mid = newNode;
                        curr = curr->mid;
                        if (j == word.size() - 1) {
                            curr->is_word = true;
                            curr->frequency = freq;
                            return true;
                        }
                    }
                }
            }
            // middle child
            else {
                if (curr->mid != NULL) {
                    curr = curr->mid;
                    i++;
                }
                else {
                    // insert the rest of the word
                    for (size_t j = i + 1; j < word.size(); j++) {
                        Node* newNode = new Node(word[j]);
                        curr->mid = newNode;
                        curr = curr->mid;
                        if (j == word.size() - 1) {
                            curr->is_word = true;
                            curr->frequency = freq;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }      
            /*
            // left child
            if (c < curr->label) {
                if (curr->left != NULL) {
                    curr = curr->left;
                }
                else {
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
        }
    }
    




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
                if (curr->is_word){
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
    */
}

/* TODO */
bool DictionaryTrie::find(string word) const {
    Node* curr = this->root;
    unsigned int index = 0;
    char letter = word[index];
    while (true)
    {
        if (letter < curr->label){
            if (curr->left != NULL) {
                curr = curr->left;
            } else {
                return false;
            }
        } else if (letter > curr->label) {
            if (curr->right != NULL) {
                curr = curr->right;
            } else {
                return false;
            }
        } else {
            if ((index == word.length() - 1) && (curr->is_word)) {
                return true;
            } else {
                if ((curr->mid != NULL) && (index != word.length() - 1)) {
                    curr = curr->mid;
                    index++;
                    letter = word[index];
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
    vector<pair<int, string> > pairsV;
    vector<string> ret;
    
    Node* curr = this->root;
    unsigned int index = 0;

    while ((curr != NULL) && (index < prefix.length())) {
        // If current character is greater
        if (curr->label > prefix[index]) {
            // Search the right subtree
            curr = curr->left;
        }
        // current character is smaller
        else if (curr->label < prefix[index]) {
            // Search left subtree
            curr = curr->right;
        }
        // If current character is equal
        else if (curr->label == prefix[index]) {
            // Search equal subtree
            if (curr->is_word) {
                pairsV.push_back(make_pair(curr->frequency, prefix));
            }
            curr = curr->mid;
            index++;
        }
        // If not found
        else {
            return ret;
        }
    }
    traverse(curr, pairsV, prefix);

    // sort vector
    std::sort(pairsV.rbegin(), pairsV.rend());

    // Remove elements sp
    if (pairsV.size() > numCompletions) {
        pairsV.resize(numCompletions);
    }
    
    for (pair<int, string> p : pairsV) {
        ret.push_back(p.second);
    }

    return ret;
}

/* TODO */
DictionaryTrie::~DictionaryTrie() {
    delete(root);
}
