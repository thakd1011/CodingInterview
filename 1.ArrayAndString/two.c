#include <stdio.h>
// 문자열 두 개가 주어졌을 때,
// 이 둘이 서로 순열 관계에 있는지 확인하라

int main() {
	char str1[101], str2[101];
	int asciiArray[128] = {0,};
	int str1_len = 0, str2_len = 0;

	printf("문자열 두 개를 입력하세요(공백으로 구분)\n");
	scanf("%s %s", str1, str2);

	for(int i=0; str1[i] != '\0'; i++){
		int index = str1[i] - 0;
		asciiArray[index]++;
		str1_len++;
	}
	for(int i=0; str2[i] != '\0'; i++) {
		str2_len++;
	}

	if(str1_len != str2_len) {
		printf("순열관계가 아닙니다.");
		return 0;
	}
	else {
		for(int i=0; i<str2_len; i++) {
			int index = str2[i] - 0;

			asciiArray[index]--;

			if(asciiArray[index] < 0) {
				printf("순열관계가 아닙니다.");
				return 0;
			}
		}
	}
	printf("순열관계입니다.");
}
