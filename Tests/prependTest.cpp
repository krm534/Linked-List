#include <iostream>
#include <linked-list.h>
#include <Header.h>
#include <cstdlib>

int main() {
	Node* head = nullptr;
    int counter = 1;
	LinkedList* test = new LinkedList();

	for (int i = 0; i < 100; i++) {
	 	test->prepend(&head, i + 1);
	}

    Node* loopInstance = head;
    while (loopInstance->next != nullptr) {
		loopInstance = loopInstance->next;
		counter++;
	}

	if (head->data == 100 && loopInstance->data == 1 && counter == 100) {
		return 0;
	} else {
		return 1;
	}
}