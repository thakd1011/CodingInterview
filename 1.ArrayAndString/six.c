//반복되는 문자의 개수를 세는 방식의 문자열 압축 메서드를 작성하라.
//예를 들어 aabccccaaa 압축하면 a2b1c5a3 출력
//압축된 문자열의 길이가 기존 문자열보다 길다면 기존 문자열을 출력
#include <stdio.h>

int lengthOfZipList(char list[]) {
	int count = 1;
	for(int i=0; list[i+1]!='\0'; i++) {
		if(list[i] != list[i+1]) {
			count++;
		}
	}
	return 2*count;
}

void zipList(char list[]) {
	int originLength = 0;
	int zippedLength = lengthOfZipList(list);

	for(int i=0; list[i] != '\0'; i++) {
		originLength++;
	}
	if(originLength < zippedLength) {
		for(int i=0; list[i] != '\0'; i++) {
			printf("%c", list[i]);
		}
		return;
	}
	else {
		char zippedList[zippedLength];
		char temp = list[0];
		int count = 1, index = 0;

		for(int i=1; list[i]!='\0'; i++) {
			if(list[i] != temp) {
				zippedList[index++] = temp;
				zippedList[index++] = (char)(count+48);
				temp = list[i];
				count = 1;
			}
			else {
				count++;
			}
		}

		zippedList[index++] = temp;
		zippedList[index++] = (char)(count+48);

		for(int i=0; i<zippedLength; i++) {
			printf("%c", zippedList[i]);
		}
	}
}

int main() {
	char list[100];
	scanf("%s", list);

	zipList(list);
}
