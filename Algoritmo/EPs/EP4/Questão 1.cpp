#include <iostream>
#include <vector>
using namespace std;

struct Link {
    int element;
    Link* next;
};
typedef struct Link Link;

struct Node{
    int key;
    int element;
    Node *left;
    Node *right;
    int height;
};
typedef struct Node Node;

Node *create_bstnode (int k, int e){
    Node *n = new Node;

    n -> key = k;
    n -> element = e;
    n -> left = NULL;
    n -> right = NULL;
    n -> height = 0;

    return n;
}

struct BST{
    Node *root;
    int nodecount;
};
typedef struct BST BST;

BST *create_bst (){
    BST *bst = new BST;

    bst -> root = NULL;
    bst -> nodecount = 0;

    return bst;
}

int h(Node* rt){
    if (rt == NULL){
        return -1;
    }
    return rt -> height;
}

int getBalance (Node *rt){
    if (rt == NULL){
        return 0;
    }
    return h(rt->left) - h(rt->right);
}

Node *rightRotate(Node *rt){
    Node *l = rt->left;
    Node *lr = l->right;

    l->right = rt;
    rt->left = lr;

    rt->height = max(h(rt->left),h(rt->right)) + 1;
    l -> height = max(h(l->left),h(l->right)) + 1;

    return l;
}

Node *leftRotate(Node *rt){
    Node *r = rt->right;
    Node *rl = r->left;

    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left),h(rt->right)) + 1;
    r -> height = max(h(r->left),h(r->right)) + 1;

    return r;
}

Node *inserthelp (Node *rt, int k, int e){
    if (rt == NULL){
        return create_bstnode(k,e);
    }

    if (rt->key > k){
        rt -> left = inserthelp(rt->left,k,e);
    }
    else{
        rt->right = inserthelp(rt->right,k,e);
    }

    rt -> height = 1 + max(h(rt->left),h(rt->right));
    int balance = getBalance(rt);

    if (balance < -1 && k >= rt->right->key){
        return leftRotate(rt);
    }
    if (balance > 1 && k < rt->left->key){
        return rightRotate(rt);
    }

    if (balance > 1 && k >= rt->left->key){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }

    if (balance < -1 && k < rt->right->key){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;

}

void insert (BST *bst, int k, int e){
    bst -> root = inserthelp(bst->root,k,e);
    bst->nodecount++;
}

void preorder (Node* rt){
    if (rt != NULL){
        cout << rt->element << endl;
        preorder(rt->left);
        preorder(rt->right);
    }
}

int main(){

    int c;
    cin >> c;

    for (int i = 0 ; i < c ; i++){
        int n;
        cin >> n;

        BST* avl = create_bst();

        int valor;
        for (int j = 0 ; j < n ; j++){
            cin >> valor;
            Link l = {valor,nullptr};
            insert(avl,valor,valor);
        }

        preorder(avl->root);
        cout << "END" << endl;

    }

    return 0;
}