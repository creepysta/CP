/*
	author: Creepysta
    03-04-2022 18:05:54
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

vector<vector<int>> g, gr;
vector<bool> vis, wts;

vector<int> calc(int src, int dest) {
    queue<int> q;
    q.push(src);
    vector<int> parent(1e6 + 5);
    parent[src] = -1;
    auto req = gr[dest];
    debug(req);
    auto check = [&](int s, int t) {
        queue<int> _q;
        _q.push(s);
        vector<bool> _vis(1e6+5, true);
        while(_q.size()) {
            int _u = _q.front();
            _q.pop();
            vis[_u] = true;
            for(int _v : gr[_u]) {
                if(_v == t) return true;
                if(_vis[_v]) continue;
                _q.push(_v);
            }
        }
        return false;
    };
    vector<int> toret;
    for(int _v : req) {
        int is = check(_v, src);
        if(is)
            toret.push_back(_v);
    }
    return toret;
}

void solve() {
    int n;
    cin >> n;
    g.clear();
    g.resize(n+1);
    gr.clear();
    gr.resize(n+1);
    vis.assign(n+1, false);
    wts.assign(n+1, 1);
    vector<int> mem(n);
    for(int i = 0; i < n; i++)
        cin >> mem[i];
    sort(begin(mem), end(mem));
    map<int, int> _mem;
    int val = 0;
    for(int i : mem)
        _mem[i] = val++;
    int e;
    cin >> e;
    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        g[_mem[x]].push_back(_mem[y]);
        gr[_mem[y]].push_back(_mem[x]);
    }
    int expert, noob;
    cin >> noob >> expert;
    int _expert = _mem[expert], _noob = _mem[noob];
    auto ans = calc(_noob, _expert);
    for(int v : gr[_expert])
        if(v == _noob)
            ans.push_back(v);
    for(int v : ans)
        cout << mem[v] << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

