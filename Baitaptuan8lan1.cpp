#include <iostream>
using namespace std;
struct Node {
	float heso;
	int somu;
	Node* next;
	Node(float hs, int sm) {
		heso = hs;
		somu = sm;
		next = nullptr;
	}
};
struct ListDT {
	Node* fist;
	Node* last;
	ListDT() {
		fist = last = nullptr;
	}
};
void TaoDT(ListDT& a) {
	a.fist = a.last = nullptr;
}
void addNode(ListDT& a, float hs, int sm) {
	if (hs == 0 && sm == 0) return;
	Node* newNode = new Node(hs, sm);
	if (a.fist == nullptr) {
		a.fist = a.last = newNode;
	}
	else {
		a.last->next = newNode;
		a.last = newNode;
	}
}
void NhapDT(ListDT& a) {
	int n;
	float hs;
	int sm;
	cout << "Nhap bac cua da thuc: ";
	cin >> n;
	int i = 0;
	do {
		cout << "Nhap he so va so mu phan tu thu " << i + 1 << ": ";
		cin >> hs >> sm;
		i++;
		addNode(a, hs, sm);
	} while (hs != 0);
}
void InDT(const ListDT& a) {
	if (a.fist == nullptr) {
		cout << "f(x) = 0" << endl;
		return;
	}

	Node* p = a.fist;
	cout << "f(x) = ";
	while (p != nullptr) {
		if (p->somu == 0) cout << p->heso;
		else {
			if (p -> heso == 1) cout << "x^" << p->somu;
			else
			cout << p->heso << "*x^" << p->somu;
		}
		if (p->next != nullptr) cout << " + ";
		p = p->next;
	}
	cout << endl;
}
void free(ListDT& a) {
	Node* p;
	while (a.fist != nullptr) {
		p = a.fist;
		a.fist = a.fist->next;
		delete p;
	}
	a.last = nullptr;
}
int main() {
	ListDT DT;
	TaoDT(DT);
	NhapDT(DT);
	InDT(DT);
	free(DT);
	return 0;
}

