/*
-------------------------------------
File:    myrecord_avl.c
Project: grec2740_a08
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-16
-------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "avl.h"
#include "myrecord_avl.h"

void merge_tree(TNODE **rootp1, TNODE **rootp2) {
	QUEUE q = { 0 };
	TNODE *p;
	enqueue(&q, *rootp2);
	while (q.front != NULL) {
		p = dequeue(&q);
		if (p->left)
			enqueue(&q, p->left);
		if (p->right)
			enqueue(&q, p->right);

		RECORD r = p->data;
		insert_avl(rootp1, r.name, r.score);
	}
}

void merge_data(AVL *t1, AVL *t2) {
	merge_tree(&t1->root, &t2->root);

	float count1 = (float) t1->stats.count;
	float count2 = (float) t2->stats.count;
	float count = count1 + count2;
	float mean1 = t1->stats.mean;
	float mean2 = t2->stats.mean;
	t1->stats.count = t1->stats.count + t2->stats.count;
	t1->stats.mean = (t1->stats.mean * (float) count1
			+ t2->stats.mean * (float) t2->stats.count)
			/ (float) t1->stats.count;
	t1->stats.stddev = sqrtf(
			(1 / count)
					* (t1->stats.stddev * t1->stats.stddev * count1
							+ mean1 * mean1 * count1
							+ t2->stats.stddev * t2->stats.stddev * count2
							+ mean2 * mean2 * count2)
					- (t1->stats.mean * t1->stats.mean));
}

void clear_avl(AVL *avl) {
	TNODE *root = avl->root;
	clear_tree(&root);
	avl->root = NULL;
	avl->stats.count = 0;
	avl->stats.mean = 0;
	avl->stats.stddev = 0;
	avl->stats.median = 0;
}
