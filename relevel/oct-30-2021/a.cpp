/*
    author: Creepysta
    30-10-2021 09:35:33
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


int modpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    string s;
    int n = 0, k;
    cin >> s;
    cin >> k;
    for(char c: s) {
        n = n*10 + (c-'0');
    }
    int len = s.length();
    int ans = -INF;
    if(len <= 2) {
        int a = n%10;
        int b = (n / 10)%10;
        ans = max(a % k, b % k);
        cout << ans << '\n';
        return;
    }
    for(int i = 2; i <= len; i++) {
        int l = n / modpow(10, i);
        int r = n % modpow(10, i-1);
        int got = l * pow(10, i-1) + r;
        int now = got % k;
        ans = max(ans, now);
    }
    cout << ans << '\n';
}


//n = 23341
//n/1000 = 23
//n%100 = 41
//23*100+n%100

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

