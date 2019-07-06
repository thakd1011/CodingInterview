#include <stdio.h>

void merge(char list[], int start, int middle, int end) {
	char sorted[101];
	int left = start;
	int right = middle+1;
	int index = start;

	while(left <= middle && right <= end) {
		if(list[left] > list[right]) {
			sorted[index++] = list[left++];
		}
		else {
			sorted[index++] = list[right++];
		}
	}
	
	//남은 값들도 마저 복사
	//두 개로 나뉜 배열 중 한 쪽은 끝까지 복사 마쳐진 상태
	if(left > middle) {
		while(right <= end){
			sorted[index++] = list[right++];
		}
	}
	else {
		while(left <= middle) {
			sorted[index++] = list[left++];
		}
	}
	
	//list 배열에 다시 복사
	for(int i=start; i<=end; i++) {
		list[i] = sorted[i];
	}
}

void mergeSort(char list[], int start, int end){
	if(start < end) {
		int middle = (start + end)/2;
		mergeSort(list, start, middle);
		mergeSort(list, middle+1, end);
		merge(list, start, middle, end);
	}
}


int main(void) {
	char str[101];
	int strLen = 0;

	printf("문자열을 입력하세요\n");
	scanf("%s", str);
	
	for(int i=0; str[i] != '\0'; i++) {
		str[i] = str[i] - 0;
		strLen++;
	}

	mergeSort(str, 0, strLen);

	for(int i=0; i<strLen - 1; i++) {
		if(str[i] == str[i+1]) {
			printf("중복있음\n");
			return 0;
		}
	}
	printf("중복없음");

}
