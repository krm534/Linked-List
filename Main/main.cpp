#include <iostream>
#include <string>
#include "../Linked-List/linked-list.h"
#include "../Tests/test.h"

using namespace std;

int main() {
	// Tests
	Test* tests = new Test();
	tests->testAppend();
	tests->testPrepend();
	tests->testDelete();
	tests->testInsertion();

	// Main
	// LinkedList* linkedList = new LinkedList();
	// linkedList->control();
}