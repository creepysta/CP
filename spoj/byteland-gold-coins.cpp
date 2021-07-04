/*
	author: Creepysta
	29-05-2021 20:11:17
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int64_t int;
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

map<int, int> dp;

/* this shit works, but cpp doesnt
dp = {}
dp[0] = 0
dp[1] = 1

def recur(n):
    if n in dp:
        return dp[n]
    else:
        dp[n] = max(n, recur(n//2) + recur(n//3) + recur(n//4))
        return dp[n]

if __name__ == '__main__':
    try:
        while True:
            n = int(input())
            print(recur(n))
    except:
        pass
 */
int f(int x) {
	if(dp.find(x) != dp.end())
		return dp[x];
	return dp[x] = max(x, f(x/2) + f(x/3) + f(x/4));
}

void solve(int x) {
	for(int i = 0; i < 12; i++)
		dp[i] = i;
	dp[12] = 13;
	debug(x);
	int got = f(x);
	cout << got << "\n";
}

int32_t main() {
	FIO;
	int t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		int x;
		while(cin >> x)
			solve(x);
	}
	return 0;
}

