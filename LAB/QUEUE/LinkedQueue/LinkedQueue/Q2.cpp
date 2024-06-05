// linked / pointer based

#include <iostream>
#include <string>

using namespace std;

typedef int etype;

struct node {
	etype element;
	node* next;
};

typedef node* position;

class LinkedQueue {
private:
	position front, rear;
	int ctr;

public:
	LinkedQueue() { MakeNull(); }
	void MakeNull() {
		front = NULL;
		rear = NULL;
		ctr = 0;
	}

	bool empty() { return front == NULL; };

	void enqueue(etype x) {
		node* newNode = new node();
		newNode->element = x;
		newNode->next = NULL;
		if (ctr == 0) {
			rear = newNode;
			front = rear;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
		ctr++;
	}

	etype dequeue() {
		if (ctr == 0) {
			cout << "empty";
			return NULL;
		}
		else {
			etype x = front->element;
			node* temp = front;
			front = front->next;
			delete temp;
			ctr--;
			if (ctr == 0) {
				rear = NULL;
			}
			return x;
		}
	}

	etype first() {
		if (empty()) {
			cout << "empty";
			return NULL;
		}
		return front->element;
	}

	void print() {
		cout << "Queue is ==>";
		node* q = front;
		while (q != NULL) {
			cout << q->element << " ";
			q = q->next;
		}
		cout << ".\n";
	}

};


void main() {
	LinkedQueue q;
	q.enqueue(0);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.print();
	cout << "e1 is " << q.dequeue() << endl;
	q.dequeue();
	q.print();

}

