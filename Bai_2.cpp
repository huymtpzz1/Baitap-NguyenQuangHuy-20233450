
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
	cout << "Nhap so Blum M = ";
	cin >> m;
	int dem = 0;
	for (int i = 0; i < k + 1; i++) {
		if (m == mangBlum[i]) dem++;
	}
	cout << m << ((dem == 1) ? " co " : " khong ") << "ton tai trong mang so Blum da tao";
}

/*
Giải thuật:

Input: Nhập vào một số nguyên N
Output: Mảng số nguyên bao gôm các số nửa nguyên tố
tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N
Kiểm tra xem một số Blum M có tồn tại trong dãy số Blum được tạo ra hay

Bước 1:
kiểm tra và tìm mảng số nguyên tố nhỏ hơn số N
if n <= 1, trả về false
for i = 2 đến căn n 
if n chia hết cho i thì trả về false 
else trả về true và lưu vào mảng arr[]
Bước 2:
Nhân đôi một các số nguyên tố trong mảng với nhau và so sánh với n
c = arr[i] * arr[j] 
Nếu nhỏ hơn thì lưu vào 1 mảng mới
ìf c < n lưu vào mảng mangBlum[]
Sau đó in ra màn hình dãy số nửa nguyên tố tạo được
Bước 3:
Tính tổng 2 số bất kì trong mảng số Blum và so sánh với số N
d = mangBlum[i] + mangBlum[j]
Nếu nhỏ hơn thì kiểm tra xem có thuộc dãy số dã tạo được không 
ìf d < n, và kiểm tra trong mảng
Thỏa mãn thì in cặp số ra màn hình
Bước 4:
Nhập 1 số Blum M bất kì và kiểm tra trong dãy đã tạo có M không
Nếu có thì in ra màn hình có tồn tại, ngược lại in ra không tồn tại
*/