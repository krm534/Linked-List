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

	test->insert(&head, 200, 1);
	test->insert(&head, 200, 100);

    Node* loopInstance = head;
    while (loopInstance->next != nullptr) {
		loopInstance = loopInstance->next;
	}

    if (head->next->data == 200 && loopInstance->data == 200) {
		return 0;
	} else {
		return 1;
	}
}