#include <iostream>
#define MAXLENGTH 100
#define NIL -1
typedef int DataType;
struct Node {
    DataType data;
    Node* left;
    Node* right;
    int height;
};
Node* CreateNode(DataType value) {
    Node* node = new Node;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}
bool IsEmpty(Node* root) {
    return root == nullptr;
}
int Height(Node* node) {
    return node ? node->height : 0;
}
int BalanceFactor(Node* node) {
    return node ? Height(node->left) - Height(node->right) : 0;
}
void UpdateHeight(Node* node) {
    if (node) {
        int leftHeight = Height(node->left);
        int rightHeight = Height(node->right);
        node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}
Node* RotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;
    x->right = y;
    y->left = T;
    UpdateHeight(y);
    UpdateHeight(x);
    return x;
}
Node* RotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;
    y->left = x;
    x->right = T;
    UpdateHeight(x);
    UpdateHeight(y);
    return y;
}
Node* AddNode(Node* root, DataType value) {
    if (!root) return CreateNode(value);
    if (value <= root->data) {
        root->left = AddNode(root->left, value);
    }
    else {
        root->right = AddNode(root->right, value);
    }
    UpdateHeight(root);
    int balance = BalanceFactor(root);
    if (balance > 1 && value < root->left->data) {
        return RotateRight(root);
    }
    if (balance < -1 && value > root->right->data) {
        return RotateLeft(root);
    }
    if (balance > 1 && value > root->left->data) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    if (balance < -1 && value < root->right->data) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }

    return root;
}
void InOrderTraversal(Node* root) {
    if (!root) return;
    InOrderTraversal(root->left);
    std::cout << root->data << " ";
    InOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    int arr[] = { 17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        root = AddNode(root, arr[i]);
    }
    if (IsEmpty(root)) {
        std::cout << "The tree is empty." << std::endl;
    }
    else {
        std::cout << "In-order traversal of AVL tree: ";
        InOrderTraversal(root);
        std::cout << std::endl;
    }
}
