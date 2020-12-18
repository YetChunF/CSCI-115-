#include <iostream>
#include <list>;
#include <vector>
using namespace std; 

class BreadthFirstSearch {
	int U; //Vertices
	list<int>* adj; //Vector to store adjacents

public:
	BreadthFirstSearch(int U) { //Constructor 
		this->U = U;
		adj = new list<int>[U];
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v); //Push v into u's list
	}

	void BFS(int u) {
		bool* visited = new bool[U];
		for (int i = 0; i < U;i++) {
			visited[i] = false; //Mark all vertices as not visited first
		}
		list<int> queue; //Create a queue for BFS
		visited[u] = true; //Mark as visited
		queue.push_back(u); //Enqueue the node

		list<int>::iterator i;
		while (!queue.empty()) {
			u = queue.front();
			cout << u << " ";
			queue.pop_front(); //Dequeue the vertex from queue 

			for (i = adj[u].begin();i != adj[u].end();++i) {
				if (!visited[*i]) { //Push the adjacents of vertices into the queue
					visited[*i] = true; //Repeat until the last vertex 
					queue.push_back(*i); 
				}
			}
		}
	}
};

class DepthFirstSearch {
	int U; // Vertices
	list<int>* adj; //Store adjacency lists

	void DFS_Util(int u, bool visited[]) {
		visited[u] = true; //Mark as true 
		cout << u << " "; //Then print out
		
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			if (!visited[*i]) { //If the adjacent node is not visited 
				DFS_Util(*i, visited); //Recursively explore as deep as possible
			}
		}
	}

public:
	DepthFirstSearch(int U) { //Constructor 
		this->U = U;
		adj = new list<int>[U];
	}

	void addEdge(int u, int v) { 
		adj[u].push_back(v); //Add v to u's list
	}

	void DFS(int u) {               
		bool* visited = new bool[U];
		for (int i = 0; i < U;i++) {
			visited[i] = false; //Mark all vertices as !visited
		}
		DFS_Util(u, visited); //Traverse the graph recursively 
	}
};

int main() {
	int n = 10; 

	//BFS
	BreadthFirstSearch b(n);
	b.addEdge(0, 1);
	b.addEdge(0, 2);
	b.addEdge(1, 2);
	b.addEdge(2, 0);
	b.addEdge(1, 6);
	b.addEdge(2, 3);
	b.addEdge(3, 3);
	b.addEdge(2, 5);
	b.addEdge(3, 7);
	b.addEdge(5, 8);
	b.addEdge(7, 9);
	cout << "Output for Breadth First Search: ";
	b.BFS(1);
	cout << endl;

	//DFS
	DepthFirstSearch d(n);
	d.addEdge(0, 1);
	d.addEdge(0, 2);
	d.addEdge(1, 2);
	d.addEdge(2, 0);
	d.addEdge(1, 6);
	d.addEdge(2, 3);
	d.addEdge(3, 3);
	d.addEdge(2, 5);
	d.addEdge(3, 7);
	d.addEdge(5, 8);
	d.addEdge(7, 9);
	cout << "Output for Depth First Search: ";
	d.DFS(1);
	cout << endl;

}