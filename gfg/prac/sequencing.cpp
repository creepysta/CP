/*
    author: Creepysta
    25-09-2021 23:05:41
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

struct job {
    int id, deadline, profit;
    void read() { cin >> id >> deadline >> profit; }
    bool operator < (const job &o) const { return profit > o.profit; };
    friend ostream& operator<<(ostream& o, const job &j) { o << '[' << j.id << ',' << j.deadline << ',' << j.profit << ']'; return o; }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1);
        for(int v = 0; v <= n; v++) {
            make_set(v);
        }
    }
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }
    int find_set(int v) {
        if(v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if(a != b) {
            if(rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }
    void merge(int u, int p) {
        parent[u] = p;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<job> a(n);
    int maxDeadline = -INF;
    for(int i = 0; i < n; i++) {
        a[i].read();
        maxDeadline = max(maxDeadline, a[i].deadline);
    }
    sort(begin(a), end(a));
    debug(a);
    DSU dsu(maxDeadline);
    int profit = 0, count = 0;
    for(int i = 0; i < n; i++) {
        int slot = dsu.find_set(a[i].deadline);
        if(slot > 0) {
            dsu.merge(slot, dsu.find_set(slot-1));
            count++;
            profit += a[i].profit;
        }
    }
    cout << count << ' ' << profit << '\n';
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

