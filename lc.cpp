//https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int n, const vector<vector<int>>& st) {
        vector<vector<int>> g(n+5);
        for(int i = 0; i < n; i++) {
            g[st[i][1]].push_back(st[i][0]);
        }
        queue<int> q;
        vector<int> vis(n+5);
        int courses = 0;
        for(int i = 0; i < n; i++) {
            q.push(i);
            vis[i] = 1;
            while(q.size()) {
                int u = q.front();
                vis[u] = 1;
                q.pop();
                for(int v : g[u]) {
                    if(vis[v]) continue;
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for(int i : vis) {
            ans += i;
        }
        return ans >= n;
    }
};


//https://leetcode.com/problems/solving-questions-with-brainpower/
class Solution {
public:
    struct St {
        int size=1;
        vector<int> st;
        St(const vector<vector<int>> &a) {
            size = 4*a.size();
            st.resize(size);
            build(1, 0, size-1, a);
        }
        void build(int x, int l, int r, const vector<vector<int>> &a) {
            if(l == r) {
                if(l < a.size()) {
                    st[x] = a[l];
                }
                return;
            }
            int mid = l + (r - l) / 2;
            build(2*x, l, m, a);
            build(2*x+1, m, r, a);
            st[x] = max(st[2*x]. st[2*x + 1]);
        }
        int query(int lx, int rx, int x, int l, int r) {
            if(l > r) return 0;
            if(l <= lx && rx <= r) return st[x];
            int mid = l + (r - l) / 2;
            int lt = query(lx, rx, 2*x, l, m);
            int rt = query(lx, rx, 2*x + 1, m, r);
            return max(lt, rt);
        }
        int query(int lx, int rx) {
            return query(lx, rx, 1, 0, size-1)
        }
    };
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        St st(questions);
        for(int i = 0; i < n; i++) {
            int is = questions[i];
            int to =  min(n-1, i + questions[i][1]);
            long long maybe = st.query(i, to);

        }
    }
};
