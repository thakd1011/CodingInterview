#include <stdio.h>
#include <stdlib.h>

int N = 5;

void rotation90(int** square) {
	int temp_first = 0, temp_second = 0;
	for(int row = 0; row < N/2 + 1; row++) {
		for(int col = row; col < N - row - 1; col++) {
			temp_first = square[row][col];
			square[row][col] = square[N - col - 1][row];

			temp_second = square[col][N - row - 1];
			square[col][N - row - 1] = temp_first;

			temp_first = temp_second;
			temp_second = square[N - row - 1][N - col - 1];

			square[N - row - 1][N - col - 1] = temp_first;
			square[N - col - 1][row] = temp_second;
		}
	}

	printf("rotated = \n");
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ", square[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int **square = (int**)malloc(sizeof(int*) * N);
	int randomInt = 0;

	for(int i=0; i<N; i++) {
		square[i] = (int*)malloc(sizeof(int) * N);
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			randomInt = rand() % 100 + 1;
			square[i][j] = randomInt;
		}
	}

	printf("origin = \n");
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ", square[i][j]);
		}
		printf("\n");
	}


	rotation90(square);
}
