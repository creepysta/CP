/*
    author: Creepysta
    06-11-2021 10:07:12
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

void solve() {
    auto pos = [&] (const vector<int> &a, int x) {
        int n = a.size();
        int l = 0, h = n-1;
        while(l <= h) {
            int m = l + (h-l)/2;
            if(a[m] == x) return m;
            if(a[m] > x)
                h = m - 1;
            else
                l = m + 1;
        }
        return (int64_t) -1;
    };
    auto fn = [&] (const vector<int> &from, const vector<int> &to, const vector<int> &pa, const vector<int> &pb) {
        int n = from.size();
        int ans = 0;
        int pf = 0, pt = 0;
        debug(from);
        debug(to);
        debug(pf, pt);
        for(int i = 0; i < n; i++) {
            int p = pos(to, from[i]);
            debug(from[i], p);
            if(p == -1) {

            } else {
                ans += max(pa[i] - pf, pb[p] - pt);
                pf = pa[i];
                pt = pb[p];
            }
            debug(pf, pt);
        }
        if(ans == 0) return max(pa.back(), pb.back());
        ans += max(pa.back() - pf, pb.back() - pt);
        return ans;
    };
    int n;
    vector<int> a, b, pa, pb;
    while(cin >> n) {
        if(!n) break;
        a = vector<int> (n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        debug(n, a);
        int m; cin >> m;
        b = vector<int> (m);
        for(int i = 0; i < m; i++)
            cin >> b[i];
        debug(m, b);
        pa = vector<int> (n);
        for(int i = 0; i < n; i++) {
            pa[i] = a[i];
            if(i) pa[i] += pa[i-1];
        }
        pb = vector<int> (m);
        for(int i = 0; i < m; i++) {
            pb[i] = b[i];
            if(i) pb[i] += pb[i-1];
        }
        debug(a);
        debug(b);
        debug(pa);
        debug(pb);
        int ans = max(fn(a, b, pa, pb), fn(b, a, pb, pa));
        cout << ans << '\n';
    }
}

int32_t main() {
    FIO;
    int t = 1;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}

