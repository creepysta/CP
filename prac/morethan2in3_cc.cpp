#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF LLONG_MAX
#define MIN LLONG_MIN
#define MOD 10000001
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

void input(vector<ll> &a, ll n) {
	for(ll &i : a) cin >> i;
}

void input1(vector<ll> &a, ll n) {
	for(ll i = 1; i <= n; i++) cin >> a[i];
}

/*
	 5 6 5
	23 30 42 57 90
	21 23 35 57 90 92
	21 23 30 57 90

	5
	21 23 30 57 90

*/

int main() {
	fastio;
	ll t;
	cin >> t;
	while(t--) {
		ll n, m, o;
		cin >> n >> m >> o;
		vector<ll> a(n), b(m), c(o);
		vector<ll> ans;
		input(a, n);
		input(b, m);
		input(c, o);
		ll i = 0, j = 0, k= 0;
		while(i < n || j < m || k < o) {
			if((i < n && j < m && k < o) && (a[i] == b[j] && a[i] == c[k])) {
				ans.push_back(a[i]);
				i++; j++; k++;
			} else if((i<n && j < m) && (a[i] == b[j])) {
				ans.push_back(a[i]);
				i++; j++;
			} else if((j<m && k < o) && (b[j] == c[k])) {
				ans.push_back(b[j]);
				j++; k++;
			} else if((i<n && k < o) && (a[i] == c[k])) {
				ans.push_back(a[i]);
				i++; k++;
			}
			else {
				if(a[i] < b[j] && a[i] < c[k]) i++;
				else if(c[k] < a[i] && c[k] < b[j]) k++;
				else if(b[j] < a[i] && b[j] < c[k]) j++;
			}
		}
		cout << ans.size() << endl;
		for(ll val : ans) cout << val << '\n';
		cout << endl;
	}

	return 0;
}

// trash
//#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
//#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
//#pragma GCC optimize(2)
//#pragma GCC optimize(3)
//#include <bits/stdc++.h>
//using namespace std;
//#define ll long long
//#define INF LLONG_MAX
//#define MIN LLONG_MIN
//#define MOD 10000001
//#define endl '\n'
//#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

//void input(vector<ll> &a, ll n) {
	//for(ll &i : a) cin >> i;
//}

//void input1(vector<ll> &a, ll n) {
	//for(ll i = 1; i <= n; i++) cin >> a[i];
//}

///*
	 //5 6 5
	//23 30 42 57 90
	//21 23 35 57 90 92
	//21 23 30 57 90

	//5
	//21 23 30 57 90

//*/

//int main() {
	//fastio;
	//ll t;
	//cin >> t;
	//while(t--) {
		//ll n, m, o;
		//cin >> n >> m >> o;
		////int a[n+m+o];
		//ll cnt = 0;
		//map<ll, ll> table;
		//for(ll i = 0; i < (n+m+o); i++) {
			//ll x;
		    //cin >> x;//>>a[i];
		    //table[x]++;
		//}
		//for(auto val : table) {
			//if (val.second >= 2) cnt++;
		//}
		//cout << cnt << endl;
		//for(auto val : table) {
			//if (val.second >= 2) cout << val.first << endl;
		//}
	//}

	//return 0;
//}


// more trash
//#include <iostream>
//using namespace std;

//int main() {

        //int n1,n2,n3,x;
	    //cin>>n1>>n2>>n3;
	    //int a[1000000]={0};
	    //int count=0;
	    //for(int i=0;i<(n1+n2+n3);i++)
	    //{
	        //cin>>x;
	        //a[x]++;

	    //}
	    //for(int i=0;i<1000000;i++)
	    //{
	        //if(a[i]>=2)
	        //count++;
	    //}
	    //cout<<count<<"\n";
	    //for(int i=0;i<1000000;i++)
	    //{
	        //if(a[i]>=2)
	        //{
	            //cout<<i<<"\n";
	        //}
	    //}
	//return 0;
//}
