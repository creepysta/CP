/*
	author: Creepysta
	22-05-2021 19:21:33
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << boolalpha << "debug: [ "; err(_it, args); }
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

// manku
const string s = "manku";
const int m = s.length();

#define lli long long int
string test(int j){
	char a[100];
	int t,i,p;
	i=0;
	while(j!=0){
		p=j%5;
		if(p==1)
			a[i]='m';
		else if(p==2)
			a[i]='a';
		else if(p==3)
			a[i]='n';
		else if(p==4)
			a[i]='k';
		else
			a[i]='u';
		j=(j-1)/5;
		i++;
	}
	i--;
	string ans = "";
	for(;i>=0;i--)
		ans += a[i];
	return ans;
}

void solve(int tt) {
	mt19937 rng(tt);
	int x, nx;
#ifdef LOCAL
	x = rng() % 50;
	if(!x) return;
#else
	cin >> x;
#endif
	nx = x;
	debug(x);
	string ans = "";
	// segfault in tc 3
	//x--;
	//int i = x % m;
	//ans = s[i] + ans;
	//x /= m;
	//while(x) {
		//i = x % m;
		//if(i == 0) {
			//ans = "u" + ans;
			//x /= m;
		//} else {
			//ans = s[i-1] + ans;
		//}
		//x /= m;
	//}
	const string ss = "umank";
	while(x) {
		int i = x % m;
		ans = ss[i] + ans;
		x = (x-1) / m;
	}
	debug(nx, "$"+ans+"$", "$"+test(nx)+"$");
	assert(ans == test(nx));
	cout << ans << '\n';
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
#ifdef LOCAL
	t = 100000;
#else
	cin >> t;
#endif
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve(tt);
	}
	return 0;
}

