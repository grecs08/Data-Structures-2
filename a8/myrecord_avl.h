/*
-------------------------------------
File:    myrecord_avl.h
Project: grec2740_a08
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-16
-------------------------------------
 */
#ifndef MYRECORD_AVL_H
#define MYRECORD_AVL_H
#include "avl.h"


typedef struct {
	int count;
	float mean;
	float stddev;
	float median;
} STATS;

typedef struct {
	TNODE *root;
	STATS stats;
} AVL;

void merge_tree(TNODE **rootp1, TNODE **rootp2);
void merge_data(AVL *t1, AVL *t2);
void clear_avl(AVL *avl);

#endif
