#include<iostream>
using namespace std;

template<class T> class Node {
public:
    T data;
    Node *next;
    Node(T d=0):data(d),next(NULL){};
};
template<class T> void show(Node<T> *head) {
    Node<T> *node = head;
    while(node->next != NULL) {
        cout<<node->data<<" ";
        node = node->next;
    }
}

main()
{
    // int i=1,d;
    char i = 'a',d;
    Node<char> *node, *head,*prev;
    
    head = new Node<char>('a');
    node = head;
    while(i++ <= 102) {
        node->next = new Node<char>(i);
        node = node->next;
    }
    
    show(head);
}