#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <ctype.h>

int strToWords(char str[255], char words[255][255]) {
	char sep[10] = " ";//separators
	char* istr;//строка, в которой хранится слово

	istr = strtok(str, sep);
	int counter = 0;
	while (istr != NULL) {
		strcpy(words[counter++], istr);

		istr = strtok(NULL, sep);
	}

	return counter;
}

int main() {
	char enter[255];
	char words[255][255];
	int counter;

	gets_s(enter);
	counter = strToWords(enter, words);
	for (int i = 0; i < counter; i++)
		_strrev(words[i]);
	strcpy(enter, strcat( words[0], " "));
	for (int i = 1; i < counter; i++)
		strcat(enter, strcat(words[i], " "));
	puts(enter);

	return 0;
}