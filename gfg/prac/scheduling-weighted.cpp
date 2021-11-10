/*
    author: Creepysta
    25-09-2021 12:46:01
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
#define debug(args...) ;
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
    int s, e, c;
    void read() { cin >> s >> e >> c; }
    bool operator < (const job &o) const { return tie(e, s, c) < tie(o.e, o.s, o.c); }
};

int slow(vector<job> &a) {
    int n = a.size();
    sort(begin(a), end(a));
    vector<int> dp(n);
    auto lastNonConflict = [&] (int pos) {
        for(int i = pos - 1; i >= 0; i--) {
            if(a[i].e <= a[pos].s)
                return i;
        }
        return INF;
    };
    dp[0] = a[0].c;
    for(int i = 1; i < n; i++) {
        int incl = a[i].c;
        int l = lastNonConflict(i);
        if (l != INF)
            incl += dp[l];
        dp[i] = max(incl, dp[i-1]);
    }
    return dp[n-1];
}

int fast (vector<job> &a) {
    int n = a.size();
    sort(begin(a), end(a));
    vector<int> dp(n);
    auto lastNonConflict = [&] (int pos) {
        int l = 0, h = pos-1;
        while(l <= h) {
            int m = l + (h-l)/2;
            if(a[m].e <= a[pos].s) {
                if(a[m+1].e <= a[pos].s)
                    l = m + 1;
                else
                    return m;
            }
            else
                h = m - 1;
        }
        return INF;
    };
    dp[0] = a[0].c;
    for(int i = 1; i < n; i++) {
        int incl = a[i].c;
        int l = lastNonConflict(i);
        if (l != INF)
            incl += dp[l];
        dp[i] = max(incl, dp[i-1]);
    }
    return dp[n-1];
}

void solve() {
    int n;
    cin >> n;
    vector<job> a(n);
    for(int i = 0; i < n; i++)
        a[i].read();
    int sl = slow(a);
    int fs = fast(a);
    debug(sl, fs);
    //assert(sl == fs);
    cout << fs << '\n';
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

