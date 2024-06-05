// BST 

#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

typedef int etype;

struct node {
	etype e;
	int ctr;
	node* left, * right, * parent;
	node() {
		e = 0;
		left = right = parent = NULL;
		ctr = 0;
	}
	node(etype a, node* l, node* r) {
		e = a;
		left = l;
		right = r;
	}

	bool isEx() {
		return left == NULL && right == NULL;
	}

	bool isRoot() {
		// return 
	}

	list<node*> children() {
		list<node*> l;
		if (left != NULL)
			l.push_back(left);
		if (right != NULL)
			l.push_back(right);
		return l;

	}
};
typedef node* position;
struct BST {
	position root;
	BST() {
		root = NULL;
	}

	bool isEmpty() {
		return root == NULL;
	}

	void Insert(position& p, etype x) {
		if (p == NULL)
			p = new node(x, NULL, NULL);
		else{
			if (p->e > x)
				Insert(p->left, x);
			else
				Insert(p->right, x);
		}
	}

	void remove(position& p, etype x) {
		if (p == NULL)
			return;
		if (x == p->e)
		{
			if (p->left != NULL && p->right != NULL)
			{
				position mnode = minnode(p->right);
				p->e = mnode->e;
				remove(p->right, mnode->e);
			}
			else {
				position discard = p;
				if (p->isEx())
					p = NULL;
				else if (p->left != NULL)
					p = p->left;
				else
					p = p->right;
				delete discard;

			}
		}
		else if (x < p->e)
			remove(p->left, x);
		else
			remove(p->right, x);
	}

	position minnode(position p)
	{
		position curr = p;
		while (curr->left != NULL)
		{
			curr = curr->left;
		}
		return curr;
	}

	position root()
	{
		return root;
	}

	position maxnode(position p) {
		position curr = p;
		while (p->right != NULL) {
			curr = curr->right;
		}
		return curr;
	}

	void preorder(position p)
	{
		if (p != NULL)
		{
			cout << p->e << " ";
			preorder(p->left);
			preorder(p->right);
		}
	}

	void inorder(position p)
	{
		if (p != NULL) {
			inorder(p->left);
			cout << p->e << " ";
			inorder(p->right);
		}
	}

	void postorder(position p) {
		if (p != NULL) {
			postorder(p->left);
			postorder(p->right);
			cout << p->e << " ";
		}
	}

	int sum(position p, int& s) {
		if (p != NULL) {
			sum(p->left, s);
			s += p->e;
			sum(p->right, s);
		}
		return s;
	}

	int size(position p, int& sz) {
		if (p != NULL) {
			size(p->left, sz);
			sz++;
			size(p->right, sz);
		}
		return sz;
	}

	int occur(position p, etype x, int& ctr) {
		if (p == NULL)
			return ctr;
		if (p->e > x)
		{
			if (p->e == x)
				ctr++;
			occur(p->left, x, ctr);
		}
		else {
			if (p->e == x)
				ctr++;
			occur(p->right, x, ctr);
		}
	}
};


void main() {
	int c = 0; int s = 0; int sz = 0;
	BST t;
	t.Insert(t.root, 10);
	t.Insert(t.root, 5);
	t.Insert(t.root, 12);
	t.Insert(t.root, 4);
	t.Insert(t.root, 4);
	t.Insert(t.root, 6);
	t.Insert(t.root, 4);
	t.Insert(t.root, 11);
	t.Insert(t.root, 13);
	t.inorder(t.root); cout << endl;
	t.preorder(t.root); cout << endl;
	t.postorder(t.root); cout << endl;
	t.remove(t.root, 10);
	t.inorder(t.root); cout << endl;
	cout << "size of tree = " << t.size(t.root, sz) << endl;
	cout << "min node = " << t.minnode(t.root)->e << endl;
	cout << "max node = " << t.maxnode(t.root)->e << endl;
	cout << "sum of nodes = " << t.sum(t.root, s) << endl;
	cout << "number of occurrence of " << 4 << " = " << t.occur(t.root, 4, c);
}