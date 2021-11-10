/*
    author: Creepysta
    23-10-2021 18:12:38
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
	vector<string> a(n+1);
    //for(int i = 1; i <= n; i++)
        //cin >> a[i];
    a[0] = char(0);
    for(int i = 1; i <= n; i++) {
        string s; cin >> s;
        int j = i - 1;
        for(; j >= 0; j--) {
            if(a[j] >= s)
                a[j+1] = a[j];
            else break;
        }
        a[j+1] = s;
        cout << j << '\n';
        debug(s, a, i, j);
    }
    //vector<string> b, c;
    //for(int i = 1; i <= n; i++)
        //b.push_back(a[i]);
    //for(string e : b) {
        //sort(begin(c), end(c));
        //int pos = lower_bound(begin(c), end(c), e) - begin(c);
        //debug(e, pos);
        //cout << pos << '\n';
        //c.push_back(e);
    //}
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

