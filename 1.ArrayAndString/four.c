#include <stdio.h>
// 회문 순열 : 주어진 문자열이 회문(palindrome)의 순열인지 확인
// 회문이란 앞으로 읽나 뒤로 읽나 같은 단어 혹은 구절을 의미
// 순열이란 문자열을 재배치하는 것을 의미

void bigToSmall(char list[]) {
	for(int i=0; list[i] != '\0'; i++) {
		if(list[i]== ' ') {
			continue;
		}
		else {
			if(list[i] - 'a' < 0) {
				list[i] += 32; //'A' to 'a'
			}
		}
	}
}

int main() {
	int cnt;
	char list[101], alphabet[26] = {0,};
	
	scanf("%[^\n]", list);

	bigToSmall(list);

	for(int i=0; list[i] != '\0'; i++) {
		if(list[i] == ' ') {
			continue;
		}
		int index = list[i] - 'a';
		alphabet[index]++;
	}

	for(int i=0; i<26; i++) {
		if(alphabet[i] % 2 == 1) {
			cnt++;
		}
		if(cnt > 1) {
			printf("False");
			return 0;
		}
	}
	printf("True");
}
