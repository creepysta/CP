/*
    author: Creepysta
    20-11-2021 17:36:38
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

const int nax = 1e7;
array<bool, nax> isPrime;


/*

given : n
for 2 to n+1 arrange the numbers as follows

Say, we are placing the number i
if gcd(2,.. i-1) == 1,  place i at the start of a new row
else if gcd(2,.. i-1) != 1, place i at the first empty col in the the jth row for which the condition holds


*/

void solve() {
    int n;
    cin >> n;
    fill(begin(isPrime), end(isPrime), 1);
    int need = n + 1;
    for(int i = 2, r = 0, c = 0; i <= nax; i++) {
        if(isPrime[i]) {
            r++;
            c = 1;
            if(i == need) {
                debug(need, r, c);
                cout << r * c << '\n';
                return;
            }
            for(int j = i+i; j <= nax; j += i) {
                if(isPrime[j]) {
                    c++;
                    if(j == need) {
                        debug(need, r, c);
                        cout << r * c << '\n';
                        return;
                    }
                }
                isPrime[j] = false;
            }
        }
    }
}

/*
2 4 6 8 10 12 14 16 18 20
3 9 15 21 27 33 _ _ _ _
5 25 35 _ _ _ _ _ _ _
7 49 _ _ _ _ _ _ _ _
11 121 _ _ _ _ _ _ _ _
13 169 _ _ _ _ _ _ _ _
17 _ _ _ _ _ _ _ _ _
19 _ _ _ _ _ _ _ _ _
23 _ _ _ _ _ _ _ _ _
29 _ _ _ _ _ _ _ _ _
*/

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

