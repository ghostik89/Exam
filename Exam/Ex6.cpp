#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <ctype.h>

int main() {
	char file[255];
	gets_s(file);

	int N;
	scanf("%d\n", &N);
	if (N < 1 || N > 30) {
		printf("Invalid data\n");
		return 0;
	}

	char Programs[30][255];
	for (int i = 0; i < N; i++)
		gets_s(Programs[i]);



	return 0;
}