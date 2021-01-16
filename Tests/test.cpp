#include <iostream>
#include <linked-list.h>
#include <Header.h>
#include <cstdlib>

int testAppend() {
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

// void testPrepend() {
//     Node* head = nullptr;
// 	LinkedList* test = new LinkedList();

// 	for (int i = 0; i < 100; i++) {
// 	 	test->prepend(&head, i + 1);
// 	}

// 	test->printList(head);
//     std::cout << "-----------------------" << std::endl;
// }

// void testDelete() {
// 	Node* head = nullptr;
// 	LinkedList* test = new LinkedList();

// 	for (int i = 0; i < 100; i++) {
// 		test->prepend(&head, i + 1);
// 	}

// 	test->printList(head);

// 	for (int i = 0; i < 100; i++) {
// 		test->deletion(&head, i + 1);
// 	}

// 	test->printList(head);
//     std::cout << "-----------------------" << std::endl;
// }

// void testInsertion() {
// 	Node* head = nullptr;
// 	LinkedList* test = new LinkedList();

// 	for (int i = 0; i < 100; i++) {
// 		test->prepend(&head, i + 1);
// 	}

// 	test->insert(&head, 21, 1);
// 	test->insert(&head, 50, 21);
// 	test->insert(&head, 48, 100);
// 	test->insert(&head, 200, 101);

// 	test->printList(head);
//     std::cout << "-----------------------" << std::endl;
// }

int main() {
	return testAppend();
	// testPrepend();
	// testDelete();
	// testInsertion();
}