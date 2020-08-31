#include <stdio.h>
#include "list.h"

int main(int argc, char** argv) {


// Test Code
//////////////////////////////////////

	struct testStruct
	{
		int data;
		char character;
	};
	
	LinkedList* listTest = newLinkedList();
	for (int i = 0; i < 100; i++)
	{
		struct testStruct* test1 = malloc(sizeof(struct testStruct) * 1);
		test1->character = 'a';
		test1->data = i;
		
		LinkedList_add_end(listTest, test1);
		
	}

	for (int i = 0; i < LinkedList_size(listTest); i++)
	{
		struct testStruct* curPtr = LinkedList_getItem(listTest, i);
		printf("%c\n", curPtr->character);
		/*char* curPtr = LinkedList_getItem(listTest, i);
		char cur =(char*)curPtr;
		printf("%c\n", cur);*/

	}
	LinkedList_clear(listTest);

    ///////////////////////////////////////
	
	return 0;
}