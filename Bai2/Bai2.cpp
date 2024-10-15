
#include <iostream>
#include <cmath>
using namespace std;
bool Nguyento(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	while (n <= 0) {
		cin >> n;
	}
	int arr[100] = { 0 }, count = 0;
	for (int i = 0; i < n; i++) {
		if (Nguyento(i)) {
			arr[count] = i;
			count++;
		}
	}
	int k = 0;
	int  mangBlum[100] = { 0 };
	for (int i = 0; i < count; i++) {
		for (int j = i; j < count; j++) {
			int c = arr[i] * arr[j];
			if (c < n) {
				mangBlum[k] = c;
				k++;
			}

		}
	}
	for (int i = 0; i < k; i++) {
		cout << mangBlum[i] << " ";
	}
	cout << endl;
	cout << "Cac cap so Blum co tong la mot so Blum nho hon N" << endl;
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			int d = mangBlum[i] + mangBlum[j];
			if (d < n) {
				for (int m = 0; m < k; m++) {
					if (d == mangBlum[m]) cout << mangBlum[i] << " va " << mangBlum[j] << endl;
				}
			}

		}
	}
	int m;
	cout << "Nhap so Blum M =";
	cin >> m;
	int dem = 0;
	for (int i = 0; i < k + 1; i++) {
		if (m == mangBlum[i]) dem++;
	}

	cout << m << ((dem == 1) ? "co " : "khong ") << "ton tai trong mang so Blum da tao";
}
