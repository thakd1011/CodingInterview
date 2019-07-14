#include <stdio.h>
#include <stdlib.h> //rand()

// 시간복잡도 : O(N^2)
// 공간복잡도 : O(N^2)

int N = 6;

void rotation90(int **square, int **newSquare) {
	printf("rotated = \n");
	for(int row=0; row<N; row++) {
		for(int col = 0; col<N; col++) {
			newSquare[row][col] = square[N - col - 1][row];
			printf("%d ",newSquare[row][col]);
		}
		printf("\n");
	}
}

int main() {
	int randomInt = 0;
	int **square = (int**)malloc(sizeof(int*) * N); //row = N
	int **newSquare = (int**)malloc(sizeof(int*) * N);

	for(int i=0; i<N; i++) {
		square[i] = (int*)malloc(sizeof(int) * N); //col = N
		newSquare[i] = (int*)malloc(sizeof(int) * N);
	}
	
	printf("square = \n");
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			randomInt = rand() % 100 + 1;
			square[i][j] = randomInt;
			printf("%d ", square[i][j]);
		}
		printf("\n");
	}

	rotation90(square, newSquare);
}
