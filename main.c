#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print(void* value) {// объявляется переменная-указатель (имя переменной - value; тип данных - void)
	printf("%f\n", *((int*)value));
}

int main(int argc, char** argv) {
	TListItem* list;
	TListItem* item;
	int* data; // объявляется переменная-указатель (data) типа int 
	list = list_create();

	data = (int*)malloc(sizeof(int)); // sizeof(int) – размер одного элемента массива
	*data = 1;  // 
	list_append(list, data);

	data = (int*)malloc(sizeof(int));
	*data = 2;
	list_append(list, data);

	data = (int*)malloc(sizeof(int));
	*data = 3;
	list_append(list, data);

	data = (int*)malloc(sizeof(int));
	*data = 5;
	list_append(list, data);

	data = (int*)malloc(sizeof(int));
	*data = 8;
	list_append(list, data);

	// создаётся односвязный список (1, 2, 3, 5, 8)
	list_traverse(list, print); 
	printf("\n");

	// ищем 5 в списке и удаляем 
	item = list_search(list, 5);
	list_delete(list, item);
	list_traverse(list, print); 
	printf("\n");
	
	// вставляем в список 7 вместо 5 
	item = list_search(list, 3);     
	data = (int*)malloc(sizeof(int));
	*data = 7;
	list_insert(item, data);
	list_traverse(list, print); 
}
