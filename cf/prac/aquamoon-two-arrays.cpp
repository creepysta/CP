/*
    author: Creepysta
    17-07-2021 16:45:03
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

void solve() {
    int n, sa=0;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sa += a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sa -= b[i];
    }
    if(sa) {
        cout << -1 << '\n';
        return;
    }
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) continue;
        for(int k = 0; k < 100; k++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(a[j] == b[j]) continue;
                if(a[i] > b[i] && a[j] < b[j]) {
                    a[i]--; a[j]++;
                    ans.emplace_back(i+1, j+1);
                }
                else if(a[i] < b[i] && a[j] > b[j]) {
                    a[j]--; a[i]++;
                    ans.emplace_back(j+1, i+1);
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
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

