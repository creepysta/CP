#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int d=0):data(d),next(NULL){};
};

void show(Node *head) {
    Node *node = head;
    while(node->next != NULL) {
        cout<<node->data<<" ";
        node = node->next;
    }
}

main()
{
    int i=1,d;
    Node *node, *head,*prev;
    
    head = new Node(1);
    node = head;
    while(i++ <= 5) {
        node->next = new Node(i);
        node = node->next;
    }
    
    show(head);
}
