/*
-------------------------------------
File:    set_avl.h
Project: grec2740_a08
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-16
-------------------------------------
 */
#ifndef SET_AVL_H
#define SET_AVL_H

typedef struct {
	TNODE *root;
	int size;
} SET;

int size(SET *s);
int contains_element(SET *s, char *e);
void add_element(SET *s, char *e);
void remove_element(SET *s, char *e);
void clear_set(SET *s);

#endif
