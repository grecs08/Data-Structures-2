/*
-------------------------------------
File:    myrecord_sllist.h
Project: grec2740_a05
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-02-17
-------------------------------------
 */
#ifndef SLLIST_H
#define SLLIST_H

typedef struct {
	char name[40];
	float score;
} RECORD;

typedef struct node {
	RECORD data;
	struct node *next;
} NODE;

typedef struct sllist {
	int length;
	NODE *start;
} SLLIST;

NODE *search(SLLIST *sllistp, char *name);
void insert(SLLIST *sllistp, char *name, float score);
int delete(SLLIST *sllistp, char *name);
void clean(SLLIST *sllistp);

#endif
