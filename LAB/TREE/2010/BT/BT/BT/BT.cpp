#include <iostream>
#include <string>
#include <algorithm>
#include <list>


using namespace std;

typedef int etype;

struct node {

	etype element;
	node* parent;
	node* left;
	node* right;

	node() {
		element = 0;
		parent = NULL;
		left = NULL;
		right = NULL; 
	}

	node(etype e, node* parent, node* left, node* right) {
		element = e;
		parent = parent;
		left = left;
		right = right;
	}

	bool isExternal() {
		return left == NULL && right == NULL;
	}

	list<node*> children() {
		list<node*> l;
		if (left != NULL)
			l.push_back(left);
		if (right != NULL)
			l.push_back(right);
		return l;
	}

	bool isRoot() {
		return parent == NULL;
	}
};



class LBT {
public:
	node* _root;
	int ctr;
	LBT() {
		_root = NULL;
		ctr = 0;
	}

	int size()
	{
		return ctr;
	}

	bool empty() {
		return _root == NULL;
	}

	node* getRoot() {
		return _root;
	}

	node* addRoot(etype e) {
		if (!empty())
			cout << "tree is not empty\n";
		else {
			_root = new node(e, NULL, NULL, NULL);
			ctr++;
		}
		return _root;
	}

	node* addLeft(node* n, etype e) {
		if (n->left != NULL)
			cout << "node already have left child\n";
		else {
			node* child = new node(e, n, NULL, NULL);// 1 , 2 , 3 
			//equivalent to child.parent = n;
			n->left = child;
			ctr++;
			return child;
		}
	}

	node* addRight(node* n, etype e) {
		if (n->right != NULL)
			cout << "node already have right child\n";
		else {
			node* child = new node(e, n, NULL, NULL);// 1 , 2 , 3 
			//equivalent to child.parent = n;
			n->right = child;
			ctr++;
			return child;
		}
	}

	void attach(node* p, LBT t1, LBT t2) {
		if (!p->isExternal())
			cout << "node must be external or leaf\n";
		else {
			p->left = t1._root;//2
			p->right = t2._root;//3
			if(t1._root!=NULL)t1._root->parent = p;//4
			if (t2._root != NULL)t2._root->parent = p;//5
			ctr += (t1.size() + t2.size());//6
		}
	}

	void preorder(node* p){
		cout << " " << p->element << " ";
		if (p->left != NULL)
			preorder(p->left);
		if (p->right != NULL)
			preorder(p->right);
	}

	void postorder(node* p) {
		if (p->left != NULL)
			postorder(p->left);
		if (p->right != NULL)
			postorder(p->right);
		cout << " " << p->element << " ";
	}

	void inorder(node* p) {
		if (p->left != NULL)
			inorder(p->left);
		cout << " " << p->element << " ";
		if (p->right != NULL)
			inorder(p->right);
	}
};

void main() {
	cout << int('3' - '0');
	LBT t1;
	t1.addRoot('-');
	LBT t2;
	t2.addRoot('/');
	LBT t3;
	t3.addRoot('+');
	LBT t4;
	t4.addRoot('*');
	LBT t5;
	t5.addRoot('+');
	LBT t6;
	t6.addRoot('*');
	LBT t7;
	t7.addRoot('8');
	LBT t8;
	t8.addRoot('+');
	LBT t9;
	t9.addRoot('3');
	LBT t10;
	t10.addRoot('-');
	LBT t11;
	t11.addRoot('2');
	LBT t12;
	t12.addRoot('3');
	LBT t13;
	t13.addRoot('-');
	LBT t16;
	t16.addRoot('3');
	LBT t17;
	t17.addRoot('1');
	LBT t20;
	t20.addRoot('9');
	LBT t21;
	t21.addRoot('5');
	LBT t26;
	t26.addRoot('7');
	LBT t27;
	t27.addRoot('4');
	t8.attach(t8._root, t16, t17);
	t10.attach(t10._root, t20, t21);
	t4.attach(t4._root, t8, t9);
	t5.attach(t5._root, t10, t11);
	t2.attach(t2._root, t4, t5);
	t13.attach(t13._root, t26, t27);
	t6.attach(t6._root, t12, t13);
	t3.attach(t3._root, t6, t7);
	t1.attach(t1._root, t2, t3);

	t1.preorder(t1._root);

	system("pause");
}
