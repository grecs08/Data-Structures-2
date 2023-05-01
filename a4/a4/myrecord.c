/*
-------------------------------------
File:    myrecord.c
Project: grec2740_a04
file description
-------------------------------------
Author:  your name here
ID:      your ID here
Email:   your Laurier email here
Version  2023-02-09
-------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mysort.h"
#include "myrecord.h"

#define MAX_LINE 100

char letter_grade(float s) {
	// your implementation
	char g[] = { 'S', 'A', 'B', 'C', 'D', 'F' };
	float b[] = { 100, 90, 80, 70, 60, 50, 0 };
	int left = 0, right = sizeof(b) / sizeof(float) - 1;
	// binary search for increasing order
	int found = 0;
	while (!found) {
		int center = (right + left) / 2;
		if (s < b[center]) {
			left = center;
		} else {
			right = center;
		}

		if (left == right - 1) {
			found = 1;
		}
	}
	if (right == left)
		return g[left - 1];
	else
		return g[left];
}


STATS process_data(RECORD *dataset, int n) {
	STATS stats = { 0 };
	if (n < 1)
		return stats;

	int count = n;
	stats.count = n;

	float mean = 0;
	for (int i = 0; i < count; i++) {
		vals[i] = dataset[i].score;
		mean += dataset[i].score;
	}
	mean /= count;
	stats.mean = mean;

	float std = 0;
	for (int i = 0; i < count; i++) {
		std += (dataset[i].score - mean) * (dataset[i].score - mean);
	}
	std = sqrtf(std / count);
	stats.stddev = std;

	quick_sort(vals, 0, count - 1);
	float median;
	if (n % 2 == 1) {
		median = vals[count / 2];
	} else {
		median = (vals[count / 2 - 1] + vals[count / 2]) / 2;
	}
	stats.median = median;

	return stats;
}
int import_data(char *infilename, RECORD *records) {
	// your implementation
	FILE *fp = fopen(infilename, "r");
	char delimiters[] = " ,\n\r";
	char line[100];
	int i = 0; // record counter
	char *token = NULL;
	while (fgets(line, sizeof(line), fp) != NULL) {
		token = (char *) strtok(line, delimiters);
		strcpy(records[i].name, token); // copy string char array
		token = (char *) strtok(NULL, delimiters);
		records[i].score = atof(token); // convert string to float
		i++;
	}
	fclose(fp);
	return i;
	}

int report_data(char *outfilename, RECORD *records, STATS stats) {
	STATS stats = { 0 };
	if (n < 1)
		return stats;
	// your implementation
	int count = n;
	;
	stats.count = n;
	float vals[MAX_REC];

	float mean = 0;
	for (int i = 0; i < count; i++) {
		vals[i] = records[i].score;
		mean += records[i].score;
	}
	mean /= count;
	stats.mean = mean;

	float std = 0;
	for (int i = 0; i < count; i++)
		std += (records[i].score - mean) * (records[i].score - mean);
	std = sqrtf(std / count);
	stats.stddev = std;

	quick_sort(vals, 0, count - 1);
	float median;
	if (n % 2 == 1) {
		median = vals[count / 2];
	} else {
		median = (vals[count / 2 - 1] + vals[count / 2]) / 2;
	}
	stats.median = median;

	FILE *fp = fopen(outfilename, "w");
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s,%c\n", records[i].name, letter_grade(records[i].score));
	}
	fclose(fp);

	return stats;
}
