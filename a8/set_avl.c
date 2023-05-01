/*
-------------------------------------
File:    set_avl.c
Project: grec2740_a08
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-16
-------------------------------------
 */

#include "avl.h"
#include "set_avl.h"
#include <stddef.h>

int size(SET *s) {
	return s->size;
}

int contains_element(SET *s, char *e) {
	return (search_avl(s->root, e)) ? 1 : 0;
}

void add_element(SET *s, char *e) {
	if (contains_element(s, e) == 0) {
		s->size++;
		insert_avl(&s->root, e, 0);
	}

}

void remove_element(SET *s, char *e) {
	s->size--;
	delete_avl(&s->root, e);
}

void clear_set(SET *s) {
	s->size = 0;
	s->root = NULL;
}
