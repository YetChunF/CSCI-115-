#include <iostream>
using namespace std; 

void BellmanFord(int G[][3], int E, int V, int s) {
	int* distance = new int [V];

	for (int i = 0; i < V;i++) {
		distance[i] = INT_MAX; //Initialize all vertices to infinity
	}
	distance[s] = 0; //Initialize distance of source as 0 

	for (int i = 0; i < V - 1;i++) { //Relax edges V-1 times 
		for (int j = 0; j < E;j++) {
			if (distance[G[j][0]] + G[j][2] < distance[G[j][1]]) {
				distance[G[j][1]] = distance[G[j][0]] + G[j][2];
			}
		}
	} 
	//To detect negative cycle by perform one more test after V-1 iterations
	for (int i = 0; i < E;i++) { 
		int x = G[i][0];
		int y = G[i][1];
		int weight = G[i][2];
		if (distance[x] != INT_MAX && distance[x] + weight < distance[y]) { //If the shortest path gets even shorter, then there is negative cycles
			cout << "Graph contains negative weight cycle" << endl; 
		}
	}
	cout << "Vertex    Distance from Source" << endl;
	for (int i = 0; i < V;i++) {
		cout << i << "\t\t" << distance[i] << endl;
	}
}

int main() {
	int V1 = 3;
	int E1 = 3;
	int s1 = 0;
	
	int graph1[][3] = { {0,1,2},{1,2,-1}, {0,2,5} };
	cout << "Graph 1: " << endl;
	BellmanFord(graph1, E1, V1, s1);

	int V2 = 3; 
	int E2 = 3;
	int s2 = 0; 
	int graph2[][3] = { {0,1,4},{0,2,-1},{1,2,10} };
	cout << "Graph 2: " << endl;
	BellmanFord(graph2, E2, V2, s2);
	
}
