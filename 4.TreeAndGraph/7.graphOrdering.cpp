#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

vector<int> orderedNode;
deque<int> tempOrdered;
deque<int> orderedNode2;

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

// semi topological sort
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

// depth first search
int DFS(vector< vector<int> > &graph, int* visited, int* isCycle, int temp) {
	// called the DFS, but it checked -> have cycle
	int status = 1;

	if(isCycle[temp]) {
		return 0;
	}
	
	if(!visited[temp]) {
		isCycle[temp] = 1;
		tempOrdered.push_back(temp);

		for(int i=0; i<graph[temp].size(); i++) {
			status = DFS(graph, visited, isCycle, graph[temp][i]);
			if(status == 0) {
				return 0;
			}
		}
		visited[temp] = 1;
		isCycle[temp] = 0;
		return 1;
	}
}

void startDFS(vector< vector<int> > & graph, int* visited, int* isCycle) {
	int dfs_result = 1;
	for(int i=0; i<graph.size(); i++) {
		if(!visited[i]) {
			dfs_result = DFS(graph, visited, isCycle, i);

			if(dfs_result == 0) {
				cout << "this graph have a cycle!\n";
				return;
			}
			else {
				while(!tempOrdered.empty()) {
					int temp = tempOrdered.back();
					tempOrdered.pop_back();
					orderedNode2.push_front(temp);
				}
			}
		}
	}
	
	if(dfs_result == 1) {
		while(!orderedNode2.empty()) {
			int node = orderedNode2.front();
			orderedNode2.pop_front();
			cout << (char)(node + 'a') <<"\t"; 
		}
	}

}


int main(const int argc, const char* argv[]) {
	if(argc < 2) {
		cout << "more input plz\n"<<endl;
		exit(1);
	}
	
	vector< vector<int> > graph;
	int nodeCnt = argc - 1;

	int* incomeCount;
	int* visited;
	int* isCycle;
	int result = 0;
	
	// init
	incomeCount = (int*)malloc(sizeof(int) * nodeCnt);
	visited = (int*)malloc(sizeof(int) * nodeCnt);
	isCycle = (int*)malloc(sizeof(int) * nodeCnt);

	for(int i=0; i<nodeCnt; i++) {
		graph.push_back(vector <int> ());
	}
	
	makeGraph(graph, incomeCount);

	// solution 1 - topological sort
	
	cout << "[result by solution1]\n";
	result = nodeOrdering(graph, incomeCount, visited);

	if(result == 1) {
		for(int i=0; i<orderedNode.size() - 1; i++) {
			cout << (char)(orderedNode[i] + 'a') <<"\t";
		}
	}
	else {
		cout << "Can't find Dependency\n";
	}

	// solution 2 - no cycle DFS
	// reInit visited array
	for(int i=0; i<nodeCnt; i++) {
		visited[i] = 0;
	}
	cout << "\n[result by solution2]\n";
	startDFS(graph, visited, isCycle);

}
