/*
-------------------------------------
File:    hash.c
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
#include "hash.h"

extern int htsize;

int hash(char *name) {
	unsigned int value = 0, i;
	char *p = name;
	while (*p) {
		value = 31 * value + *p;
		p++;
	}
	return value % htsize;
}

HASHNODE *new_hashnode(char *name, int value) {

	HASHNODE *hn = (HASHNODE*) malloc(sizeof(HASHNODE));
	strcpy(hn->name, name);
	hn->value = value;
	hn->next = NULL;
	return hn;

}

HASHTABLE *new_hashtable(int size) {

	HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
	ht->hna = (HASHNODE**) malloc(sizeof(HASHNODE**) * size);
	int i;
	for (i = 0; i < size; i++)
		*(ht->hna + i) = NULL;
	ht->size = size;
	ht->count = 0;
	return ht;

}

HASHNODE *search(HASHTABLE *ht, char *name) {

	int i = hash(name);
	HASHNODE *p = ht->hna[i];
	while (p) {
		if (strcmp(p->name, name) == 0) {
			break;
		} else {
			p = p->next;
		}
	}
	return p;

}

int insert(HASHTABLE *ht, HASHNODE *np) {

	int i = hash(np->name);
	HASHNODE *p = ht->hna[i];
	int x = 0;
	int cont = 1;
	if (p) {
		printf("a:%d\n", p == NULL);
		do {
			printf("b:%d\n", p == NULL);
			if (strcmp(p->name, np->name) == 0) {
				x = 1;
				p->value = np->value;
			} else {
				if (p->next != NULL) {
					p = p->next;
				} else {
					cont = 0;
				}
			}
		} while (!x && p && cont);
		if (!x) {
			p->next = np;
			ht->count++;
		}
	} else {
		ht->hna[i] = np;
		ht->count++;
	}

	return !x;

}

int delete(HASHTABLE *ht, char *name) {

	int hashval = hash(name);
	HASHNODE *prev = NULL;
	HASHNODE *node = ht->hna[hashval];

	while (node != NULL && strcmp(name, node->name) != 0) {
		prev = node;
		node = node->next;
	}

	if (node == NULL) {
		return 0;
	} else {
		if (prev == NULL) {
			ht->hna[hashval] = node->next;
		} else {
			prev->next = node->next;
		}
		free(node);
		ht->count--;
		return 1;
	}


}

void clean_hash(HASHTABLE **htp) {
	if (*htp == NULL)
		return;
	HASHTABLE *ht = *htp;
	HASHNODE *sp = ht->hna[0], *p, *temp;
	int i;
	for (i = 0; i < ht->size; i++) {
		p = ht->hna[i];
		while (p) {
			temp = p;
			p = p->next;
			free(temp);
		}
		ht->hna[i] = NULL;
	}
	free(ht->hna);
	ht->hna = NULL;
	*htp = NULL;
}
