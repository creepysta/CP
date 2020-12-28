#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

template<class T> class LinkedList {
	private:
	struct Node {
		T data;
		Node *next, *prev;
		Node(T _data) : data(_data), next(NULL), prev(NULL){};
	};
	Node *node, *head;
	public:
	LinkedList() : node(NULL), head(NULL) {};
	void addNode(ll data) {
		if(head == NULL) {
			head = new Node(data);
		}
		else {
			node = head;
			while(head->next != NULL) {
				head = head->next;
			}
			head->next = new Node(data);
			head = node;
		}
	}
	ll len() {
		ll cnt = 0;
		node = head;
		while(node) {
			cnt++;
			node = node->next;
		}
		return cnt;
	}
	void show() {
		node = head;
		while(node != NULL) {
			cout << node->data << ' ';
			node = node->next;
		}
		cout << endl;
	}
	void rev() {
		Node *curr = head;
		// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
		// NULL <- 1 <- 2 <- 3 <- 4 <- 5
		// take prev, next
		// node->next = node means every element points to itself;
		Node *next = NULL, *prev=NULL;
		while(curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
};


int main () {
	LinkedList<int> linkedList;
	for(ll i=0;i < 5; i++) linkedList.addNode(i+1);
	linkedList.show();
	linkedList.rev();
	linkedList.show();
	linkedList.rev();
	linkedList.show();
	cout << linkedList.len() << endl;
	return 0;
}
