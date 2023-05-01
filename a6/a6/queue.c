/*
-------------------------------------
File:    queue.c
Project: grec2740_a06
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-03-01
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
	np->next = NULL;
	if (qp->front) {
		qp->rear->next = np;
		qp->rear = np;
	} else {
		qp->front = np;
		qp->rear = np;
	}
	qp->length++;
}

NODE *dequeue(QUEUE *qp) {
	NODE *p = qp->front;
	if (p) {
		qp->front = p->next;
		p->next = NULL;
		if (!qp->front) {
			qp->rear = NULL;
		}
		qp->length--;
	} else {
		printf("UNDERFLOW");
	}
	return p;
}

void clean_queue(QUEUE *qp) {
	qp->length = 0;
	if (qp->front) {
		clean(&qp->front);
	}
	qp->front = NULL;
	qp->rear = NULL;
}
