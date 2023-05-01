/*
-------------------------------------
File:    dllist.c
Project: grec2740_a05
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-02-17
-------------------------------------
 */

/*
 * dllist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

NODE *new_node(char data) {
	NODE *np = malloc(sizeof(NODE));
	if (np != NULL) {
		np->data = data;
		np->prev = NULL;
		np->next = NULL;
	}
	return np;
}

void clean(DLLIST *dllistp) {
	NODE *np = dllistp->start;
	while (np != NULL) {
		NODE *temp = np;
		np = np->next;
		free(temp);
	}
	dllistp->start = NULL;
	dllistp->end = NULL;
	dllistp->length = 0;
}

void insert_start(DLLIST *dllistp, NODE *np) {
	np->prev = NULL;
	np->next = dllistp->start;
	if (dllistp->start != NULL) {
		dllistp->start->prev = np;
	}
	dllistp->start = np;
	if (dllistp->end == NULL) {
		dllistp->end = np;
	}
	dllistp->length++;
}

void insert_end(DLLIST *dllistp, NODE *np) {
	np->prev = dllistp->end;
	np->next = NULL;
	if (dllistp->end != NULL) {
		dllistp->end->next = np;
	}
	dllistp->end = np;
	if (dllistp->start == NULL) {
		dllistp->start = np;
	}
	dllistp->length++;
}

void delete_start(DLLIST *dllistp) {
	if (dllistp->start != NULL) {
		NODE *np = dllistp->start;
		dllistp->start = np->next;
		if (dllistp->start != NULL) {
			dllistp->start->prev = NULL;
		}
		if (np == dllistp->end) {
			dllistp->end = NULL;
		}
		free(np);
		dllistp->length--;
	}
}

void delete_end(DLLIST *dllistp) {
	if (dllistp->end != NULL) {
		NODE *np = dllistp->end;
		dllistp->end = np->prev;
		if (dllistp->end != NULL) {
			dllistp->end->next = NULL;
		}
		if (np == dllistp->start) {
			dllistp->start = NULL;
		}
		free(np);
		dllistp->length--;
	}
}
