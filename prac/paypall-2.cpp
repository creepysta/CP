/*
    author: Creepysta
    04-09-2022 13:05:19
*/
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using tree_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

void solve(const vector<int> &a) {
    int n = a.size();
    int tolook = INF;
    for(int i = 0; i < n-1; i++) {
        tolook = min(tolook, a[i+1] - a[i]);
    }
    map<int, int> m;
    vector< pair<int, int> > ret;
    for(int i = 0; i < n; i++) {
        if(m.find(abs(tolook - a[i])) != m.end()) {
            int now = a[i], prev = a[m[abs(tolook-a[i])]];
            if (now > prev) swap(now, prev);
            ret.emplace_back(now, prev);
        }
        m[a[i]] = i;
    }
    sort(begin(ret), end(ret));
    for(auto p : ret) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

int32_t main() {
    FIO;
    vector<int> a{ 6, 2, 4, 10 };
    sort(a.begin(), a.end());
    solve(a);
    return 0;
}
