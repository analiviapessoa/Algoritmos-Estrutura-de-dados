#include <iostream>
using namespace std;

struct Node{
    int key;
    int element;
    Node *left;
    Node *right;
};
typedef struct Node Node;

Node *create_bstnode (int k, int e){
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

int findhelp (Node *rt, int k){
    if (rt == NULL){
        return -1;
    }

    if (rt->key > k){
        return findhelp(rt->left,k);
    }
    else if (k > rt->key){
        return findhelp(rt->right,k);
    }
    else{
        return (rt->element);
    }
}

int find (BST *bst, int k){
    return findhelp(bst->root, k);
}

Node *inserthelp (Node *rt, int k, int e){
    if (rt == NULL){
        return create_bstnode(k,e);
    }

    if (rt->key > k){
        rt -> left = inserthelp(rt->left,k,e);
    }
    else{
        rt -> right = inserthelp(rt->right,k,e);
    }
    return rt;
}

void insert (BST *bst, int k, int e){
    bst -> root = inserthelp(bst->root,k,e);
    bst->nodecount++;
}

Node *getmin(Node *rt){
    if (rt->left == NULL){
        return rt;
    }
    return getmin(rt->left);
}

Node *deletemin(Node *rt){
    if (rt->left == NULL){
        return rt->right;
    }
    rt->left = deletemin(rt->left);
    return rt;
}

Node *removehelp(Node *rt, int k){
    if (rt == NULL){
        return NULL;
    }

    if (rt->key > k){
        rt->left = removehelp(rt->left,k);
    }
    else if(k > rt->key){
        rt->right = removehelp(rt->right,k);
    }
    else{
        if(rt->left == NULL){
            Node* temp = rt -> right;
            delete rt;
            return temp;
        }
        else if (rt->right == NULL){
            return rt->left;
        }
        else{
            Node *temp = getmin(rt->right);
            rt->element = temp -> element;
            rt->key = temp -> key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}

int remove (BST *bst, int k){
    int temp = findhelp(bst -> root, k);

    if (temp != NULL){
        bst->root = removehelp(bst->root,k);
        bst->nodecount--;
    }
    return temp;
}

void preorder (Node *rt){
    if (rt != NULL){
        cout << rt -> element << " ";
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder (Node *rt){
    if (rt != NULL){
        inorder(rt->left);
        cout << rt -> element << " ";
        inorder(rt->right);
    }
}

void postorder (Node *rt){
    if (rt != NULL){
        postorder(rt->left);
        postorder(rt->right);
        cout << rt -> element << " ";
    }
}

int height (Node *rt){
    if (rt == NULL){
        return -1;
    }
    else{
        int Hleft = height(rt->left);
        int Hright = height(rt->right);
        return max(Hleft,Hright) + 1;
    }
}

int main() {
    BST* bst = create_bst();

    insert(bst, 10, 10);
    insert(bst, 20, 20);
    insert(bst, 30, 30);

    preorder(bst->root);
    cout << endl;
    
    inorder(bst->root);
    cout << endl;
    
    postorder(bst->root);
    cout << endl;

    cout << "Elemento encontrado: " << find(bst, 10) << endl;
    cout << "Altura da árvore: " << height(bst->root) << endl;

    cout << "Elemento removido: " << remove(bst, 10) << endl;
    cout << "Altura da árvore após remoção: " << height(bst->root) << endl;
    
    delete bst;
    return 0;
}