#include <iostream>
using namespace std;

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

int findhelp (Node *rt, int k){
    if (rt == NULL){
        return -1;
    }

    if (rt -> key > k){
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

Node *removehelp (Node *rt, int k){
    if (rt == NULL){
        return rt;
    }

    if (rt->key > k){
        rt -> left = removehelp(rt->left,k);
    }
    else if (k > rt->key){
        rt->right = removehelp(rt->right,k);
    }
    else{
        if (rt -> left == NULL || rt->right == NULL){
            Node *temp;

            if (rt->left != NULL){
                temp = rt->left;
            }
            else{
                temp = rt -> right;
            }

            if (temp == NULL){
                temp = rt;
                rt = NULL;
            }
            else{
                *rt = *temp;
            }
            delete temp;
        }
        else{
            Node* temp = getmin(rt->right);
            rt->key = temp->key;
            rt->element = temp->element;
            rt->right = removehelp(rt->right,temp->key);
        }
    }

    if (rt == NULL){
        return rt;
    }

    rt -> height = 1 + max(h(rt->left),h(rt->right));
    int balance = getBalance(rt);

    if (balance > 1 && getBalance(rt->left) >= 0){
        return rightRotate(rt);
    }

    if (balance > 1 && getBalance(rt->left) < 0){
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }

    if (balance < -1 && getBalance(rt->right) <= 0){
        return leftRotate(rt);
    }

    if (balance < -1 && getBalance(rt->right) > 0){
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;

}

int remove (BST *bst, int k){
    int temp = findhelp(bst -> root, k);

    if (temp != -1){
        bst->root = removehelp(bst->root,k);
        bst->nodecount--;
    }
    return temp;
}

void preorder (Node* rt){
    if (rt != NULL){
        cout << rt->element << " ";
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder (Node *rt){
    if (rt != NULL){
        inorder(rt->left);
        cout << rt->element << " ";
        inorder(rt->right);
    }
}

void postorder (Node *rt){
    if (rt != NULL){
        postorder(rt->left);
        postorder(rt->right);
        cout << rt->element << " ";
    }
}

int main() {

    BST* avl = create_bst();

    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i ++){
        int valor;
        string operacao;
        cin >> operacao;

        if (operacao == "insert"){
            cin >> valor;
            insert(avl,valor,valor);
        }
        else if (operacao == "pre"){
            preorder(avl->root);
            cout << endl;
        }
        else if (operacao == "in"){
            inorder(avl->root);
            cout << endl;
        }
        else if (operacao == "post"){
            postorder(avl->root);
            cout << endl;
        }
    }

    delete avl;
    
    return 0;
}