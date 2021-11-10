/*
    author: Creepysta
    02-10-2021 10:06:47
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1e12) + 7;
const int MOD = int(1e9) + 7;
#ifdef LOCAL
#define FIO ;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "[ "; err(_it, args); }
#else
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) ;
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { if(x.empty()) {cout<<"[ ]";return o;} o<<"[";for(auto e:x) o<<e<<", ";o<<"\b\b]";return o;}
void err(istream_iterator<string> it) {cerr<<"\b\b ]\n";}
tmpt , class... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<": "<<a<< ", ";err(++it,args...);}
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt > ostop , const multiset<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) {o<<"(";o<<p.first<<", "<<p.second<<")";return o;}

int n, m;
vector<vector<int>> g;
vector<vector<bool>> vis;
const vector<pair<int, int>> dir {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m && !vis[i][j];
}

void solve() {
    cin >> n >> m;
    g.assign(n, vector<int>(m));
    vis.assign(n, vector<bool>(m, 0));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
            if(!g[i][j]) {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    int cnt = q.size(), sec = 0;
    bool inf = 0;
    while(q.size()) {
        int x, y;
        tie(y, x) = q.front();
        q.pop();
        for(auto d : dir) {
            int dy = y + d.first, dx = x + d.second;
            if(valid(dy, dx)) {
                if(g[dy][dx] == 1) {
                    inf = 1;
                    q.push({dy, dx});
                    vis[dy][dx] = 1;
                    g[dy][dx] = 0;
                }
            }
        }
        if(--cnt == 0) {
            if(inf)
                sec++;
            inf = 0;
            cnt = q.size();
        }
    }
    cout << sec << '\n';
}

int32_t main() {
    FIO;
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}

