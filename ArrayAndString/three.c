#include <stdio.h>
//문자열에 들어있는 모든 공백을 '%20'으로 바꿔주는 메서드를 작성하라.
// 입력:"Mr John Smith", 13
// 출력 : "Mr%20John%20Smith"

char newList[1001]; //1000글자를 넘지 않는다고 가정
char appendList[3] = {'%', '2', '0'};

void changeString(char stringList[], int stringLen) {
	int index = 0;
	int spaceCount = 0;
	
	for(int i=0; i<stringLen; i++) {
		if(stringList[i]==' ') {
			spaceCount++;

			for(int j=0; j<3; j++) {
				newList[index+j] = appendList[j];
			}

			index += 3;
		}
		else {
			newList[index] = stringList[i];
			index++;
		}
	}

	for(int i=0; i<stringLen + 2 * spaceCount; i++) {
		printf("%c", newList[i]);
	}
}

int main() {
	char inputString[1001];
	int inputStringLen;
	
	printf("문자열을 입력하세요.\n");
	scanf("%[^\n]", inputString);
	
	printf("문자열의 길이를 입력하세요.\n");
	scanf("%d", &inputStringLen);

	changeString(inputString, inputStringLen);

}

