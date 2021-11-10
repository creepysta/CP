/*
    author: Creepysta
    26-05-2021 20:41:00
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
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

void greedy() {
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    int n = a.length(), m = b.length();
    bool ok = true;
    unordered_set<int> taken;
    for(; i < n && j < m;) {
        if(a[i] == b[j] || a[i] - b[j] == 32)
            taken.insert(i), j++;
        i++;
    }
    for(int t = 0; t < n; t++) {
        if(taken.find(t) == taken.end()) {
            if(a[t] >= 'A' && a[t] <= 'Z')
                ok = false;
        }
    }
    if(j == m && ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}

vector<vector<bool>> dp;
string a, b;
int n, m;

void solve() {
    cin >> a >> b;
    n = a.length(), m = b.length();
    if (n < m) {
        cout << "NO" << endl;
        return;
    }
    dp[0][0] = true;
    for (int i = 1; i <= n && islower(a[i-1]); ++i)
        dp[i][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(m, i); ++j) {
            if (islower(a[i-1]))
                dp[i][j] = dp[i][j] || dp[i-1][j];
            if (toupper(a[i-1]) == b[j-1])
                dp[i][j] = dp[i][j] || dp[i-1][j-1];
        }
    }
    if(dp[n][m])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        dp = vector<vector<bool>> (1010, vector<bool> (1010));
        solve();
    }
    return 0;
}
