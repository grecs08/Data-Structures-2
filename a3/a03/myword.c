/*
-------------------------------------
File:    myword.c
Project: grec2740_a03
file description
-------------------------------------
 Author:  Andrew Greco
 ID:      210422740
 Email:   grec2740@mylaurier.ca
Version  2023-02-01
-------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"


int process_word(char *filename, WORD *words, WORDSTATS *wordstats) {
	FILE *file;
	char line[MAX_LINE_LEN];
	char *token;
	const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";
	int i, j;
	int word_exist;

	file = fopen(filename, "r");
	if (file == NULL) {
		return 1;
	}

	wordstats->line_count = 0;
	wordstats->total_word_count = 0;
	wordstats->distinct_word_count = 0;

	while (fgets(line, MAX_LINE_LEN, file) != NULL) {
		wordstats->line_count++;
		token = strtok(line, delimiters);
		while (token != NULL) {
			str_trim(token);
			lower_case(token);
			word_exist = 0;
			for (i = 0; i < wordstats->distinct_word_count; i++) {
				if (strcmp(token, words[i].word) == 0) {
					words[i].frequency++;
					word_exist = 1;
					break;
				}
			}
			if (!word_exist) {
				strcpy(words[wordstats->distinct_word_count].word, token);
				words[wordstats->distinct_word_count].frequency = 1;
				wordstats->distinct_word_count++;
			}
			wordstats->total_word_count++;
			token = strtok(NULL, delimiters);
		}
	}

	fclose(file);
	return 0;
}

int save_file(char *filename, WORD *words, WORDSTATS *wordstats) {
	FILE *file;
	int i;

	file = fopen(filename, "w");
	if (file == NULL) {
		return 1;
	}

	fprintf(file, "Line Count: %d\n", wordstats->line_count);
	fprintf(file, "Total Word Count: %d\n", wordstats->total_word_count);
	fprintf(file, "Distinct Word Count: %d\n\n",
			wordstats->distinct_word_count);
	fprintf(file, "Distinct Words and Their Frequencies:\n");

	for (i = 0; i < wordstats->distinct_word_count; i++) {
		fprintf(file, "%s: %d\n", words[i].word, words[i].frequency);
	}

	fclose(file);
	return 0;
}
