#include <bits/stdc++.h>
using namespace std;

struct Node {
    int valor;
    Node *next;
};

Node *create_list(){
    Node *head = new Node;
    head -> valor = -1;
    head -> next = NULL;
    return head;
}

void append(Node *head, int val){
    Node *cur = head;
    while (cur -> next != NULL){

    }
}

int main(){

    Node first;
    Node second;
    Node third;
    Node fourth;    

    first.valor = 2;
    first.next = &second;

    second.valor = 3;
    second.next = &third;

    third.valor = 5;
    third.next = &fourth;

    fourth.valor = 7;
    fourth.next = NULL;

    return 0;
}