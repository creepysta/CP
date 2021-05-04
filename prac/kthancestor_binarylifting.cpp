#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
    vector<vector<int>> q;
    vector<int> depth;
    int LOG;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 0;
        while((1<<LOG) <= n) {
            LOG++;
        }
        q = vector<vector<int>> (n, vector<int> (LOG));
        depth = vector<int> (n, 0);
        parent[0] = 0;
        for(int i = 0; i < n; i++) {
            if(i)
                depth[i] = depth[parent[i]] + 1;
            q[i][0] = parent[i];
        }
        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i < n; i++) {
                q[i][j] = q[ q[i][j-1] ][j-1];
            }
        }
        // for(int i = 0; i < n; i++) {
        //     q[i][0] = parent[i];
        //     if(i)
        //         depth[i] = depth[parent[i]] + 1;
        //     for(int j = 1; j < LOG; j++) {
        //         q[i][j] = q[ q[i][j-1] ][j-1];
        //     }
        // }
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node] < k)
            return -1;
        for(int j = 0; j < LOG; j++) {
            if((1 << j) & k) {
                node = q[node][j];
            }
        }
        return node;
    }
};

int32_t main() {
	return 0;
}
