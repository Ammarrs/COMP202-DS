#include <iostream>

using namespace std;

typedef int etype;

struct node {
	etype element;
	node* next;
};

typedef node* pos;

// very imp note : position p always points to the prev. node to the current node
// to be processed

class list {
private:
	node* head;
	node* tail;
	int ctr;

public:
	list() {
		makenull();
	}
	void makenull() {
		head = new node;
		head->next = nullptr;
		tail = nullptr;
		ctr = 0;
	}

	// return ptr to the last node
	pos end() {
		if (head->next == nullptr)
			return head;
		return tail;
	}

	//insert x at pos p in list l
	/// if list l has no pos p the result is undefined
	void insert(etype x, pos p = nullptr) {
		if (p == nullptr)
			p = end();
		pos newnode = new node;
		newnode->element = x;
		newnode->next = p->next;
		p->next = newnode;
		if (newnode->next == nullptr)
			tail = newnode;
		ctr++;
	}

	// delet ethe elem position p in list l
	void Delete(pos p) {
		if (p == end() || p == nullptr)
			cout << "no elem to be deleted.\n";
		if (p->next == tail)
			tail = p;
		pos temp = p->next;
		p->next = p->next->next;
		delete temp;
		ctr--;
	}


	// returns the pos p of an elem in list l

	pos locate(etype x) {
		pos p = head;
		while (p->next != nullptr) {
			if (p->next->element == x)
				return p;
			p = p->next;
		}
		return p; // equivalent to return end()
	}

	pos locateinrange(etype x,pos spos,pos endp) {
		pos p = spos;
		while (p->next != nullptr && p->next != endp ) {
			if (p->next->element == x)
				return p;
			p = p->next;
		}
		return p; // equivalent to return end()
	}

	etype retrive(pos p) {
		if (p == nullptr) {
			cout << "ERR : in retrive.\n";
			return NULL;
		}
		return p->next->element;
	}

	void printlist() {
		cout << "list is: ";
		pos p = head->next;
		while (p != nullptr) {
			cout << p->element << " ";
			p = p->next;
		}
		cout << endl;
	}

	pos first() {
		return head;
	}



};