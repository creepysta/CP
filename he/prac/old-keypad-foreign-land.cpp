/*
    author: Creepysta
    31-10-2021 11:34:24
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
    int n;
    cin >> n;
    vector<int> freq(n);
    for(int &i : freq)
        cin >> i;
    int m;
    cin >> m;
    vector<int> key(m), ck;
    int keys = 0
    for(int &i : key) {
        cin >> i;
        keys += i;
    }
    ck = vector<int> (m);
    sort(freq.rbegin(), freq.rend());
    int ans = 0;
    if(keys < n) {
        cout << -1 << "\n";
        return;
    }
    for(int f = 0; f < n; f++) {
        int step = 1;
        for( ; step <= 50; step++) {
            bool got = 0;
            for(int k = 0; k < m; k++) {
                if(step > ck[k] && ck[k] < key[k]) {
                    ck[k] = step;
                    got = 1;
                    break;
                }
            }
            if(got) break;
        }
        ans += freq[f] * step;
    }
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

