// covid
#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","popcnt")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define MOD 1000000007
//#define endl '\n'

bool wrong = false;

void ask(int i, int j, int i1, int j1) {
	cout << 1 << ' '<< i << ' ' << j << ' ' << i1 << ' ' << j1 << endl;
}

//vector<bool>sample;
bool sample[61][61];

void divmid(

void solve() {
	int n,p;
	cin >> n >> p;
	//sample.clear();sample.resize(n+1,vector<int> (n+1));
	memset(sample, 0, sizeof(sample));
	int given;
	// p is the probability of a person being infected
	// print 1 r1 r2 c1 c2
	// read X
	// if X != -1 then X = number of infected people
	// print 2\n ans matrix
	// read X
	// if x == 1 then correct
	// else wrong return
	for(int i = 1; i <= n; i++) {
		ask(i, j, i, j);
		cin >> given;
		if(given==-1) {
			wrong = true;
			return;
		}
		int nums = n;
		if(given == 0 || given == n) {
			if(given = n)
			for(int j = 1; j <= n; j++) {
				sample[i][j] = 1;
			}
		}
		else {
			bool done= false;
			while(!done) {
				nums/=2;
				while(nums) {
					ask(i, nums,
					for(int j = 0; j<nums; j++) {

					}
					nums/=2;
				}
			}
		}
	}
	cout << 2<< endl;
	for(int i=1; i <=n ;i++, cout << endl) for(int j=1; j <=n; j++) cout << sample[i][j] << ' ';
	cin >> given;
	if(given==1) return;
	if(given == -1) {
		wrong = true;
		return;
	}
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t=1;
	cin >> t;
	for(ll tt=1; tt <= t; tt++) {
		//cout << "case #" << tt << ":\n";
		if(wrong) break;
		solve();
	}

	return 0;
}
