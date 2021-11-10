/*
    author: Creepysta
    25-09-2021 01:31:15
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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    sort(begin(a), end(a));
    int ps = -INF, pe = -INF, count = 0;
    auto overlap = [=] (int s, int e, int ps, int pe) {
        for(int rep = 0; rep < 2; rep++) {
            if((ps <= s && s <= pe) || (ps <= e && e <= pe))
                return true;
            swap(s, ps);
            swap(e, pe);
        }
        return false;
    };
    for(int i = 0; i < n; i++) {
        int end = a[i].first, start = a[i].second;
        if (overlap(start, end, ps, pe))
            continue;
        count++;
        ps = start, pe = end;
    }
    cout << count << '\n';
}

int32_t main() {
    FIO;
    int t = 1;
#ifdef LOCAL
    cin >> t;
#endif
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}

