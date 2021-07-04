/*
	author: Creepysta
    10-06-2021 23:08:23
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int MOD = int(1e9) + 7;
#ifdef LOCAL
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "[ "; err(_it, args); }
#else
#define debug(args...) ;
#define FIO ;
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

int n, x;
vector<vector<int>> g;
vector<int> sub, val;

void dfs1(int u, int p = -1) {
    sub[u] = 1;
    for(int v : g[u]) {
        if(v != p) {
            dfs1(v, u);
            sub[u] += sub[v];
        }
    }
}

void dfs2(int u, int p = -1) {
    for(int i = 0, j = 1; i < (int) g[u].size(); i++) {
        int v = g[u][i];
        if(v != p) {
            val[v] = val[u] * j;
            debug(i, p, u, v, val[u], val[v]);
            j++;
            dfs2(v, u);
        }
    }
}

int dfs(int u, int p = -1) {
    vector<int> a;
    for(int v : g[u]) {
        if(v == p) continue;
        int got = dfs(v, u);
        a.push_back(got);
    }
    sort(a.rbegin(), a.rend());
    int res = 1;
    for(int i = 0; i < (int) a.size(); i++) {
        res += (i+1) * a[i];
    }
    debug(u, res, a);
    return res;
}

void solve() {
    cin >> n >> x;
    g.clear(); g.resize(n);
    sub.clear(); sub.resize(n);
    val.clear(); val.resize(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //dfs1(0);
    //debug(n, x);
    //debug(g);
    //for(int i = 0; i < n; i++) {
        //sort(g[i].rbegin(), g[i].rend(),
                //[&] (int p, int q) {
                    //return sub[p] < sub[q];
                //}
            //);
    //}
    //debug(g);
    //val[0] = x;
    //dfs2(0);
    //int ans = 0;
    //for(int i : val)
        //ans += i;
    //ans %= MOD;
    //debug(val, sub);
    //cout << ans << "\n";
    int ans = dfs(0) % MOD;
    ans = (ans * x) % MOD;
    cout << ans << '\n';
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

