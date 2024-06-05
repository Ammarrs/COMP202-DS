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
	node* left, *right , *parent;
	node() {
		e = 0;
		left = right = parent =  NULL;
		ctr = 0;
	}
	node(etype a , node* l , node* r) {
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
	
	list<node> children() {
		list<node> l;
		if (left != NULL)
			l.push_back(left);

	}
};
struct BST {


};