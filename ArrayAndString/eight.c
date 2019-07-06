/*
0행렬 : MXN 행렬의 한 원소가 0일 경우
해당 원소가 속한 행과 열의 모든 원소를 0으로 설정하라
*/

/*
//시간복잡도 - O(N*M), 공간복잡도 - O(N)
//step 1. check zero location
//step 2. set zero specific row & column
*/

#include <stdio.h>
#include <stdlib.h> //rand()

int M = 6, N = 9;

void setZero(int **randomArr) {
	// randomArr 배열의 첫번째 행과 열을 check array로 사용하면
	// 공간복잡도를 줄일 수 있다.  O(N) -> O(1)
	int *row = (int*)malloc(sizeof(int) * M);
	int *col = (int*)malloc(sizeof(int) * N);

	// init row, col array
	for(int i=0; i < M; i++) {
		row[i] = 0;
	}
	for(int j=0; j < N; j++) {
		col[j] = 0;
	}
	
	// check zero location
	for(int i = 0; i<M; i++) {
		for(int j = 0; j<N; j++) {
			if(randomArr[i][j] == 0) {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	

	// TODO : make setZero function
	for(int i = 0; i < M; i++) {
		if(row[i]) {
			for(int j = 0; j< N; j++) {
				randomArr[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < N; i++) {
		if(col[i]) {
			for(int j = 0; j< M; j++) {
				randomArr[j][i] = 0;
			}
		}
	}
}

int main() {
	int **randomArr = (int**)malloc(sizeof(int*) * M);

	for(int i=0; i<M; i++) {
		randomArr[i] = (int*)malloc(sizeof(int) * N);
	}

	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			randomArr[i][j] = rand() % 30;
		}
	}
	
	printf("Before\n");
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ", randomArr[i][j]);
		}
		printf("\n");
	}

	setZero(randomArr);

	printf("After\n");
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ", randomArr[i][j]);
		}
		printf("\n");
	}

}
