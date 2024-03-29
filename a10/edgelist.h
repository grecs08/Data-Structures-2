/*
-------------------------------------
File:    edgelist.h
Project: grec2740_a10
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-04-06
-------------------------------------
 */

#ifndef EDGELIST_H
#define EDGELIST_H

typedef struct edge {
	int from;
	int to;
	int weight;
	struct edge *next;
} EDGE;

typedef struct edgelist {
	int size;
	EDGE *start;
	EDGE *end;
} EDGELIST;

EDGELIST *new_edgelist();
void add_edge_end(EDGELIST *g, int from, int to, int weight);
void add_edge_start(EDGELIST *g, int from, int to, int weight);
int weight_edgelist(EDGELIST *g);
void clean_edgelist(EDGELIST **gp);
void display_edgelist(EDGELIST *g);

#endif
