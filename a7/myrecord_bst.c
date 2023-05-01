/*
-------------------------------------
File:    myrecord_bst.c
Project: grec2740_a07
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-10
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_data(BST *bst, STATS *stats, char *name, float score) {
	if (search(stats->root, name) == NULL) {
		insert(&stats->root, name, score);
		int n = stats->count;
		stats->count += 1;
		float mean = stats->mean;
		stats->mean = ((float) 1 / ((float) n + (float) 1))
				* ((float) n * (float) mean + score);
		/*printf("mean: %f(s), %f\n", score, stats->mean);
		 printf("%f\n", ((float)1/((float)n+(float)1)));
		 printf("%d:", n+1);
		 printf("%f\n", 1/(n+1));
		 printf("%f\n", (n*mean + score));*/
		float stddev = stats->stddev;
		stats->stddev = sqrtf(
				((float) 1 / ((float) n + (float) 1))
						* ((float) n * (stddev * stddev + mean * mean)
								+ (score * score))
						- (stats->mean * stats->mean));
		//printf("stddev: %f\n", stats->stddev);
	}
}

void remove_data(BST *bst, STATS *stats, char *name) {
	TNODE *p = search(stats->root, name);
	if (p != NULL) {
		float score = p->data.score;
		delete(&(stats->root), name);
		int count = stats->count;
		float mean = stats->mean;
		float stddev = stats->stddev;
		stats->count = count - 1;
		stats->mean = ((float) 1 / (float) (stats->count))
				* ((float) count * mean - score);
		stats->stddev = sqrtf(
				((float) 1 / (float) (stats->count))
						* ((float) count * (stddev * stddev + mean * mean)
								- (score * score))
						- (stats->mean * stats->mean));
	}
}
