#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node_t {
	void* data;
	struct node_t* next;
}node_t;

typedef struct LinkedList {
	struct node_t* head;
}LinkedList;

LinkedList* newLinkedList();
void LinkedList_add_at(LinkedList* list, int index, void* data);
void LinkedList_add_beg(LinkedList* list, void* data);
void LinkedList_add_end(LinkedList* list, void* data);
void LinkedList_removeItem(LinkedList* list, int index);
void* LinkedList_getItem(LinkedList* list, int index);
int LinkedList_size(LinkedList* list);
void LinkedList_clear(LinkedList* list);

#endif
