#include <stdlib.h>
#include "list.h"

TListItem* list_create(){ 
	TListItem* item;
	item = (TListItem*)malloc(sizeof(TListItem));
	if (item != NULL){
		(*item).data = NULL;
		(*item).next = NULL;
	}
	return item;
}

// добавляет элемент в список
TListItem* list_append(TListItem* head, void* data){
	TListItem* item;
	while ((*head).next != NULL){
		head = (*head).next;
	}
	item = (TListItem*)malloc(sizeof(TListItem));
	if (item != NULL){
		(*item).data = data;
		(*item).next = NULL;

		(*head).next = item;
	}

	return item;
}

void list_traverse(TListItem* head, TFunc f){
	head = head->next;
	while (head != NULL){
		f(head->data);
		head = head->next;
	}
}

//удаляет из памяти список
void list_free(TListItem** head){
	TListItem* ptr;
	TListItem* next;
	ptr = *head;
	while (ptr != NULL){
		next = (*ptr).next;
		if (ptr->data != NULL)
		free(ptr->data);
		free(ptr);
		ptr = next;
	}
	*head = NULL;
}

//ищет в списке элемент со значением needle, возвращает указатель на первый найденный, либо NULL
TListItem* list_search(TListItem* head, int needle){
	while (head != NULL){
		if ((head->data != NULL) && (*(int*)head->data == needle)){
			return head;
		}
		head = head->next;
	}
	return NULL;
}

//удаляет из списка элемент item
void* list_delete(TListItem* head, TListItem* item){
	while ((head != NULL) && (head->next != item)){
		head = head->next;
	}
	if (head){
		head->next = item->next;
		// освободим память
		free(item->data); 
		free(item);
	}
}

//создает в памяти новый элемент и вставляет его после заданного
TListItem* list_insert(TListItem* item, void* data){
	TListItem* ptr = (TListItem*)malloc(sizeof(TListItem));
	ptr->data = data;
	ptr->next = item->next;
	item->next = ptr;
	return ptr;
}
