/*
    author: Creepysta
    08-07-2021 23:49:56
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1e12) + 7;
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

/*
   1 = 1
   2 = [(1), (2)], (1, 2) = 2
   3 = [(1), (2), (3)], [(1, 2), (3)], [(1), (2, 3)], [(1, 2, 3)] = 4
   4 =
        1  2  3  4
        1    2 3 4
        1 2    3 4
        1   2 3  4
        1 2 3    4
        1 2 3 4
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 0; i < n; i++)
        cin >> a[i+1];
    vector<int> pref(n+1);
    for(int i = 1; i < n; i++)
        pref[i] += a[i-1];
    int ans = 0;

    cout << ans << '\n';
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

