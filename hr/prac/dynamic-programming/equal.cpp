/*
    author: Creepysta
    15-07-2021 22:49:21
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
    vector<int> a(n);
    for(int &i : a)
        cin >> i;
    //sort(a.begin(), a.end());
    //auto cmp = [](int x, int y) { return x > y; };
    int ans = INF;
    int small = *min_element(a.begin(), a.end());
    for(int p = 0; p < 3; p++) {
        //set<int, decltype(cmp)> s(cmp);
        //for(int i : a)
            //s.insert(i+p);
        int c = 0;
        for(int i = 0; i < n; i++) {
            int diff = a[i] - small + p;
            c += diff / 5 + diff % 5 / 2 + diff % 5 % 2 / 1;
        }
        //while(s.size() != 1) {
            //auto it = s.begin();
            //int y = *it;
            //s.erase(it);
            //int x = *s.begin();
            //int diff = y - x;
            //if(diff >= 5)
                //y -= 5;
            //else if(diff >= 2)
                //y -= 2;
            //else
                //y--;
            //s.insert(y);
            //c++;
        //}
        ans = min(ans, c);
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

