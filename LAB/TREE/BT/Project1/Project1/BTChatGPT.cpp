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

    node(etype e, node* p, node* l, node* r) : element(e), parent(p), left(l), right(r) {}

    bool isExternal() {
        return left == nullptr && right == nullptr;
    }

    list<node*> children() {
        list<node*> l;
        if (left != nullptr)
            l.push_back(left);
        if (right != nullptr)
            l.push_back(right);
        return l;
    }

    bool isRoot() {
        return parent == nullptr;
    }
};

class LBT {
public:
    node* _root;
    int ctr;
    LBT() : _root(nullptr), ctr(0) {}

    ~LBT() {
        deleteSubtree(_root);
    }

    void deleteSubtree(node* root) {
        if (root != nullptr) {
            deleteSubtree(root->left);
            deleteSubtree(root->right);
            delete root;
        }
    }

    int size() {
        return ctr;
    }

    bool empty() {
        return _root == nullptr;
    }

    node* getRoot() {
        return _root;
    }

    node* addRoot(etype e) {
        if (!empty())
            cout << "Tree is not empty\n";
        else {
            _root = new node(e, nullptr, nullptr, nullptr);
            ctr++;
        }
        return _root;
    }

    node* addLeft(node* n, etype e) {
        if (n->left != nullptr)
            cout << "Node already has a left child\n";
        else {
            node* child = new node(e, n, nullptr, nullptr);
            n->left = child;
            ctr++;
            return child;
        }
    }

    node* addRight(node* n, etype e) {
        if (n->right != nullptr)
            cout << "Node already has a right child\n";
        else {
            node* child = new node(e, n, nullptr, nullptr);
            n->right = child;
            ctr++;
            return child;
        }
    }

    void attach(node* p, LBT t1, LBT t2) {
        if (!p->isExternal())
            cout << "Node must be external or leaf\n";
        else {
            p->left = t1._root;
            p->right = t2._root;
            if (t1._root != nullptr) t1._root->parent = p;
            if (t2._root != nullptr) t2._root->parent = p;
            ctr += (t1.size() + t2.size());
        }
    }

    void preorder(node* p) {
        if (p != nullptr) {
            cout << " " << p->element << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    int evaluateExp(LBT t, node* p) {
        if (!p->isExternal()) {
            int x = evaluateExp(t, p->left);
            int y = evaluateExp(t, p->right);
            switch (p->element) {
            case '+': return x + y; break;
            case '-': return x - y; break;
            case '*': return x * y; break;
            case '/': return x / y; break;
            default: return 0;
            }
        }
        else
            return int(p->element - '0');
    }
};

int main2() {
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
    t13.attach(t13._root, t26, t27);
    t4.attach(t4._root, t8, t9);
    t5.attach(t5._root, t10, t11);
    t6.attach(t6._root, t12, t13);
    t2.attach(t2._root, t4, t5);
    t3.attach(t3._root, t6, t7);
    t1.attach(t1._root, t2, t3);

    t1.preorder(t1._root);
    cout << "\nResult: " << t1.evaluateExp(t1, t1._root) << endl;

    return 0;
}
