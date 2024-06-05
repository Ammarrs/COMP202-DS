#include <iostream>

using namespace std;

typedef int etype;
typedef int pos;
//int capacity = 100;

class list {
private :
	etype* elements;
	etype capacity;
	pos last;
public:
	list() {
		capacity = 100;
		elements = new etype[capacity];
		last = -1;
	}

	list(int n) {
		capacity = n;
		elements = new etype[capacity];
		last = -1;
	}

	void makenull(list l) {
		last = -1;
	}

	pos end(list l) {
		return last + 1;
	}

	void insert(etype x, pos p, list l) {
		if (p < 0 && p > last + 1)
			cout << "ERR : position is out of range.\n";
		else if (last == capacity - 1)
			cout << "ERR : list is full.\n";
		else{
			for (int i = last; i >= p; i--)
				elements[i + 1] = elements[i];
			last++;
			elements[p] = x;
		}
			
	}

	pos locate(etype x, list l) {
		for (int i = 0; i < last + 1; i++) {
			if (elements[i] == x)
				return i;
		}
		return end(l);
	}

	etype retrive(pos p, list l) {
		if (p == end(l)) {
			return -999;
		}
		else if(p < 0 && p > last){
			cout << "ERR : pos is out of range.\n";
			return -999;
		}
		else {
			for (int i = 0; i <= last; i++) {
				if (i == p)
					return elements[i];
			}
		}
	}

	void deletepos(pos p, list l) {
		if (p < 0 && p > last)
			cout << "ERR : pos out of range.\n";
		else {
			for (int i = p; i < last + 1; i++) {
				elements[i] = elements[i + 1];
			}
			last--;
		}
	}

	pos next(pos p, list l) {
		if (p < 0 && p > last)
			return -999;
		return p + 1;
	}

	pos prev(pos p, list l) {
		if (p < 0 && p > last)
			return -999;
		return p - 1;
	}

	void printlist(list l) {
		for (int i = 0; i <= last; i++)
			cout << elements[i] << " ";
		cout << endl;
	}

	pos first(list l) {
		return 0;
	}

	void purge(list& l) { // removes duplicates from the list
		pos p, q;
		p = first(l);
		while (p != end(l)) {
			q = next(p, l);
			while (q != end(l)) {
				if (retrive(p, l) == retrive(q, l))
					deletepos(q, l);
				else
					q = next(q, l);
			}
			p = next(p, l);
		}
	}

	list reverse(list l1) {
		list l2(end(l1));
		pos p = prev(end(l1), l1);
		while (p != prev(first(l1), l1)) {
			etype x = retrive(p, l1);
			insert(x, end(l2), l2);

			p = prev(p, l1);
		}
		return l2; 
	}

	void insertXafterY(etype x, etype y, list& l) {
		pos p = locate(y, l);
		pos nextp = next(p, l);
		insert(x, nextp, l);
	}

	list concatinate(list l1, list l2) {
		list l3(end(l1)+end(l2));

		pos curr = first(l1);

		while (curr != end(l1)) {
			etype x = retrive(curr, l1);
			//pos posl3 = first(l3);
			insert(x, end(l3), l3);
			curr = next(curr,l1);
		}

		curr = first(l2);

		while (curr != end(l2)) {
			etype x = retrive(curr, l2);
			//pos posl3 = first(l3);
			insert(x, end(l3), l3);
			curr = next(curr,l2);
		}
		return l3;
	}


	void split(list l1 , list &lodd , list &leven) {
		pos curr = first(l1);
		while (curr != end(l1)) {
			etype x = retrive(curr, l1);
			if (x % 2 == 0)
				insert(x, end(leven), leven);
			else
				insert(x, end(lodd), lodd);
			curr = next(curr, l1);
		}
	}

	etype sum(list l){
		etype sum = 0;
		pos p = first(l);
		while (p != end(l)) {
			etype x = retrive(p, l);
			sum += x;
			p = next(p, l);

		}
		return sum;
	}


};
