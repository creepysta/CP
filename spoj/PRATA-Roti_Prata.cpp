
/*
    author: Creepysta
    31-10-2021 13:19:30
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
    int k; cin >> k;
    cin >> n;
    vector<int> cooks(n);
    for(int &i : cooks)
        cin >> i;
    auto calc = [&] (int a, int rhs) {
        // a*(x * (x+1))/2 = rhs
        // a*x^2 + a*x = (rhs * 2);
        // det = a*a + 4 * 2 * rhs
        // x = sqrt(det) - a
        // x /= 2 * a;
        int det = a*a + 4 * 2 * a * rhs;
        int x = ((int) sqrt(det) - a)/(2*a);
        return x;
    };
    auto fn = [&] (int x) {
        int c = 0;
        for(int cook : cooks) {
            c += calc(cook, x);
            debug(cook, c, k, x);
            if(c >= k)
                return 1;
        }
        return 0;
    };
    int lo = 1, hi = 20*(k*(k+1)/2);
    int ans = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(fn(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
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
