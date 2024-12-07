﻿#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;   
    Node* left;    
    Node* right;  
    Node(string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
bool EmptyTree(Node* root) {
    return root == nullptr;
}

Node* Xaycay() {
    Node* root = new Node("+");
    root->left = new Node("-");
    root->right = new Node("*");
    root->left->left = new Node("*");
    root->left->right = new Node("/");
    root->right->left = new Node("-");
    root->right->right = new Node("^");
    root->left->left->left = new Node("a");
    root->left->left->right = new Node("5");
    root->right->right->left = new Node("e");
    root->right->right->right = new Node("/");
    root->right->left->left = new Node("h");
    root->right->left->right = new Node("f");
    root->left->right->left = new Node("b");
    root->left->right->right = new Node("^");
    root->left->right->right->left = new Node("c");
    root->left->right->right->right = new Node("6");
    root->right->right->right->left = new Node("1");
    root->right->right->right->right = new Node("2");

    return root;
}

void LRN(Node* p) {
    if (p == nullptr) return;
    LRN(p->left);
    LRN(p->right); 
    cout << p->data << " ";  
}

void LNR(Node* p) {
    if (p == nullptr) return;
    LNR(p->left); 
    cout << p->data << " ";  
    LNR(p->right); 
}

void NLR(Node* p) {
    if (p == nullptr) return;
    cout << p->data << " ";
    NLR(p->left);  
    NLR(p->right); 
}

int main() {
    Node* root = Xaycay();  
    cout << "Hau to: ";
    LRN(root);
    cout << endl;
    cout << "Trung to: ";
    LNR(root);
    cout << endl;
    cout << "Tien to: ";
    NLR(root);
    cout << endl;
}

