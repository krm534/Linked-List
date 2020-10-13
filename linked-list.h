#include <iostream>
#include <string>
#include "Header.h"

class LinkedList {
    public:
        void append(Node** head, int data);
        void prepend(Node** head, int data);
        void freeUpMemory(Node** mem);
        void deletion(Node** head, int number);
        void printList(Node* head);
        void control();
        bool handleActions(std::string prompt, Node** head, int type);
};