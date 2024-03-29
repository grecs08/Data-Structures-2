/*
-------------------------------------
File:    graph.h
Project: grec2740_a10
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-04-06
-------------------------------------
 */
#ifndef GRAPH_H
#define GRAPH_H

#define INFINITY 99999

typedef struct adjnode {
	int nid;
	int weight;
	struct adjnode *next;
} ADJNODE;

typedef struct gnode {
	int nid;
	ADJNODE *neighbor;
} GNODE;

typedef struct graph {
	int order;
	int size;
	GNODE **nodes;
} GRAPH;

GRAPH *new_graph(int n);
void add_edge(GRAPH *g, int from, int to, int weight);
int get_weight(GRAPH *g, int from, int to);
void clean_graph(GRAPH **gp);
void display_bforder(GRAPH *g, int start);
void display_dforder(GRAPH *g, int start);
void display_graph(GRAPH *g);
#endif
