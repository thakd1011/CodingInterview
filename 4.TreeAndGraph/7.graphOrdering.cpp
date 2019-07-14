#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

#define MAXSIZE 10

int GRAPH[MAXSIZE][MAXSIZE];
int visited[MAXSIZE];

int main(const int argc, const char* argv[]) {
	if(argc < 2) {
		cout << "more input plz\n";
		exit(1);
	}

	int nodeCount = argc - 1;
	char start, dest;
	int s, d;
	queue <int> q;

	do{
		scanf("\n%c %c", &start, &dest);
		
		s = start - 'a';
		d = dest - 'a';

		GRAPH[s][d] = 1;
		cout << "s = " << s << ", d = " << d<<"\n";
	}while(s >= 0 && d >= 0);

	// check all zero column
	for(int i = 0; i < nodeCount; i++) { // col
		bool zero = true;
		for(int j = 0; j < nodeCount; j++) { // row
			if(GRAPH[j][i] == 1) {
				zero = false;
				break;
			}
		}

		if(zero == true) {
			visited[i] = 1;
			q.push(i);
		}
	}

	while(!q.empty()) {
		int temp = q.front();
		cout << temp << "\t";
		q.pop();

		for(int i=0; i<nodeCount; i++) {
			if(GRAPH[temp][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}
