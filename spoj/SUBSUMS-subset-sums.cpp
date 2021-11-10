/*
    author: Creepysta
    22-10-2021 16:49:43
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
    int n, A, B, x;
    cin >> n >> A >> B;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(i < (n+1)/2) a.push_back(x);
        else b.push_back(x);
    }
    debug(n, A, B, x);
    debug(a, b);
    auto subsum = [&] (const vector<int> &ini, vector<int> &fin) {
        int ins = ini.size();
        for(int mask = 0; mask < (1<<ins) ; mask++) {
            int sum = 0;
            for(int i = 0; i < ins; i++) {
                if(mask & (1 << i)) {
                    sum += ini[i];
                }
            }
            fin.push_back(sum);
        }
    };
    vector<int> prefa, prefb;
    subsum(a, prefa);
    subsum(b, prefb);
    sort(begin(prefa), end(prefa));
    sort(begin(prefb), end(prefb));
    int pa = prefa.size(), pb = prefb.size();
    //debug(pa, pb);
    debug(prefa);
    debug(prefb);
    auto pos = [&] (int k, int yy) {
        int l = 0, h = pb - 1;
        int got = -1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(prefb[mid]+k >= yy) {
                got = mid;
                h = mid - 1;
            } else
                l = mid + 1;
            //debug(l, h, mid, got, k, yy);
        }
        return got;
    };
    int ans = 0;
    for(int i = 0; i < pa; i++) {
        int ll = pos(prefa[i], A),
            rr = pos(prefa[i], B+1);
        debug(i);
        rr = rr < 0 ? pb : rr;
        debug(ll, rr);
        if(ll != -1)
            ans += rr - ll;
    }
    cout << ans << '\n';
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


