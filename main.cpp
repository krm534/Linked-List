#include <iostream>
#include <string>
#include "linked-list.h"

using namespace std;

void testAppend() {
	Node* head = nullptr;
	LinkedList* test = new LinkedList();

	for (int i = 0; i < 10; i++) {
		cout << "HEAD: " << head << endl;
	 	test->append(&head, i + 1);
	}

	test->printList(head);
}

void testPrepend() {
	Node* head = nullptr;
	LinkedList* test = new LinkedList();

	for (int i = 0; i < 10; i++) {
		cout << "HEAD: " << head << endl;
	 	test->prepend(&head, i + 1);
	}

	test->printList(head);
}

void testDelete() {
	Node* head = nullptr;
	LinkedList* test = new LinkedList();

	for (int i = 0; i < 10; i++) {
		test->prepend(&head, i + 1);
	}

	test->printList(head);

	for (int i = 0; i < 10; i++) {
		test->deletion(&head, i + 1);
	}

	test->printList(head);
}

int main() {
	//testAppend();
	//testPrepend();
	//testDelete();

	LinkedList* linkedList = new LinkedList();
	linkedList->control();
}