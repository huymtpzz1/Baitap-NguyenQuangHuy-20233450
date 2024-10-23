#include <iostream>
using namespace std;

void nhap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}
void xuat(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void tim(int a[], int n) {
    int k = 1, arr[50] = { 0 }, tam;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                tam = a[i];
                k++;
            }
        }
        if (k != 1) {
            cout << "Co " << k << " nam co " << tam << " nguoi" << endl;
        }
        k = 1;
    }
}
void Sonam(int a[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            cout << (1920 + i) << " ";
        }
    }
    cout << "voi " << value << " nguoi" << endl;
}
void Songuoi(int a[], int n) {
    int max = a[0], min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    cout << "Nam co so nguoi nhieu nhat :" << endl;
    Sonam(a, n, max);
    cout << "Nam co so nguoi it nhat :" << endl;
    Sonam(a, n, min);
}
int main() {
    int a[] = { 19, 77, 40, 90, 2, 25, 54, 17, 79, 6, 44, 24, 14, 4, 95, 47, 66,
                48, 23, 98, 15, 86, 25, 50, 9, 29, 64, 3, 67, 4, 90, 81, 74, 34,
                98, 13, 87, 96, 56, 90, 49, 85, 94, 66, 19, 95, 47, 42, 65, 87, 11 };
    for (int i = 0; i < 51; i++) {
        int nam = 1920 + i;
        cout << "Nam " << nam << " co " << a[i] << " nguoi" << endl;
    }
    cout << endl;
    tim(a, 51);
    cout << endl;
    Songuoi(a, 51);
    return 0;
}

