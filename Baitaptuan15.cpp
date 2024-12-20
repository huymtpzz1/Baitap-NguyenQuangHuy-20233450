#include <iostream>
using namespace std;

#define MAX 100
#define MAXLENGTH 100
#define NIL -1

typedef struct Node {
    char title[100]; 
    int pageCount;   
    int childCount;    
    Node* children[MAX]; 
} Node;
void customStrncpy(char* dest, const char* src, int n) {
    int i;
    for (i = 0; i < n - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
Node* createNode(const char* title, int pageCount) {
    Node* newNode = new Node;
    customStrncpy(newNode->title, title, 100);
    newNode->title[99] = '\0'; 
    newNode->pageCount = pageCount;
    newNode->childCount = 0;
    for (int i = 0; i < MAX; i++) {
        newNode->children[i] = nullptr;
    }
    return newNode;
}
void addChild(Node* parent, Node* child) {
    if (parent->childCount < MAX) {
        parent->children[parent->childCount++] = child;
    }
}
bool isEmptyTree(Node* root) {
    return root == nullptr || root->childCount == 0;
}
int countChapters(Node* root) {
    return root->childCount;
}
int calculateTotalPages(Node* node) {
    int total = node->pageCount;
    for (int i = 0; i < node->childCount; i++) {
        total += calculateTotalPages(node->children[i]);
    }
    return total;
}
Node* findLongestChapter(Node* root) {
    Node* longestChapter = nullptr;
    int maxPages = -1;

    for (int i = 0; i < root->childCount; i++) {
        int pages = calculateTotalPages(root->children[i]);
        if (pages > maxPages) {
            maxPages = pages;
            longestChapter = root->children[i];
        }
    }
    return longestChapter;
}
bool deleteNode(Node* parent, const char* titleToDelete) {
    for (int i = 0; i < parent->childCount; i++) {
        if (strncmp(parent->children[i]->title, titleToDelete, 100) == 0) {
            delete parent->children[i];
            for (int j = i; j < parent->childCount - 1; j++) {
                parent->children[j] = parent->children[j + 1];
            }
            parent->childCount--;
            return true;
        }
        else {
            if (deleteNode(parent->children[i], titleToDelete)) {
                return true;
            }
        }
    }
    return false;
}
void printTree(Node* node, int level = 0) {
    for (int i = 0; i < level; i++) cout << "  ";
    cout << "- " << node->title << " (" << node->pageCount << " pages)\n";
    for (int i = 0; i < node->childCount; i++) {
        printTree(node->children[i], level + 1);
    }
}

int main() {
    Node* book = createNode("Book Title", 0);
    Node* chapter1 = createNode("Chapter 1", 10);
    Node* chapter2 = createNode("Chapter 2", 15);
    Node* chapter3 = createNode("Chapter 3", 20);
    addChild(book, chapter1);
    addChild(book, chapter2);
    addChild(book, chapter3);
    Node* section1 = createNode("Section 1.1", 5);
    Node* section2 = createNode("Section 1.2", 7);
    addChild(chapter1, section1);
    addChild(chapter1, section2);
    cout << "Book Structure:\n";
    printTree(book);
    cout << "\nIs the tree empty? " << (isEmptyTree(book) ? "Yes" : "No") << "\n";
    cout << "\nNumber of chapters: " << countChapters(book) << "\n";
    Node* longest = findLongestChapter(book);
    if (longest) {
        cout << "Longest chapter: " << longest->title << "\n";
    }
    const char* titleToDelete = "Section 1.1";
    if (deleteNode(book, titleToDelete)) {
        cout << "\nDeleted: " << titleToDelete << "\n";
    }
    else {
        cout << "\nNot found: " << titleToDelete << "\n";
    }
    cout << "\nUpdated Book Structure:\n";
    printTree(book);
}
