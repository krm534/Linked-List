#include "linked-list.h"

// Control function
void LinkedList::control() {
	int linkedListType, stopLoop;

	// Head node
	Node* head = nullptr;

	while (true) {
		std::cout << "Enter 1 to prepend, 2 to append, and 3 to delete." << std::endl;
		std::cin >> linkedListType;

		// Prepend
		if (linkedListType == 1) {
			while (true) {
				std::string prependPrompt = "Enter a number to prepend to linked list.";
				
				if (handleActions(prependPrompt, &head, 1)) {
					continue;
				}
				else {
					break;
				}
			}
		}
		// Append
		else if (linkedListType == 2) {
			while (true) {
				std::string appendPrompt = "Enter a number to append to linked list.";
				
				if (handleActions(appendPrompt, &head, 2)) {
					continue;
				}
				else {
					break;
				}
			}
		}
		// Delete
		else if (linkedListType == 3) {
			while (true) {
				std::string deletionPrompt = "Enter a number to delete from the linked list.";
				
				if (handleActions(deletionPrompt, &head, 3)) {
					continue;
				}
				else {
					break;
				}
			}
		}
		// Exception
		else {
			std::cout << "Error occurred" << std::endl;
		}

		std::cout << "Enter 0 to continue manipulating the linked list or 1 to exit." << std::endl;
		std::cin >> stopLoop;

		if (stopLoop == 0) {
			continue;
		}
		else {
			break;
		}
	}
}

// Handles action function calls
bool LinkedList::handleActions(std::string prompt, Node** head, int type) {
		// Check if linked list is empty
		int stopDelete, number;

		std::cout << prompt << std::endl;
		std::cin >> number;

		// Delete new node
		if (type == 1) {
			prepend(head, number);
		}
		else if (type == 2) {
			append(head, number);
		}
		else {
			deletion(head, number);
		}

		// Print list so far
		printList(*head);

		if (head != nullptr) {
			std::cout << "Enter 0 to delete, prepend, or append another value or 1 to exit." << std::endl;
			std::cin >> stopDelete;

			if (stopDelete == 0) {
				return 1;
			}
			else if (stopDelete == 1) {
				return 0;
			}
			else {
				std::cout << "Error occurred! Invalid command entered!" << std::endl;
				return 0;
			}
		}
		else {
			return 0;
		}
}

// Append Node to Linked List
void LinkedList::append(Node** head, int data) {
	// Allocate new node
	Node* new_node = new Node();

	Node* last = *head;

	// Add data attribute
	new_node->data = data;

	// Add next attribute
	new_node->next = nullptr;

	// If head is null
	if (*head == nullptr) {
		*head = new_node;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	// Change last next to new node
	last->next = new_node;
}

// Prepend Node to Linked List
void LinkedList::prepend(Node** head, int data) {
	// Allocate new node
	Node* prev = new Node();

	// Add next node attribute
	prev->next = NULL;

	// Add data attribute
	prev->data = data;

	// if head is null
	if (*head == nullptr) {
		*head = prev;
		return;
	}

	prev->next = *head;
	*head = prev;
}

// Free Up Node Memory
void LinkedList::freeUpMemory(Node** mem) {
	delete(*mem);
	*mem = nullptr;
}

// Delete Node in Linked List
void LinkedList::deletion(Node** head, int number) {
	Node* last = *head;
	Node* next = nullptr;

	// Check if only one node is in linked list
	if (last->next == nullptr) {
		freeUpMemory(head);
		return;
	}

	// Accomodate for first node deletion
	if (last->data == number) {
		*head = nullptr;

		if (last->next != nullptr) {
			*head = last->next;
		}

		return;
	}

	while (last->next != NULL) {
		next = last->next;
		if (next->data == number) {
			break;
		}
		else {
			last = last->next;
			continue;
		}
	}

	// Rearrange pointers
	if (next->next == NULL) {
		last->next = nullptr;
	}
	else {
		last->next = next->next;
	}

	freeUpMemory(&next);
}

// Print Linked List
void LinkedList::printList(Node* head) {
	Node* n = head;

	if (n == NULL) {
		std::cout << "Empty Linked List" << std::endl;
		return;
	}

	if (n->next == nullptr) {
		// Print last number in linked list
		std::cout << n->data << " -> ";
	}
	else {
		while (n->next != NULL) {
			std::cout << n->data << " -> ";
			n = n->next;
		}
		// Print last number in linked list
		std::cout << n->data << " -> ";
	}

	// Create new line
	std::cout << std::endl;
}