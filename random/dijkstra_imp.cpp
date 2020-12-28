#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

typedef pair<int, int> iPair; 

void addEdge(vector <vector<pair<int, int>>> &adj, int u, int v, int wt) { 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<vector<pair<int,int>>> adj, int V, int src) { 
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

	vector<int> dist(V, INF); 

	pq.push(make_pair(0, src)); 
	dist[src] = 0; 

	while (!pq.empty()) { 
		int u = pq.top().second; 
		pq.pop(); 

		for (int i = 0; i < (int) adj[u].size(); i++) { 
			int v = adj[u][i].first; 
			int weight = adj[u][i].second; 

			if (dist[v] > dist[u] + weight) { 
				dist[v] = dist[u] + weight; 
				pq.push(make_pair(dist[v], v)); 
			} 
		} 
	} 

	printf("Vertex\tDistance from Source\n"); 
	for (int i = 0; i < V; ++i) 
		printf("%d\t\t%d\n", i, dist[i]); 
} 

int main() { 
	int V = 5; 
	vector<vector<iPair>> adj(V); 

	/*
	addEdge(adj, 0, 1, 4); 
	addEdge(adj, 0, 7, 8); 
	addEdge(adj, 1, 2, 8); 
	addEdge(adj, 1, 7, 11); 
	addEdge(adj, 2, 3, 7); 
	addEdge(adj, 2, 8, 2); 
	addEdge(adj, 2, 5, 4); 
	addEdge(adj, 3, 4, 9); 
	addEdge(adj, 3, 5, 14); 
	addEdge(adj, 4, 5, 10); 
	addEdge(adj, 5, 6, 2); 
	addEdge(adj, 6, 7, 1); 
	addEdge(adj, 6, 8, 6); 
	addEdge(adj, 7, 8, 7); 
	*/

	addEdge(adj,1, 2, 1); 
	addEdge(adj,2, 3, 7); 
	addEdge(adj,2, 4, -2); 
	addEdge(adj,1, 3, 8); 
	addEdge(adj,1, 4, 9); 
	addEdge(adj,3, 4, 3); 
	addEdge(adj,2, 5, 3); 
	addEdge(adj,4, 5, -3); 
	shortestPath(adj, V, 0); 
	return 0; 
} 
