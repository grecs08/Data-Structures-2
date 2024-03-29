/*
-------------------------------------
File:    heap.c
Project: grec2740_a09
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-29
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

//helper swap function
void heap_swap(HEAPNODE *a, HEAPNODE *b) {
	HEAPNODE temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

HEAP *new_heap(int capacity) {
// your implementation
	HEAP *hp = (HEAP *) malloc(sizeof(HEAP));
	hp->capacity = capacity;
	hp->size = 0;
	hp->hna = (HEAPNODE*) malloc(sizeof(HEAPNODE) * capacity);
	return hp;
}

//heapify up starting from a
int heapify_up(HEAP *source, int a) {
	HEAPNODE *p = source->hna;

	int i = a;
	int j = (i - 1) / 2;

	while (i != 0) {
		if (cmp((p + j)->key, (p + i)->key) == 1) {
			heap_swap((p + j), (p + i));
			i = j;
			j = (i - 1) / 2;
		} else {
			break;
		}
	}
	return i;
}

//helper heapify function starting from a
int heapify_down(HEAP *source, int a) {
	HEAPNODE *p = source->hna;

	int i = a;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int j;

	while (i < source->size) {
		if (r >= source->size) {
			if (l >= source->size) {
				break;
			} else {
				j = l;
			}
		} else {
			j = (cmp((p + l)->key, (p + r)->key) == -1) ? l : r;
		}

		if (cmp((p + j)->key, (p + i)->key) == -1) {
			heap_swap((p + j), (p + i));
			i = j;
			l = 2 * i + 1;
			r = 2 * i + 2;
		} else {
			break;
		}
	}
	return i;
}

void insert(HEAP *heap, HEAPNODE new_node) {

	if (heap->size == heap->capacity) {
		heap->capacity *= 2;
		void * temp = realloc(heap->hna, sizeof(HEAPNODE) * heap->capacity);
		if (temp) {
			heap->hna = temp;
		} else {
			temp = malloc(sizeof(HEAPNODE) * heap->capacity);
			if (temp) {
				memcpy(temp, heap->hna, sizeof(HEAPNODE) * heap->size);
				free(heap->hna);
				heap->hna = temp;
			} else {
				printf("array resize failed\n");
			}
		}
	}

	HEAPNODE *p = heap->hna;
	*(p + heap->size) = new_node;
	heap->size++;
	heapify_up(heap, heap->size - 1);
	return;
}

void display_heap2(HEAP *hp) {
	printf("\nsize:%d\ncapacity:%d\n", hp->size, hp->capacity);
	printf("(index,key,data):");
	int i;
	for (i = 0; i < hp->size; i++) {
		printf("(%d,%d,%d) ", i, hp->hna[i].key, hp->hna[i].data);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}

HEAPNODE extract_min(HEAP *heap) {

	HEAPNODE *p = heap->hna;
	heap_swap(p, p + heap->size - 1);
	HEAPNODE res = *(p + heap->size - 1);
	heap->size--;

	heapify_down(heap, 0);

	if (heap->size <= heap->capacity / 4) {
		heap->capacity /= 2;
		void* temp = realloc(heap->hna, sizeof(HEAPNODE) * heap->capacity);
		if (temp) {
			heap->hna = temp;
		} else {
			temp = malloc(sizeof(HEAPNODE) * heap->capacity);
			if (temp) {
				memcpy(temp, heap->hna, sizeof(HEAPNODE) * heap->size);
				free(heap->hna);
				heap->hna = temp;
			} else {
				printf("array resize failed\n");
			}
		}
	}

	return res;
}


int change_key(HEAP *heap, int index, KEYTYPE new_key) {
	HEAPNODE *p = heap->hna;
	KEYTYPE old_key = (p + index)->key;
	(p + index)->key = new_key;


	int i;
	if (index == 0) {
		i = heapify_down(heap, 0);
	} else if (index == heap->size - 1) {
		i = heapify_up(heap, heap->size - 1);
	} else {
		if (cmp(old_key, new_key) == -1) {
			i = heapify_down(heap, index);
		} else if (cmp(old_key, new_key) == 1) {
			i = heapify_up(heap, index);
		} else {
			i = index;
		}
	}
	return i;
}

int find_data_index(HEAP *heap, DATA data) {
	HEAPNODE *p = heap->hna;
	int i = 0;

	while (i < heap->size) {
		if ((p + i)->data == data) {
			break;
		} else {
			i++;
		}
	}

	return i;
}

int cmp(KEYTYPE a, KEYTYPE b) {
	if (a < b) {
		return -1;
	} else if (a > b) {
		return 1;
	} else {
		return 0;
	}
}
