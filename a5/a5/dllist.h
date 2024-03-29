/*
-------------------------------------
File:    dllist.h
Project: grec2740_a05
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-02-17
-------------------------------------
 */
#ifndef DLLIST_H
#define DLLIST_H

typedef struct node {
	char data;
	struct node *prev;
	struct node *next;
} NODE;

typedef struct dllist {
	int length;
	NODE *start;
	NODE *end;
} DLLIST;

NODE *new_node(char value);
void clean(DLLIST *dllistp);
void insert_start(DLLIST *dllistp, NODE *np);
void insert_end(DLLIST *dllistp, NODE *np);
void delete_start(DLLIST *dllistp);
void delete_end(DLLIST *dllistp);

#endif
