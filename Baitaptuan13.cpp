#include <iostream>
using namespace std;

void Coppy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int Sosanh(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

int Dodai(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

double Nhapso() {
    char ch;
    double num = 0, factor = 1;
    bool decimalPoint = false;

    while (true) {
        ch = getchar();
        if (ch == '\n' || ch == ' ') break;

        if (ch == '.') {
            decimalPoint = true;
        }
        else {
            if (decimalPoint) {
                factor /= 10;
                num += (ch - '0') * factor;
            }
            else {
                num = num * 10 + (ch - '0');
            }
        }
    }
    return num;
}

struct Sanpham {
    char name[50];
    double price;
    int quantity;

    Sanpham() : price(0), quantity(0) {
        name[0] = '\0';
    }

    Sanpham(const char* n, double p, int q) {
        Coppy(name, n);
        price = p;
        quantity = q;
    }
};

struct GioHang {
    Sanpham items[50];
    int itemCount;
    double total;

    GioHang() : itemCount(0), total(0) {}

    void addGiohang(const char* name, double price, int quantity) {
        if (itemCount < 50) {
            items[itemCount] = Sanpham(name, price, quantity);
            itemCount++;
            total += price * quantity;
        }
    }

    double Tinhtien() {
        return total;
    }
};

struct Queue {
    struct Node {
        GioHang cart;
        Node* next;
        Node(GioHang c) : cart(c), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;
    const int MAX_SIZE = 50;

    Queue() : front(nullptr), rear(nullptr), size(0) {}


    void isEmpty() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
        }
    }


    void isFull() {
        if (size == MAX_SIZE) {
            cout << "Queue is full. Cannot add more customers." << endl;
        }
    }

    void enqueue(const GioHang& cart) {
        isFull(); 
        Node* newNode = new Node(cart);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        isEmpty();  
        if (front == nullptr) {
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (front == nullptr) rear = nullptr;
    }

    double getTotalAmount() {
        double total = 0;
        Node* current = front;
        while (current != nullptr) {
            total += current->cart.Tinhtien();
            current = current->next;
        }
        return total;
    }

    int getProductSold(const char* productName) {
        int totalSold = 0;
        Node* current = front;
        while (current != nullptr) {
            for (int i = 0; i < current->cart.itemCount; i++) {
                if (Sosanh(current->cart.items[i].name, productName) == 0) {
                    totalSold += current->cart.items[i].quantity;
                }
            }
            current = current->next;
        }
        return totalSold;
    }
};

void myGetline(char* str, int maxLen) {
    int i = 0;
    char ch;
    while (i < maxLen - 1) {
        ch = getchar();
        if (ch == '\n') break;
        str[i++] = ch;
    }
    str[i] = '\0';
}

GioHang createCart() {
    GioHang cart;
    char productName[50];
    double price;
    int quantity;
    while (true) {
        cout << "Nhap ten san pham(End de ket thuc phien): ";
        myGetline(productName, sizeof(productName));
        if (Sosanh(productName, "End") == 0) break;
        cout << "So luong san pham: ";
        quantity = Nhapso();
        cout << "Gia san pham: ";
        price = Nhapso();
        cart.addGiohang(productName, price, quantity);
    }
    return cart;
}

int main() {
    Queue queue;
    char productToCount[50];
    GioHang cart;
    char continueShopping[10] = "yes";

    while (true) {
        cout << "Nhap thong tin cho khach hang:" << endl;
        cart = createCart();
        queue.enqueue(cart);
        cout << "Tong tien cua gio hang nay: " << cart.Tinhtien() << " VND" << endl;
        cout << "Khach tiep theo(yes/no): ";
        myGetline(continueShopping, sizeof(continueShopping));
        if (Sosanh(continueShopping, "no") == 0) break;
    }

    cout << "Tong tien thu duoc sau 1 phien: " << queue.getTotalAmount() << " VND" << endl;
    cout << "San pham muon kiem tra so luong ban ra: ";
    myGetline(productToCount, sizeof(productToCount));
    cout << "So luong " << productToCount << " ban duoc la: " << queue.getProductSold(productToCount) << endl;

    return 0;
}
