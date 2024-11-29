#include <iostream>
using namespace std;

struct Node{
    int key;
    int element;
    Node* left;
    Node* right;
    int height;
    int subsize;
};

Node *create_bstnode (int k, int e){
    Node *n = new Node;

    n -> key = k;
    n -> element = e;
    n -> left = nullptr;
    n -> right = nullptr;
    n -> height = 0;
    n -> subsize = 1;

    return n;
}

struct BST{
    Node *root;
    int nodecount;
};

BST *create_bst (){
    BST *bst = new BST;

    bst -> root = nullptr;
    bst -> nodecount = 0;

    return bst;
}

int numerodenos(Node* rt) {
    if(rt!=nullptr){
        return rt->subsize;
    }
    else{
        return 0;
    }
}

int findhelp (Node *rt, int k, int &pos){
    if (rt == nullptr){
        return -1;
    }

    if (rt->key > k){
        return findhelp(rt->left,k,pos);

    }else if (k > rt->key){
        pos += numerodenos(rt->left) + 1;
        return findhelp(rt->right,k,pos);

    }else{
        pos+=numerodenos(rt->left);
        return pos+1;
    }
}

int find (BST *bst, int k){
    int pos = 0;
    return findhelp(bst->root, k, pos);
}

int h(Node* rt) {
    if(rt!=nullptr){
        return rt -> height;
    }
    else{
        return -1;
    }
}

int getBalance (Node *rt){
    if (rt != nullptr){
        return h(rt -> left) - h(rt->right);
    }
    else{
        return 0;
    }
}

Node *rightRotate(Node *rt){
    Node *l = rt->left;
    Node *lr = l->right;

    l->right = rt;
    rt->left = lr;

    rt->height = max(h(rt->left),h(rt->right)) + 1;
    l->height = max(h(l->left),h(l->right)) + 1;

    rt->subsize = numerodenos(rt->left) + numerodenos(rt->right) + 1;
    l->subsize = numerodenos(l->left) + numerodenos(l->right) + 1;
    
    return l;
}

Node *leftRotate(Node *rt){
    Node *r = rt->right;
    Node *rl = r->left;

    r->left = rt;
    rt->right = rl;

    rt->height = max(h(rt->left),h(rt->right)) + 1;
    r -> height = max(h(r->left),h(r->right)) + 1;
    
    rt->subsize = numerodenos(rt->left) + numerodenos(rt->right) + 1;
    r->subsize = numerodenos(r->left) + numerodenos(r->right) + 1;
    
    return r;
}

Node *inserthelp (Node *rt, int k, int e){
    if (rt == nullptr){
        return create_bstnode(k,e);
    }
    if (rt->key > k){
        rt -> left = inserthelp(rt->left,k,e);
    }else{
        rt->right = inserthelp(rt->right,k,e);
    }

    rt -> height = 1 + max(h(rt->left),h(rt->right));
    rt -> subsize = 1 + numerodenos(rt->left) + numerodenos(rt->right);
    
    int balance = getBalance(rt);
    
    if (balance < -1 && (k >= rt->right->key)){
        return leftRotate(rt);
    }
    if (balance > 1 && k < rt->left->key){
        return rightRotate(rt);
    }
    if (balance > 1 && (k >= rt->left->key)){
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

int main() {

    int Q;
    cin >> Q;

    BST* avl = create_bst();

    for (int i = 0 ; i < Q ; ++i){
        int operacao, numero;
        cin >> operacao >> numero;

        if (operacao == 1){
            insert(avl,numero,numero);
        }
        else if (operacao == 2){
            auto f = find(avl, numero);
            if (f== -1){
                cout << "Data tidak ada" << endl;
            }
            else{
                cout << f << endl;
            }    
        }
    }
    return 0;
}