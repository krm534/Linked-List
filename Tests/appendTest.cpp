#include <iostream>
#include <linked-list.h>
#include <Header.h>
#include <cstdlib>

int main() {
	Node* head = nullptr;
	int counter = 1;
	LinkedList* test = new LinkedList();

	for (int i = 0; i < 100; i++) {
	 	test->append(&head, i + 1);
	}

	test->printList(head);

	Node* loopInstance = head;
	while (loopInstance->next != nullptr) {
		loopInstance = loopInstance->next;
		counter++;
	}

	if (head->data == 1 && loopInstance->data == 100 && counter == 100) {
		return 0;
	} else {
		return 1;
	}
}