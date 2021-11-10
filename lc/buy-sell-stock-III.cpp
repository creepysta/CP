/*
    author: Creepysta
    25-10-2021 17:59:13
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


int solve(vector<int> &prices) {
    int n = prices.size();
    int d1 = -1, d2 = -1, ans = 0;
    for(int i = 0; i < n; i++) {
        while(i < n-1 && prices[i] >= prices[i+1])
            i++;
        int bot = prices[i];
        while(i < n-1 && prices[i] <= prices[i+1])
            i++;
        int top = prices[i];
        if(d1 == -1) {
            d1 = max(d1, top - bot);
        }
        else if(d2 == -1) {
            d2 = max(d2, top-bot);
            ans = max(d1 + d2, ans);
            d1 = d2;
            d2 = -1;
        }
    }
    return max(ans, max(d1, d2));
}

int32_t main() {
    FIO;
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        vector<int> prices(n);
        for(int &i : prices)
            cin >> i;
        cout << solve(prices) << '\n';
    }
    return 0;
}

