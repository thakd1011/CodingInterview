// Exercise1. Check start node and destination node! Make sure there's a route?
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

#define GRAPHSIZE 10

int visited[GRAPHSIZE];
int graph[GRAPHSIZE][GRAPHSIZE];

bool checkRoute(int start, int dest) {
	for(int i=0; i<GRAPHSIZE; i++) {
		if((!visited[i]) && graph[start][i] == 1) {
			visited[i] = 1;
			checkRoute(i, dest);
		}
	}
	
	if(visited[dest]) return true;
	else return false;
}


void makeGraph(){
	int start = 0, dest = 0;

	cout << "input start and destination node - format : (start, dest) 0~9\n";
	cout << "Quit : input start & dest == -1, -1\n";
	do{
		scanf("%d %d", &start, &dest);
		graph[start][dest] = 1;
		graph[dest][start] = 1;
	}while(start != -1 && dest != -1);
}

int main() {
	// make graph...
	makeGraph();
	int node1, node2;
	bool result = false;

	cout << "input node1 and node2 what you want to find\n";
	cin >> node1 >> node2;
	
	visited[node1] = 1;
	result = checkRoute(node1, node2);
	
	if(result == true) {
		cout << "True\n";
	}
	else {
		cout <<"False\n";
	}
}
