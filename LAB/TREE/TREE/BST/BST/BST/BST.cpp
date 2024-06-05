
#include <iostream>
#include<list>
using namespace std;
typedef int etype;
struct node {
	etype element;
	node* left;
	node* right;
	node()
	{
		element = 0;
		right = left = NULL;
	}
	node(etype x, node* l, node* r)
	{
		element = x;
		left = l;
		right = r;
	}
	bool isexternal()
	{
		return left == NULL && right == NULL;
	}
	list <node*> children()
	{
		list <node*> l;
		if (left != NULL)
			l.push_back(left);
		if (right != NULL)
			l.push_back(right);
		return l;
	}
};
typedef node* pos;
class bstree {
public:
	pos root;
	bstree()
	{
		root = NULL;
	}
	bool Empty()
	{
		return root == NULL;
	}
	void Insert(pos& p, etype x)
	{
		if (p == NULL)
			p = new node(x, NULL, NULL);
		else
		{
			if (p->element > x)
				Insert(p->left, x);
			else
				Insert(p->right, x);
		}
	}
	void Remove(pos& p, etype x)
	{
		if (p == NULL)
			return;
		if (x == p->element)
		{
			if (p->left != NULL && p->right != NULL)
			{
				pos mnode = minnode(p->right);
				p->element = mnode->element;
				Remove(p->right, mnode->element);
			}
			else
			{
				pos discard = p;
				if (p->isexternal())
					p = NULL;
				else if (p->left != NULL)
					p = p->left;
				else
					p = p->right;
				delete discard;
			}
		}
		else if (x < p->element)
			Remove(p->left, x);
		else
			Remove(p->right, x);
	}
	pos minnode(pos p)
	{
		pos curr = p;
		while (curr->left != NULL)
		{
			curr = curr->left;
		}
		return curr;
	}
	pos Root()
	{
		return root;
	}
	pos maxnode(pos p)
	{
		pos curr = p;
		while (curr->right != NULL)
		{
			curr = curr->right;
		}
		return curr;
	}
	void preorder(pos p)
	{
		if (p != NULL) {
			cout << p->element << " ";
			preorder(p->left);
			preorder(p->right);
		}
	}
	void inorder(pos p)
	{
		if (p != NULL) {
			inorder(p->left);
			cout << p->element << " ";
			inorder(p->right);
		}
	}
	void postorder(pos p)
	{
		if (p != NULL) {
			postorder(p->left);
			postorder(p->right);
			cout << p->element << " ";
		}
	}
	int sum(pos p, int& s)
	{
		if (p != NULL)
		{
			sum(p->left, s);
			s += p->element;
			sum(p->right, s);
		}
		return s;
	}
	int Size(pos p, int& sz)
	{
		if (p != NULL)
		{
			Size(p->left, sz);
			sz++;
			Size(p->right, sz);
		}
		return sz;
	}
	int occur(pos p, etype x, int& c)
	{
		if (p == NULL)
			return c;
		if (p->element > x) {
			if (p->element == x)
				c++;
			occur(p->left, x, c);
		}
		else
		{
			if (p->element == x)
				c++;
			occur(p->right, x, c);
		}
	}
};

int main()
{
	int c = 0; int s = 0; int sz = 0;
	bstree t;
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
	t.Remove(t.root, 10);
	t.inorder(t.root); cout << endl;
	cout << "size of tree = " << t.Size(t.root, sz) << endl;
	cout << "min node = " << t.minnode(t.root)->element << endl;
	cout << "max node = " << t.maxnode(t.root)->element << endl;
	cout << "sum of nodes = " << t.sum(t.root, s) << endl;
	cout << "number of occurrence of " << 4 << " = " << t.occur(t.root, 4, c);
	return 0;
}
