/*
    author: Creepysta
    03-09-2022 17:13:59
https://www.geeksforgeeks.org/allocate-minimum-number-pages/
*/
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using tree_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

/*
[ a: [12, 34, 67, 90] ]
[ p: [0, 12, 46, 113, 203] ]
*/

void solve(const vector<int> &a, int m) {
    int n = a.size();
    vector<int> pref(n+1);
    pref[1] = a[0];
    for(int i = 1; i < n; i++) {
        pref[i+1] = a[i] + pref[i];
    }
    debug(a);
    debug(pref);
    int expected = ceil(pref.back() / m);
    int lo = 0, hi = n;
    int ans = pref.back() + 5;
    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if(expected == pref[mid]) {
            ans = pref[mid];
        } else if(expected > pref[mid]) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (ans == pref.back() + 5) {
        int ld = abs(expected - pref[lo]);
        int rd = abs(expected - pref[hi]);
        ans = ld < rd ? pref[lo] : pref[hi];
    }
    debug(expected, lo, hi);
    debug(ans);
    cout << ans << '\n';
}

int32_t main() {
    FIO;
    int t = 1;
    //cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        vector<int> a{12, 34, 67, 90};
        int n = a.size(), m = 2;
        //cin >> n >> m;
        //a.resize(n);
        //for(int i = 0; i < n; i++)
            //cin >> a[i];
        solve(a, m);
    }
    return 0;
}

