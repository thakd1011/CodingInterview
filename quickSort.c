#include <stdio.h>

int list[10] = {7, 9, 2, 5, 11, 0, 2, 13, 3, 4};

void swap(int a, int b){
	int temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}

void quickSort(int list[], int start, int end) {
	if(start < end) {
		int pivot = list[start];
		int left = start+1;
		int right = end;
		do{
			while(list[left] < pivot) {
				left++;
			}
			while(list[right] > pivot) {
				right--;
			}
			if(left < right) {
				swap(left, right);
			}
		}while(left < right);

		swap (start, right);

		quickSort(list, start, right-1);
		quickSort(list, right+1, end);
	}
}


int main() {

	quickSort(list, 0, 9);
	
	//print sorted list
	for(int i=0; i<10; i++){
		printf("%d ", list[i]);
	}
	return 0;
}
