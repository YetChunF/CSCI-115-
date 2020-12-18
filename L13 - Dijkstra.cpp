//Yet Chun Fong 300376480
// CSCI 115 Lab 13  Shortest Path - Dijkstra’s

#include <iostream>
using namespace std;

#define V 6 //This is number of vertices in the graph

//Utility function to find the vertex with minimum distance value from vertices that are not included in the shortest path tree 
int minDis(int dist[], bool spt[]) {
	int min = INT_MAX, min_index; //Initialize min value 

	for (int v = 0; v < V; v++) {
		if (spt[v] == false && dist[v] <= min) {
			min = dist[v], min_index = v;
		}
	}
	return min_index;
}

//Print function 
void print(int dist[]) {
	cout << "Vertex:          Distance from Source: " << endl;
	for (int i = 0;i < V;i++) {
		cout << i << "                   " << dist[i] << endl;
	}
}

void dijkstra(int graph[V][V], int source) {
	int dist[V]; //The output array, dist[i] will hold the shortest distance from source to i 
	bool spt[V]; //spt will be true if vertex i is already in the shortest path tree

	for (int i = 0; i < V;i++) {
		dist[i] = INT_MAX; //Initialize all distances to infinite 
		spt[i] = false;  // And all spt as false
	}
	//Source to source itself will be 0 
	dist[source] = 0;

	//To find the shortest path for all vertices
	for (int count = 0; count < V - 1;count++) {
		int u = minDis(dist, spt); //Pick a minimum distance vertex 
		spt[u] = true; //Mark the picked vertices as processed 

		for (int v = 0; v < V; v++) { //Update dist value of the adjacent vertices of picked vertex
			if (!spt[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v]; //If spt is false and distance of u is not infinity 
			} //And if distance of u + weight of graph is smaller than distance[v], then reassign the value 
		}
	}
	print(dist);
}

int main() {
	int graph[V][V] = {
		{0,4,0,1,3,0},
		{4,0,3,2,0,0},
		{0,0,2,0,1,5},
		{1,0,4,3,5,0},
		{5,0,0,1,0,2},
		{0,5,0,2,0,1}
	};
	dijkstra(graph, 0);
}
