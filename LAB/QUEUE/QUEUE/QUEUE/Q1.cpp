//array based !!!!!

#include<iostream> 
#include <list>
#include <string>

using namespace std;
typedef int pos;
typedef int etype;
class queue {
private:
	int capacity;
	pos front, rear;
	int ctr;
	etype* elements;
public:
	queue(int size = 10) { makeNull(size); }
	void makeNull(int size = 10) {
		elements = new etype[size];
		front = -1;
		rear = -1;
		capacity = size;
		ctr = 0;
	}

	bool isEmpty() { return ctr == 0; }
	bool isFull() { return ctr == capacity; }

	void enqueue(etype x) {
		if (isFull()) {
			cout << "ERR:Queue is Full.\n";
		}
		else {
			rear = (rear + 1) % capacity;
			elements[rear] = x;
			if (ctr == 0) { // if its the 1st element 
				front = 0;
			}
			ctr++;
		}
	}

	etype dequeue() {
		if (isEmpty()) {
			cout << "ERR: the Queue is Empty\n";
			return -1;
		}
		else {
			etype x = elements[front];
			front = (front + 1) % capacity;
			ctr--;
			return x;
		}
	}

	etype first() {
		if (isEmpty()) {
			cout << "ERR: Queue is Empty\n";
			return -1;
		}
		else {
			return elements[front];
		}
	}

	// print 

	void print() {
		cout << "front-->";
		cout << "|\t" << elements[front] << "\t|\n";
		for (int i = (front + 1) % capacity; i != rear; i = (i + 1) % capacity) {
			cout << "  \t|\t" << elements[i] << "\t|\n";
		}
		cout << "rear -->";
		cout << "|\t" << elements[rear] << "\t|\n";
		cout << "\t|---------------|\n";
	}
};


void main() {
	queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(6);
	q.enqueue(7);
	q.print();
	cout << q.dequeue() << " has been deleted.\n";
	q.dequeue();
	cout << q.dequeue() << " has been deleted.\n";
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.print();

}