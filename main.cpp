#include <iostream>
#include "Header.h"

using namespace std;

// Prototypes 
void append(Node**, int);
void prepend(Node**, int);
void freeUpMemory(Node**);
void deletion(Node**, int);
void printList(Node*);
void control();

int main() {
	control();

	system("pause");
}

// Control function
void control() {
	int linkedListType, number, stopAppend, stopPrepend, stopDelete, stopLoop;

	// Head node
	Node* head = nullptr;

	while (true) {
		cout << "Enter 1 to prepend, 2 to append, and 3 to delete." << endl;
		cin >> linkedListType;

		// Prepend
		if (linkedListType == 1) {
			while (true) {
				cout << "Enter a number to prepend to linked list." << endl;
				cin >> number;

				// Prepend new node
				prepend(&head, number);

				// Print list so far
				printList(head);

				cout << "Enter 0 to prepend another value or 1 to exit" << endl;
				cin >> stopPrepend;

				if (stopPrepend == 0) {
					continue;
				}
				else if (stopPrepend == 1) {
					break;
				}
				else {
					cout << "Error occurred" << endl;
				}
			}
		}
		// Append
		else if (linkedListType == 2) {
			while (true) {
				cout << "Enter a number to append to linked list." << endl;
				cin >> number;

				// Append new node
				append(&head, number);

				// Print list so far
				printList(head);

				cout << "Enter 0 to append another value or 1 to exit" << endl;
				cin >> stopAppend;

				if (stopAppend == 0) {
					continue;
				}
				else if (stopAppend == 1) {
					break;
				}
				else {
					cout << "Error occurred" << endl;
				}
			}
		}
		// Delete
		else if (linkedListType == 3) {
			while (true) {

				// Check if linked list is empty
				if (head == nullptr) {
					cout << "Deletion Error: linked list is empty" << endl;
					break;
				}

				cout << "Enter a number to delete from the linked list." << endl;
				cin >> number;

				// Delete new node
				deletion(&head, number);

				// Print list so far
				printList(head);

				if (head != nullptr) {
					cout << "Enter 0 to delete another value or 1 to exit" << endl;
					cin >> stopDelete;

					if (stopDelete == 0) {
						continue;
					}
					else if (stopDelete == 1) {
						break;
					}
					else {
						cout << "Error occurred" << endl;
					}
				}
				else {
					break;
				}
			}
		}
		// Exception
		else {
			cout << "Error occurred" << endl;
		}

		cout << "Enter 0 to continue manipulating the linked list or 1 to exit" << endl;
		cin >> stopLoop;

		if (stopLoop == 0) {
			continue;
		}
		else {
			break;
		}
	}
}

// Append Node to Linked List
void append(Node** head, int data) {
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
void prepend(Node** head, int data) {
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
void freeUpMemory(Node** mem) {
	delete(*mem);
	*mem = nullptr;
}

// Delete Node in Linked List
void deletion(Node** head, int number) {
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
void printList(Node* head) {
	Node* n = head;

	if (n == NULL) {
		cout << "Empty Linked List" << endl;
		return;
	}

	if (n->next == nullptr) {
		// Print last number in linked list
		cout << n->data << " -> ";
	}
	else {
		while (n->next != NULL) {
			cout << n->data << " -> ";
			n = n->next;
		}
		// Print last number in linked list
		cout << n->data << " -> ";
	}

	// Create new line
	cout << endl;
}