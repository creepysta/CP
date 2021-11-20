/*
    author: Creepysta
    19-11-2021 14:05:56
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
    int n, index, maxSum;
    cin >> n >> index >> maxSum;
    int l = 1, h = maxSum;
    int ans = 0;
    index++;
    while(l <= h) {
        int guess = l + (h - l) / 2;
        int left = ((guess - 1) * guess) / 2, right = left;
        if(guess > index) {
            int rem = guess - index;
            int torem = (rem * (rem + 1)) / 2;
            left -= torem;
        } else {
            int nn = index - guess;
            left += nn * 1;
        }
        if(guess > n - index + 1) {
            int rem = guess - (n - index + 1);
            int torem = (rem * (rem + 1)) / 2;
            right -= torem;
        } else {
            int nn = n - index + 1 - guess;
            right += nn * 1;
        }
        int sum = left + right + guess;
        if(sum <= maxSum) {
            ans = guess;
            l = guess + 1;
        } else {
            h = guess - 1;
        }
    }
    cout << ans << '\n';
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

