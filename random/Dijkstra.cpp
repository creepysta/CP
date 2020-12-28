#include <bits/stdc++.h>
using namespace std;

int V = 9;

int minDist(int dist[], bool visited[]) {
	
	int min = INT_MAX, min_index;

	for(int i = 0; i < V; i++) {
if (visited[i] == false && dist[i] <= min) {
			min_index = i;
			min = dist[i];
		}
	}

	return min_index;
}

int main()
{
	int src = 0;
	int dist[V];
	bool visited[V];

	int graph[V][V] = {
		{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
		{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
		{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
		{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
		{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
		{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
		{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
		{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
		{0, 0, 2, 0, 0, 0, 6, 7, 0} 
	};

	for(int i = 0; i< V; i++) {
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	dist[src] = 0;

	for(int i = 0; i< V - 1; i++) {
		int u = minDist(dist, visited);
		visited[u] = true;

		for(int v = 0; v < V; v++) {
			if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}

	for(int i = 0; i < V; i++) {
		cout << i << "\t" << dist[i] << endl;
	}


	return 0;
}
