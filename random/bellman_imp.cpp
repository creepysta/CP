#include <bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

vector<pair<int, int> > graph[100000]; 

void addEdge(int frm, int to, int weight) { 
	graph[frm].push_back({ to, weight }); 
	graph[to].push_back({ frm, INF }); 
} 

void shortestPathFaster(int S, int V) { 
	int d[V + 1]; 
	bool inQueue[V + 1] = { false }; 
	for (int i = 0; i <= V; i++) { 
		d[i] = INT_MAX; 
	} 
	d[S] = 0; 

	queue<int> q; 
	q.push(S); 
	inQueue[S] = true; 

	while (!q.empty()) { 

		int u = q.front(); 
		q.pop(); 
		inQueue[u] = false; 

		for (int i = 0; i < graph[u].size(); i++) { 

			int v = graph[u][i].first; 
			int weight = graph[u][i].second; 

			if (d[v] > d[u] + weight) { 
				d[v] = d[u] + weight; 

				if (!inQueue[v]) { 
					q.push(v); 
					inQueue[v] = true; 
				} 
			} 
		} 
	} 

	cout << "Vertex \t\t Distance" << " from source" << endl; 
	for (int i = 1; i <= V; i++) { 
		printf("%d \t\t %d\n", i, d[i]); 
	} 
} 

int main() { 
	int V = 5; 
	int S = 1; 

	addEdge(1, 2, 1); 
	addEdge(2, 3, 7); 
	addEdge(2, 4, -2); 
	addEdge(1, 3, 8); 
	addEdge(1, 4, 9); 
	addEdge(3, 4, 3); 
	addEdge(2, 5, 3); 
	addEdge(4, 5, -3); 

	/*
	addEdge(0, 1, 4); 
	addEdge(0, 7, 8); 
	addEdge(1, 2, 8); 
	addEdge(1, 7, 11); 
	addEdge(2, 3, 7); 
	addEdge(2, 8, 2); 
	addEdge(2, 5, 4); 
	addEdge(3, 4, 9); 
	addEdge(3, 5, 14); 
	addEdge(4, 5, 10); 
	addEdge(5, 6, 2); 
	addEdge(6, 7, 1); 
	addEdge(6, 8, 6); 
	addEdge(7, 8, 7); 
	*/

	shortestPathFaster(S, V); 

	return 0; 
} 
