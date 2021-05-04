/*
	author: Creepysta
	10-04-2021 11:55:06
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#else
#define debug(args...) 0;
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { o << "[";for(auto e : x) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": "  << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &x) itfr
tmpt > ostop , const set<T> &x) itfr
tmpt , class V> ostop , const map<T,V> &x) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

vector<bool> prime;
vector<int> primes;

void solve() {
	int L, R;
	cin >> L >> R;
	if(R <= (int) 1e6) {
		prime.clear();
		prime.assign(R+1, true);
		prime[0] = prime[1] = false;
		for(int i = 2; i <= R; i++) {
			if(prime[i]) {
				for(int j = i*i; j <= R; j+=i)
					prime[j] = false;
			}
		}
		for(int i = L; i <= R; i++)
			if(prime[i])
				cout << i << '\n';
		return;
	}
	int lim = sqrt(R);
	primes.clear();
	prime.clear();
	prime.assign(lim+1, true);
	prime[0] = prime[1] = false;
	for(int i = 2;i <= lim; i++) {
		if(prime[i]) {
			primes.emplace_back(i);
			for(int j = i * i; j <= lim; j+= i)
				prime[j] = false;
		}
	}
	prime.clear();
	prime.assign(R-L+1, true);
	for(int i : primes) {
		for(int j = max(i*i,  (L+i-1) / i*i); j <= R; j += i)
			prime[j-L] = false;
	}
	if(L == 1)
		prime[0] = false;
	for(int i = 0; i < (int) prime.size(); i++)
		if(prime[i])
			cout << (L+i) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

