#include <iostream>
// #include <cmath>
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

    node(){
        // parent = NULL;
        left = NULL;
        right = NULL;
        element = 0;
        //int ctr;
    }
    node(etype e , /*node*p,*/node*lft ,node*rgt){
        element = e;
        //parent = p;
        left = lft;
        right = rgt;
    }

    bool isExternal(){
        return left == NULL && right == NULL;
    }

    list<node*> children(){
        list<node*> l;
        if (left != NULL){
            l.push_back(left);
        }
        if (right != NULL){
            l.push_back(right);
        }
        return l;
    }
};

// left < parent
// right > parent
typedef node* treepos;
class BST{
    public:
    treepos _root;
    
    void insert(treepos &ptr , etype elem){
        if (ptr == NULL){
            ptr = new node(elem,NULL,NULL);
        }else{
            if (elem < ptr-> element){
                insert(ptr->left,elem);  
            }
            else{
                insert(ptr->right,elem);
            }
        }
    }

    bool find(treepos ptr,etype elem){
        if (ptr==NULL){
            return false;
        }
        else{
            if(elem == ptr -> element)
            return true;
            else if(elem < ptr->element)
            return find(ptr->left,elem);
            else
            return find(ptr->right,elem);
        }
    }


    treepos minNode(treepos ptr){
        treepos current = ptr;
        // loopdown to find the left most leaf
        while(current -> left != NULL){
            current = current -> left;
        }
        return current;
    }

    void remove(treepos &ptr , etype elem){
        if (ptr == NULL) return;
        if (elem == ptr -> element){
            if (ptr -> left != NULL && ptr -> right != NULL){
                treepos minRight = minNode(ptr -> right);
                ptr -> element = minRight -> element;
                remove(ptr -> right , minRight -> element);
            }
            else {
                treepos discard = ptr;
                if (ptr -> isExternal()) ptr = NULL;
                else if(ptr -> left != NULL) ptr = ptr -> left;
                else ptr = ptr -> right;
                delete discard;
            }
        }
        else if (elem < ptr -> element) remove(ptr -> left , elem);
        else remove(ptr -> right , elem);
    }
    // inorder
    void inorder(treepos ptr){
        if(ptr != NULL){
            inorder(ptr -> left);
            cout << " " << ptr -> element << " " ;
            inorder(ptr -> right);
        }
    }
    // preorder
    void preorder(treepos ptr){
        if(ptr != NULL){
            cout << " " << ptr -> element << " " ;
            inorder(ptr -> left);
            inorder(ptr -> right);
        }
    }
    // postorder
    void postorder(treepos ptr){
        if(ptr != NULL){
            inorder(ptr -> left);
            inorder(ptr -> right);
            cout << " " << ptr -> element << " " ;
        }
    }
};


int main(){
    BST t;
    t.insert(t._root,4);
    t.insert(t._root,2);
    t.insert(t._root,1);
    t.insert(t._root,3);
    t.insert(t._root,6);
    t.insert(t._root,5);
    t.insert(t._root,7);
    cout << "\n minimum value in BST is "<< t.minNode(t._root)->element<<endl;
    t.remove(t._root,4);
    cout<< endl;
    t.inorder(t._root);
    cout<< endl;

    cout << endl;
    return 0;
}