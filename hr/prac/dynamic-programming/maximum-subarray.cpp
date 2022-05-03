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
#define pb push_back
#define ff first
#define ss second
#define umapll unordered_map<long long int,long long int>
#define umapsl unordered_map<string,long long int>
#define pll pair<long long int,long long int>
#define psl pair<string,long long int>
#define pcl pair<char,long long int>
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

int dp[10001][10001];

void input(vector<ll> &a, ll n) {
    for(ll &i : a) cin >> i;
}

void input1(vector<ll> &a, ll n) {
    for(ll i = 1; i <= n; i++) cin >> a[i];
}

int main() {
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        input(a,n);
        ll tmax = 0, allmax=MIN, maxelem=MIN;
        ll tsmax=0, allsmax=MIN;
        for(ll i = 0; i < n; i++) {
             /*only considering sum of possitive elems
               subsequence sum
             */
            // tmax = max(tmax, tmax+a[i]);
            /*taking into consideration neg elems as well
              subarray sum
            */
            tmax = max(0ll, tmax+a[i]);
            tsmax = max(tsmax, tsmax+a[i]);
            allmax = max(tmax, allmax);
            allsmax = max(tsmax, allsmax);
            maxelem = max(maxelem, a[i]);
            //cout << a[i] << " " << tmax << " " << allmax << endl;
        }
        if(allmax ==0) {
            allmax = maxelem;
        }
        if(allsmax == 0) {
            allsmax = maxelem;
        }
        cout << allmax << ' ' << allsmax << endl;
        //input(a, n);
        //input1(a, n);
    }

    return 0;
}