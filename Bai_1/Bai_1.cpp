
#include <iostream>
#include <string>
using namespace std;
void doicho(int& a, int& b) {
	int doi = a;
	a = b;
	b = doi;
}
void sapxep(int a[], int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		if (min != i) {
			doicho(a[min], a[i]);
		}
	}
}
int mahoa(const string& mau) {
	if (mau == "do") return 0;
	if (mau == "trang") return 1;
	if (mau == "xanh") return 2;
}
int main()
{
	const int n = 10;
	string arr[n];
	int arr2[n];
	for (int i = 0; i < n; i++) {
		getline(cin, arr[i]);
	}
	cout << "Day chua sap xep:";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	for (int i = 0; i < n; i++) {
		arr2[i] = mahoa(arr[i]);
	}
	cout << endl;
	sapxep(arr2, n);
	cout << "Day duoc sap xep: ";
	for (int i = 0; i < n; i++) {
		switch (arr2[i]) {
		case 0: cout << "Do "; break;
		case 1: cout << "Trang "; break;
		case 2: cout << "Xanh "; break;
		default:
			break;
		}
	}
	cout << endl;
	return 0;
}
