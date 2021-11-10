/*
    author: Creepysta
    22-07-2021 20:59:57
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

int n, x;
const int nax = 1e5 + 5;
array<int,nax> a, b;

void toggle(int l, int r) {
    int v = ((1 << r) -1) ^ ((1<< (l-1)) - 1);
    x ^= v;
}

void modify(int p, int v) {
    int mask = 1 << p;
    x = ((n & ~mask) | (v << p));
}

int merge(int l, int m, int r) {
    int i = l, j = m, k = l;
    int inv = 0;
    while(i < m && j < r) {
        if(a[i] > a[j]) {
            b[k++] = a[j++];
            inv += m - i;
            int me = (1 << m) & x;
            toggle(i, m);
            if((m-i) % 2)
                modify(i, ~me);
            else
                modify(i, me);
            debug(x);
        } else {
            b[k++] = a[i++];
        }
    }
    while(i < m) {
        b[k++] = a[i++];
    }
    while(j < r) {
        b[k++] = a[j++];
    }
    for(int i = l; i < r; i++)
        a[i] = b[i];
    return inv;
}

int get(int l, int r) {
    int inv = 0;
    if(l < r-1) {
        int mid = l + (r - l) / 2;
        inv += get(l, mid);
        inv += get(mid, r);
        inv += merge(l, mid, r);
    }
    return inv;
}

array<array<int, 2>, nax> cnt;
void solve() {
    for(int i = 0; i < nax; i++)
        cnt[i][0] = cnt[i][1] = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]][i%2] ++;
    }
    //x = 0;
    //int inv = get(0, n);
    //if(inv % 2)
    //if(x == 0)
        //cout << "YES\n";
    //else
        //cout << "NO\n";

    //vector<pair<int, int>> a(n);
    //for(int i = 0; i < n; i++) {
        //cin >> a[i].first, a[i].second = i;
    //}
    //sort(begin(a), end(a));
    //for(int i = 0; i < n; i++) {
        //int diff = abs(i - a[i].second);
        //if(diff % 2) {
            //cout << "NO\n";
            //return;
        //}
    //}
    //cout << "YES\n";

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]][i%2] ++;
    }
    sort(begin(a), end(a));
    for(int i = 0; i < n; i++) {
        cnt[a[i]][i%2] --;
    }
    for(int i = 0; i < n; i++) {
        if(cnt[a[i]][0] != 0 || cnt[a[i]][1] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

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

