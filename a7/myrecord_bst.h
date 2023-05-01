/*
-------------------------------------
File:    myrecord_bst.h
Project: grec2740_a07
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-10
-------------------------------------
 */
#ifndef MYRECORD_BST_H
#define MYRECORD_BST_H

typedef struct {
	TNODE *root;
} BST;

typedef struct {
	int count;
	float mean;
	float stddev;
	float median;
} STATS;

void add_data(BST *bst, STATS *stats, char *name, float score);
void remove_data(BST *bst, STATS *stats, char *name);
#endif
