#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <ctype.h>

int main() {
	char Folders[30][255];
	int N;
	scanf("%d\n", &N);

	char tempstr[255];
	int counter = 0;
	bool NoSolution = true;
	for (int i = 0; i < N; i++) {
		gets_s(tempstr);
		char* firstptr = strchr(tempstr, '\\');
		char* secondptr = strchr((firstptr + 1), '\\');

		if (firstptr != NULL) {
			if (secondptr == NULL) {
				char* pointptr = strrchr((firstptr + 1), '.');
				if (pointptr == NULL && strlen(tempstr) > 3) {
					strcpy(Folders[counter], tempstr);
					counter++;
					NoSolution = false;
				}
			}
			else {
				strncpy(Folders[counter], tempstr, secondptr - tempstr);
				Folders[counter][secondptr - tempstr] = '\0';
				counter++;
				NoSolution = false;
			}
		}

	}

	if (NoSolution)
		printf("no solution\n");
	else
		for (int i = 0; i < counter; i++)
			puts(Folders[i]);

	return 0;
}