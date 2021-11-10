/*
    author: Creepysta
    28-09-2021 22:26:04
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

struct edge {
    int a, b, w;
    void read() { cin >> a >> b >> w; }
};

void solve() {
    int n;
    cin >> n;
    vector<edge> g(n);
    for(int i = 0; i < n; i++)
        g[i].read();
    vector<int> d(n, INF);
    d[0] = 0;
    for(int i = 0; i < n; i++) {
        bool changed = 0;
        for(edge e : g) {
            int a = e.a, b=e.b, w=e.w;
            if(d[b] > d[a] + w) {
                changed = 1;
                d[b] = d[a] + w;
            }
        }
        if(i == n-1 && changed) {
            cout << 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
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

