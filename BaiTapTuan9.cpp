// Bai 1
#include <iostream>
using namespace std;
struct Node {
    string name;      
    int size;        
    string date;     
    Node* next;      
};
struct List {
    Node* firstNode;  
};
void ListInit(List* list) {
    list->firstNode = NULL; 
}
int Date(const string& date1, const string& date2) {
    for (int i = 0; i < 10; ++i) {
        if (date1[i] > date2[i]) return 1; 
        if (date1[i] < date2[i]) return -1; 
    }
    return 0; 
}
Node* TaoNode(const string& name, int size, const string& date) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->size = size;
    newNode->date = date;
    newNode->next = NULL;
    return newNode;
}
void ListInsert(List* list, Node* newNode) {
    if (list->firstNode == NULL || Date(newNode->date, list->firstNode->date) > 0) {
        newNode->next = list->firstNode;
        list->firstNode = newNode;
        return;
    }
    Node* p = list->firstNode;
    while (p->next != NULL && Date(newNode->date, p->next->date) <= 0) {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
}
void ListDisplay(List* list) {
    Node* p = list->firstNode;
    while (p != NULL) {
        cout << "Ten file: " << p->name
            << ", Kich thuoc: " << p->size << " MB"
            << ", Ngay tao: " << p->date << endl;
        p = p->next;
    }
}

int ListSize(List* list) {
    int TSize = 0; 
    Node* p = list->firstNode;
    while (p != NULL) {
        TSize += p->size;
        p = p->next;
    }
    return TSize;
}
void XoaFile(List* list, int maxSize) {
    while (ListSize(list) > maxSize) {
        Node* P = NULL;
        Node* minFile = list->firstNode;
        Node* K = list->firstNode;
        Node* p = NULL;
        while (K != NULL) {
            if (K->size < minFile->size) {
                minFile = K;
                P = p;
            }
            p = K;
            K = K->next;
        }
        if (P == NULL) {
            list->firstNode = minFile->next;
        }
        else {
            P->next = minFile->next;
        }
        delete minFile;
    }
}
void ListFree(List* list) {
    Node* p = list->firstNode;
    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        delete temp;
    }
    list->firstNode = NULL;
}
int main() {
    List fileList;
    ListInit(&fileList);
    int N;
    cout << "Nhap so luong file: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        string name, date;
        int size;
        cout << "Nhap ten file " << i + 1 << ": ";
        cin >> name;
        cout << "Nhap kich thuoc file (MB): ";
        cin >> size;
        cout << "Nhap ngay tao: ";
        cin >> date;
        ListInsert(&fileList, TaoNode(name, size, date));
    }
    cout << "\nDanh sach file truoc khi sao luu:" << endl;
    ListDisplay(&fileList);
    int maxSize = 32 * 1024;
    XoaFile(&fileList, maxSize);
    cout << "\nDanh sach file sau khi sao luu vao USB:" << endl;
    ListDisplay(&fileList);
    ListFree(&fileList);
    return 0;
}

// Bai 2
#include <iostream>
using namespace std;

struct Node {
    char word[100];
    int count;
    Node* next;
};

struct List {
    Node* firstNode;
};

void ListInit(List* list) {
    list->firstNode = NULL;
}

void addWord(List* list, const char* word) {
    Node* temp = list->firstNode;
    while (temp != NULL) {
        int i = 0;
        while (word[i] == temp->word[i] && word[i] != '\0' && temp->word[i] != '\0')
            i++;
        if (word[i] == '\0' && temp->word[i] == '\0') {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = new Node;
    int i = 0;
    while ((newNode->word[i] = word[i]) != '\0') i++;
    newNode->count = 1;
    newNode->next = list->firstNode;
    list->firstNode = newNode;
}
bool Kiemtra(const char* word) {
    int len = 0;
    while (word[len] != '\0') len++;
    if (len % 2 != 0) return false;
    int half = len / 2;
    for (int i = 0; i < half; i++) {
        if (word[i] != word[i + half]) return false;
    }
    return true;
}
void Xoatu(List* list) {
    Node* temp = list->firstNode;
    while (temp != NULL) {
        if (Kiemtra(temp->word)) {
            temp->count = 1;
        }
        temp = temp->next;
    }
}
void TimTuXuatHienNhieuNhat(List* list) {
    int maxCount = 0;
    Node* temp = list->firstNode;
    while (temp != NULL) {
        if (temp->count > maxCount) {
            maxCount = temp->count;
        }
        temp = temp->next;
    }
    cout << "Cac tu xuat hien nhieu nhat (" << maxCount << " lan): ";
    temp = list->firstNode;
    while (temp != NULL) {
        if (temp->count == maxCount) {
            cout << temp->word << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}
void Caumoi(List* list) {
    Node* temp = list->firstNode;
    cout << "Cau sau khi loai bo tu lay: ";
    while (temp != NULL) {
        if (temp->count > 0) {
            cout << temp->word << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}
void Solan(List* list) {
    Node* temp = list->firstNode;
    while (temp != NULL) {
        if (temp->count > 0) {
            cout << temp->word << ": " << temp->count << " lan" << endl;
        }
        temp = temp->next;
    }
}
int main() {
    List list;
    ListInit(&list);
    char input[] = "Lua nep la lua nep lang lua len lop lop nong nan nang nang";
    char* word = input;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            input[i] = '\0';
            addWord(&list, word);
            word = input + i + 1;
        }
    }
    addWord(&list, word);
    Xoatu(&list);
    cout << "So lan xuat hien cac tu:" << endl;
    Solan(&list);
    TimTuXuatHienNhieuNhat(&list);
    Caumoi(&list);

    return 0;
}
