/*
    author: Creepysta
    30-10-2021 12:05:34
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
    vector<int> a(n);
    for(int & i: a)
        cin >> i;
    sort(begin(a), end(a));
    int q;
    cin >> q;
    for(int qq = 0; qq < q; qq++) {
        int x, copy; cin >> x; copy = x;
        vector<int> digits;
        while(copy) {
            digits.push_back(copy%10);
            copy /= 10;
        }
        reverse(begin(digits), end(digits));
        debug(digits);
        bool allin = 1, onebig = 0;
        for(int i : digits) {
            allin &= binary_search(begin(a), end(a), i);
            onebig |= a[n-1] < i;
        }
        if(allin)
            cout << x << '\n';
        else if(onebig) {
            string ans = string(digits.size() + 1, a[0] + '0');
            cout << ans << '\n';
        }
        else {
            string ans = "";
            int el = digits[0];
            int pos = lower_bound(begin(a), end(a), el) - begin(a);
            ans += to_string(a[pos]);
            bool flag = 0;
            flag = ans[0] > digits[0];
            for(int d = 1; d < (int) digits.size(); d++) {
                el = digits[d];
                if(flag || ans[d-1] > digits[d-1]) {
                    ans += to_string(a[0]);
                } else {
                    pos = lower_bound(begin(a), end(a), el) - begin(a);
                    ans += to_string(a[pos]);
                    flag |= ans[d] > digits[d];
                }
            }
            cout << ans << '\n';
        }
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

