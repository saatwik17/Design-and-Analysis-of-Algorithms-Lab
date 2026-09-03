#include <stdio.h>
int main() {
	int m, n, r, p;
	int A[100][100], B[100][100], C[100][100];
	int i, j, k;
	scanf("%d %d", &m, &n);

	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	scanf("%d %d", &r, &p);

	if(n != r) {
		printf("Invalid input");
		return 0;
	}
	for(i = 0; i < r; i++) {
		for(j = 0; j < p; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	for(i = 0; i < m; i++) {
		for(j = 0; j < p; j++) {
			C[i][j] = 0;
		}
	}

	for(i = 0; i < m; i++) {
		for(j = 0; j < p; j++) {
			for(k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for(i = 0; i < m; i++) {
		for(j = 0; j < p; j++) {
			printf("%d", C[i][j]);
			if(j < p - 1)
			printf(" ");
		}
			printf(" \n");
	}

	return 0;
}