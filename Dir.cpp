#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class FileManager {
private:
    struct Node {
        string name;
        bool isDir;
        Node *left, *right;
        Node(string n, bool d) : name(n), isDir(d), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    Node* insert(Node* node, string name, bool isDir) {
        if (!node) return new Node(name, isDir);
        if (name < node->name) node->left = insert(node->left, name, isDir);
        else if (name > node->name) node->right = insert(node->right, name, isDir);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* remove(Node* node, string name) {
        if (!node) return nullptr;
        if (name < node->name) node->left = remove(node->left, name);
        else if (name > node->name) node->right = remove(node->right, name);
        else {
            if (!node->left) { Node* temp = node->right; delete node; return temp; }
            if (!node->right) { Node* temp = node->left; delete node; return temp; }
            Node* temp = findMin(node->right);
            node->name = temp->name;
            node->isDir = temp->isDir;
            node->right = remove(node->right, temp->name);
        }
        return node;
    }

public:
    void create(string name, bool isDir) { root = insert(root, name, isDir); }
    void del(string name) { root = remove(root, name); }

    // Traversal examples
    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << (node->isDir ? "[DIR] " : "[FILE] ") << node->name << endl;
        inOrder(node->right);
    }
    
    void showAll() { inOrder(root); }
};
