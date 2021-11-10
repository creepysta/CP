/*
    author: Creepysta
    20-07-2021 23:20:39
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

const int nax = 1e5;
char a[nax+5];

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    for(int i = 0; i < m; i++)
        a[i] = 0;
    for(int i = 0; i < 2*n-1; i++) {
        cin >> s;
        for(int j = 0; j < m; j++)
            a[j] ^= s[j];
    }
    string ans = "";
    for(int i = 0; i < m; i++) {
        if(a[i]) ans += a[i];
    }
    fflush(stdout);
    //string ans = "";
    //for(int i = 0; i < 26; i++) {
        //if(f[i])
            //ans += i+'a';
    //}
    cout << ans << endl;
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

