#include "linked-list.h"

// Control function
void LinkedList::control() {
	int linkedListType, stopLoop;

	// Head node
	Node* head = nullptr;

	while (true) {
		std::cout << "Enter 1 to prepend, 2 to append, 3 to delete, 4 to insert, and 5 to view list." << std::endl;
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
		// Insert
		else if (linkedListType == 4) {
			while (true) {
				std::string deletionPrompt = "Enter a number to insert into the linked list.";
				
				if (handleActions(deletionPrompt, &head, 4)) {
					continue;
				}
				else {
					break;
				}
			}
		}
		// View
		else if (linkedListType == 5) {
			printList(head);
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
		int stopDelete, number, beforeNumber;

		std::cout << prompt << std::endl;
		std::cin >> number;

		// Delete new node
		if (type == 1) {
			prepend(head, number);
		}
		else if (type == 2) {
			append(head, number);
		}
		else if (type == 3) {
			deletion(head, number);
		}
		else {
			std::cout << "Enter the number in which you want your number to be inserted after." << std::endl;
			std::cin >> beforeNumber;
			insert(head, number, beforeNumber);
		}

		if (*head != nullptr) {
			// Print list so far
			printList(*head);

			std::cout << "Enter 0 to delete, prepend, append, or insert another value or 1 to exit." << std::endl;
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

// Insert Node between two numbers in Linked List
void LinkedList::insert(Node** head, int newNumber, int beforeNumber) {
	Node* last = *head;

	if (last == nullptr) {
		std::cout << "Empty Linked List" << std::endl;
		return;
	}

	while (true) {
		if (last == nullptr) {
			break;
		}
		
		if (last->data == beforeNumber) {
			Node* newNode = new Node();
			newNode->data = newNumber;

			if (last->next == nullptr) {
				newNode->next = nullptr;
			} else {
				newNode->next = last->next;
			}

			last->next = newNode;

			if (beforeNumber == newNumber) {
				last = last->next->next;
				continue;
			}
		}
		
		last = last->next;
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

	// Check if any node exists in linked list
	if (last == NULL) {
		std::cout << "Empty Linked List" << std::endl;
		return;
	}

	// Check if only one node is in linked list
	if (last->next == nullptr) {
		freeUpMemory(head);
		return;
	}

	// Check if node to delete is first node
	if (last->data == number) {
		*head = last->next;
		freeUpMemory(&last);
		return;
	}

	// Loop through and find node to delete
	while (last->next != nullptr) {
		next = last->next;
		if (next->data == number) {
			if (next->next == nullptr) {
				last->next = nullptr;
			} else {
				last->next = next->next;
			}
			freeUpMemory(&next);
		}
		else {
			last = last->next;
			continue;
		}
	}
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