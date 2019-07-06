#include <stdio.h>
// 문자열이 주어졌을 때 중복된 문자가 있는 지 확인

int main(void) {
	char str[101]; //최대 100자리라고 가정
	int  asciiArray[128]={0,}; //문자 종류(ASCII Code 기준)
	
	printf("문자열을 입력하세요\n");
	scanf("%s", str);
	for(int i=0; i<10; i++) {
		printf("%c", str[i]);
	}

	// solution 1.
	for(int i = 0; str[i] != '\0'; i++) {
		int index = str[i] - 0;
		
		if(asciiArray[index] != 0) {
			printf("중복 있음");
			return 0;
		}
		else {
			asciiArray[index]++;
		}
	}
	printf("중복 없음");
	
}
