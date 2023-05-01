/*
 ============================================================================
 Name        : grec2740_a05.c
 Author      : HBF
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myrecord_sllist.h"

NODE *search(SLLIST *sllistp, char *name) {
	NODE *p = sllistp->start;
	while (p != NULL) {
		if (strcmp(p->data.name, name) == 0) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void insert(SLLIST *sllistp, char *name, float score) {
	NODE *newnode = (NODE *) malloc(sizeof(NODE));
	strcpy(newnode->data.name, name);
	newnode->data.score = score;
	newnode->next = sllistp->start;
	sllistp->start = newnode;
	sllistp->length++;
}

int delete(SLLIST *sllistp, char *name) {
	NODE *p = sllistp->start;
	NODE *prev = NULL;
	while (p != NULL) {
		if (strcmp(p->data.name, name) == 0) {
			if (prev == NULL) {
				sllistp->start = p->next;
			} else {
				prev->next = p->next;
			}
			free(p);
			sllistp->length--;
			return 1;
		}
		prev = p;
		p = p->next;
	}
	return 0;
}

void clean(SLLIST *sllistp) {
	NODE *p = sllistp->start;
	while (p != NULL) {
		NODE *temp = p;
		p = p->next;
		free(temp);
	}
	sllistp->length = 0;
	sllistp->start = NULL;
}
