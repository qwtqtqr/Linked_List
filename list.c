#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LinkedList* newLinkedList() {
	LinkedList* list = malloc(sizeof(LinkedList) * 1);
	list->head = NULL;
	return list;
}

void LinkedList_add_at(LinkedList* list, int index, void* data) {
	node_t* node = malloc(sizeof(node_t) * 1);
	node->data = data;
	node->next = NULL;

	if (list->head == NULL) {
		list->head = node;
		return;
	}
	int idx = 0;

	node_t* prev = NULL;
	node_t* cur = list->head;

	while (cur != NULL && idx != index)
	{
		idx++;
		prev = cur;
		cur = cur->next;
	}

	if (idx == 0)
	{
		list->head = node;
		node->next = cur;
		return;
	}

	if (cur == NULL)
	{
		prev->next = node;
		return;
	}
}

void LinkedList_add_beg(LinkedList* list, void* data) {
	LinkedList_add_at(list, 0, data);
}

void LinkedList_add_end(LinkedList* list, void* data) {
	LinkedList_add_at(list, -1, data);
}

void LinkedList_removeItem(LinkedList* list, int index) {
	node_t* head = list->head;
	node_t* temp = head;
	int idx = 0;

	if (index > 0)
	{
		node_t* prev = NULL;
		node_t* next = NULL;


		while (temp != NULL)
		{
			if (idx == index - 1)
			{
				prev = temp;
			}

			if (idx == index + 1)
			{
				next = temp;
			}
			temp = temp->next;
			idx++;
		}
		prev->next = next;
	}
	
	if (index == 0)
	{
		
		temp = temp->next;
		head = temp;
	}
}

int LinkedList_size(LinkedList* list) {
	node_t* temp = list->head;
	int idx = 0;
	while (temp != NULL) {
		idx++;
		temp = temp->next;
	}
	return idx;
}

void* LinkedList_getItem(LinkedList* list, int index){
	node_t* head = list->head;
	node_t* temp = head;
	int idx = 0;
	while (idx < index)
	{
		idx++;
		temp = temp->next;
	}
	return temp->data;
}

void LinkedList_clear(LinkedList* list) {
	list->head = NULL;
}
