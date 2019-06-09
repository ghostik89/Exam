#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int summColumn(int matrix[20][20], int N, int M, int index) {
	int summ;

	summ = 0;
	for (int i = 0; i < N; i++)
		summ += matrix[i][index];

	return summ;
}

void swapColumn(int matrix[20][20], int N, int M, int index1, int index2) {
	int temp;

	for (int i = 0; i < N; i++) {
		temp = matrix[i][index1];
		matrix[i][index1] = matrix[i][index2];
		matrix[i][index2] = temp;
	}
	
}

int main() {
	int A[20][20];
	int N, M;

	scanf("%d %d\n", &N, &M);
	if (N < 1 || N > 20) {
		printf("Invalid data\n");
		return 0;
	}
	if (M < 1 || M > 20) {
		printf("Invalid data\n");
		return 0;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &A[i][j]);

	int SummColumns[20];
	for (int i = 0; i < N; i++) 
		SummColumns[i] = summColumn(A, N, M, i);

	for (int i = 0; i < M; i++)
		for (int j = M - 1; j > i; j--) {
			if (SummColumns[j - 1] > SummColumns[j]) {
				int temp = SummColumns[j - 1];
				SummColumns[j - 1] = SummColumns[j];
				SummColumns[j] = temp;
				swapColumn(A, N, M, j - 1, j);
			}
		}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}

	return 0;
}