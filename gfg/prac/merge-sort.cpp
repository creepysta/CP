/*
    author: Creepysta
    26-09-2021 12:14:18
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

void merge(int a[], int l, int m, int r) {
    // Your code here
    int i = l, j = m+1, k = 0;
    vector<int> b(r-l+1);
    while(i <= m && j <= r) {
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i <= m)
        b[k++] = a[i++];
    while(j <= r)
        b[k++] = a[j++];
    for(int i = l, p = 0; i <= r; i++)
        a[i] = b[p++];
}

void mergeSort(int arr[], int l, int r) {
    //code here
    if(l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void solve(int t) {
    mt19937 rng(t);
    int n = 10;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        a[i] = b[i] = rng() % 10;
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    mergeSort(a, 0, n-1);
    sort(b, b + n);
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; i++)
        if(a[i] != b[i])
            assert(false);
}

int32_t main() {
    FIO;
    int t = 1;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve(tt);
    }
    return 0;
}

