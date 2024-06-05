#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef int etype, pos;
int capacity = 100;
struct list {
	etype* elem = new etype[capacity];
	// pos p;
	int last;
	list() {
		last = -1;
	}
	list(int k) {
		last = k;
	}

};

pos end(list l) {
	return l.last + 1;
}

pos first(list l) {
	return 0;
}

pos next(pos p, list l) {
	if (p<0 || p>l.last + 1) {
		cout << "pos out of range\n";
		return -999999;
	}
	else if (p == capacity - 1) {
		cout << "it's the last elem !!\n";
		return -999999;
	}
	else {
		return p + 1;
	}
}

pos prev(pos p, list l) {
	if (p<0 || p>l.last + 1) {
		cout << "pos out of range\n";
		return -999999;
	}
	else if (p == 0) {
		cout << "it's the first elem !!\n";
		return -999999;
	}
	else {
		return p - 1;
	}
}

void insert(int x, pos p, list l) {
	if (l.last == capacity - 1)
		cout << "list is full\n";
	else if (p<0 || p>l.last + 1)
		cout << "pos out of range\n";
	else {
		for (int q = l.last; q >= p; q--) {
			l.elem[q + 1] = l.elem[q];
		}
		l.elem[p] = x;
		l.last++;
	}
}

void remove(int x, pos p, list l) {
	if (l.last = -1)
		cout << "list is empty\n";
	else if (p<0 || p>l.last)
		cout << "p out of range\n";
	else {
		for (int i = p + 1; i < l.last + 1; i++) {
			l.elem[i - 1] = l.elem[i];
		}
		l.last--;
	}

}

pos locate(int x, list l) {
	for (int q = 0; q < l.last + 1; q++) {
		if (l.elem[q] == x)
			return q;
		return -999999;
	}
}

void makeNULL(list l) {
	l.last = -1;
}

etype retrieve(pos p, list l) {
	if (p < 0 || p > l.last) {
		cout << "pos out of range\n";
		return -999999;
	}
	return l.elem[p];
}

etype displist(list l) {
	for (int i = first(l); i <= l.last; i++)
		return l.elem[i];
}



void main() {
	list l(10);
	insert(5, 0, l);
	insert(4, 1, l);
	insert(51, 2, l);
	insert(85, 3, l);
	insert(3, 4, l);
	insert(48, 5, l);
	insert(9, 6, l);
	insert(32, 7, l);
	insert(12, 8, l);
	insert(17, 9, l);
	displist(l);



}