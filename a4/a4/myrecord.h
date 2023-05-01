/*
-------------------------------------
File:    myrecord.h
Project: grec2740_a04
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-02-09
-------------------------------------
 */
#ifndef MYRECORD_H
#define MYRECORD_H

typedef struct {
	char name[40];
	float score;
} RECORD;

typedef struct {
	int count;
	float mean;
	float stddev;
	float median;
} STATS;

char letter_grade(float score);
int import_data(char *infilename, RECORD *records);
STATS process_data(RECORD *records, int count);
int report_data(char *outfilename, RECORD *records, STATS stats);

#endif
