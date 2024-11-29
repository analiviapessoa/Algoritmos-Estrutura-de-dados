#include <iostream>
#include <vector>
using namespace std;

struct Link {
    int element;
    Link* next;
};
typedef struct Link Link;

struct Node{
    Link key;
    int element;
    Node *left;
    Node *right;
};
typedef struct Node Node;

Node *create_bstnode (Link k, int e){
    Node *n = new Node;

    n -> key = k;
    n -> element = e;
    n -> left = NULL;
    n -> right = NULL;

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

bool compare(Link &a, Link &b) {
    return (a.element) > (b.element);
}

Node *inserthelp (Node *rt, Link k, int e){
    if (rt == NULL){
        return create_bstnode(k,e);
    }

    if (compare(rt->key, k) == true){
        rt -> left = inserthelp(rt->left,k,e);
    }
    else{
        rt -> right = inserthelp(rt->right,k,e);
    }
    return rt;
}

void insert (BST *bst, Link k, int e){
    bst -> root = inserthelp(bst->root,k,e);
    bst->nodecount++;
}

void preorder (Node *rt, vector<int> &resultado){
    if (rt != NULL){
        resultado.push_back(rt->key.element);
        preorder(rt->left, resultado);
        preorder(rt->right, resultado);
    }
}

void inorder (Node *rt, vector<int> &resultado){
    if (rt != NULL){
        inorder(rt->left, resultado);
        resultado.push_back(rt->key.element);
        inorder(rt->right, resultado);
    }
}

void postorder (Node *rt, vector<int> &resultado){
    if (rt != NULL){
        postorder(rt->left, resultado);
        postorder(rt->right, resultado);
        resultado.push_back(rt->key.element);
    }
}

void print_vector (const vector<int> &v){
    
    for (int i = 0; i < v.size() ; i++){
        cout << " " << v[i];
    }

    cout << endl;
}

int main() {
    BST* bst = create_bst();

    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i++){
        int numero;
        cin >> numero;
        Link l = {numero,nullptr};
        insert(bst,l,numero);
    }

    vector<int> resultado;
    preorder(bst->root,resultado);
    cout << "Pre order :";
    print_vector(resultado);
    vector<int> resultado2;
    inorder(bst->root,resultado2);
    cout << "In order  :";
    print_vector(resultado2);
    vector<int> resultado3;
    postorder(bst->root,resultado3);
    cout << "Post order:";
    print_vector(resultado3);

    return 0;
}