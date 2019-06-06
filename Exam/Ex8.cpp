#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <ctype.h>

struct File {
	char way[255];
	char file[255];
};

bool SearchDuplicate(File files[30], char* current, const int elemCount) {
	bool HaveDuplicates;

	HaveDuplicates = false;
	for (int i = 0; i < elemCount; i++)
		if (!strcmp((const char*)files[i].file, current))
			HaveDuplicates = true;
	return HaveDuplicates;
}

int main() {

	File files[30];
	int N;

	scanf("%d\n", &N);
	if (N < 1 || N > 30) {
		printf("Invalid data\n");
		return 0;
	}

	int currentCount = 0;
	bool NoSolustion = true;
	bool HaveDuplicate = false;
	char tempEnter[255];
	for (int i = 0; i < N; i++) {
		gets_s(tempEnter);
		char* temp = strrchr(tempEnter, '\\');
		if (currentCount > 0 && temp != NULL) HaveDuplicate = SearchDuplicate(files, temp, currentCount);
		if (HaveDuplicate) NoSolustion = false;
		if (temp != NULL && (HaveDuplicate || i == 0)) {
			strcpy(files[currentCount].way, tempEnter);
			strcpy(files[currentCount].file, temp);
			currentCount++;
		}
	}


	if (NoSolustion)
		puts("no solution");
	else
		for (int i = 0; i < currentCount; i++)
			puts(files[i].way);

	return 0;
}