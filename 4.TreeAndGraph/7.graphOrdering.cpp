#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> orderedNode;

void makeGraph(vector< vector<int> > &graph, int* incomeCount) {
	char start, dest;
	int s, d;
	do{
		printf("input node to node\n");
		scanf("\n%c %c", &start, &dest);
		s = start - 'a';
		d = dest - 'a';
		
		graph[s].push_back(d);
		incomeCount[d]++;

	}while(!(s < 0 || d < 0));
}

int findZeroIncome(int* incomeCount, int* visited, int length) {
	for(int i=0; i<length; i++) {
		if(!visited[i] && incomeCount[i] == 0) {
			return i;
		}
	}
	return -1;
}

int nodeOrdering(vector< vector<int> > &graph, int* incomeCount, int* visited) {
	int tempNode;
	
	do{
		tempNode = findZeroIncome(incomeCount, visited, graph.size());
		
		if(!visited[tempNode]) {
			visited[tempNode] = 1;
			orderedNode.push_back(tempNode);
		}

		for(int i=0; i<graph[tempNode].size(); i++) {
			int next = graph[tempNode][i];
			incomeCount[next]--;
		}
		
	}while(tempNode != -1);	

	for(int i=0; i<graph.size(); i++) {
		if(visited[i] == 0) {
			return 0;
		}
	}
	return 1;
}


//TODO: make grpha_vector (2d) & incoming count array, input node to node and incoming count plus, 
int main(const int argc, const char* argv[]) {
	if(argc < 2) {
		cout << "more input plz\n"<<endl;
		exit(1);
	}

	int nodeCnt = argc - 1;
	vector< vector<int> > graph;
	int* incomeCount;
	int* visited;
	int result = 0;
	
	// init
	incomeCount = (int*)malloc(sizeof(int) * nodeCnt);
	visited = (int*)malloc(sizeof(int) * nodeCnt);

	for(int i=0; i<nodeCnt; i++) {
		graph.push_back(vector <int> ());
	}
	
	makeGraph(graph, incomeCount);
	result = nodeOrdering(graph, incomeCount, visited);

	if(result == 1) {
		for(int i=0; i<orderedNode.size() - 1; i++) {
			cout << (char)(orderedNode[i] + 'a') <<"\t";
		}
	}
	else {
		cout << "Can't find Dependency\n";
	}

}
