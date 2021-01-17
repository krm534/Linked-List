#include <iostream>
#include <linked-list.h>
#include <Header.h>
#include <cstdlib>

int main() {
	Node* head = nullptr;
	LinkedList* test = new LinkedList();

	for (int i = 0; i < 100; i++) {
		test->prepend(&head, i + 1);
	}

	test->printList(head);

	for (int i = 0; i < 100; i++) {
		test->deletion(&head, i + 1);
	}

	if (head == nullptr) {
		return 0;
	} else {
		return 1;
	}
}