//문자열 편집 방법 3가지 : 문자 삽입, 삭제, 교체.
//문자열 두 개가 주어졌을 때, 문자열을 같게 만들기 위한
//편집 횟수가 1회 이내인지 확인하라
#include <stdio.h>
#include <stdbool.h> // bool, true, false 정의된 헤더파일
#include <math.h>

bool checkEditCount(char string1[], char string2[], int string1_len, int string2_len) {
	int flag = 0;
	int cnt = 0;

	if(string1_len == string2_len) { // change alphabet
		for(int i=0; i<string1_len; i++) {
			if(string1[i] != string2[i]) {
				cnt++;
			}
			if(cnt > 1) {
				return false;
			}
		}
		return true;
	}
	else { // insert or delete alphabet
		int firstIndex = 0, secondIndex = 0;
		int maxSize = string1_len > string2_len ? string1_len : string2_len;

		for(int i=0; i<maxSize; i++) {
			if(string1[firstIndex] != string2[secondIndex]) {
				if(string1_len > string2_len) {
					secondIndex--;
				}
				else {
					firstIndex--;
				}
				flag++;
			}
			
			if(flag > 1) {
				return false;
			}

			firstIndex++;
			secondIndex++;
		}
	}
	return true;
}

int main() {
	char string1[100], string2[100];
	int string1_len = 0, string2_len = 0;
	bool check = false;
	
	scanf("%[^,], %[^\n]", string1, string2);

	for(int i=0; string1[i] != '\0'; i++) {
		string1_len++;
	}
	for(int i=0; string2[i] != '\0'; i++) {
		string2_len++;
	}

	if(abs(string1_len - string2_len) > 1) {
		printf("false");
		return false;
	}
	else {
		check = checkEditCount(string1, string2, string1_len, string2_len);
		if(check) {
			printf("true");
		}
		else {
			printf("false");
		}
	}
}
