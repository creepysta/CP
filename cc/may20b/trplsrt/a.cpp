#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define M 500005
#define mod 1000000007
#define inf LLONG_MAX
#define endl "\n"
#define MAX 100000

using namespace std;


void input(vector<ll> & arr,ll n) {
	for(ll i=1;i<=n;++i)
		cin>>arr[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--) {
		ll n,k;
		cin>>n>>k;
		vector<ll> arr(n+1);
		input(arr,n);
		vector<ll> correctPosition(n+1,0);
		vector<vector<ll>> result;
		ll count=0;
		bool flag=true;
		ll sorted=0;
		vector<ll> problematic(n+1,0);
		ll pcount=0;
		for(ll i=1;i<=n;++i) {
			if(i==arr[arr[i]] && i!=arr[i]) {
				++pcount;
				problematic[i]=1;
			}
			if(i==arr[i])
				++sorted;
		}
		ll i=1;
		while(flag && i<=n) {
			if(sorted==n)
				break;
			if(pcount==2 && sorted==n-2) {
				flag=false;
				break;
			}
			if(i==arr[i])
				++i;
			else if(problematic[i] && pcount!=n-sorted)
				++i;
			else {
				if(!problematic[i]) { //not problematic case
					vector<ll> v;
					ll a=i;
					ll b=arr[i];
					ll c=arr[arr[i]];
					v.push_back(a);v.push_back(b);v.push_back(c);
					result.push_back(v);
					ll temp=arr[a];
					arr[a]=arr[c];
					arr[c]=arr[b];
					arr[b]=temp;
					++count;//1 rshift
					if(arr[a]==a)
						++sorted;
					if(arr[b]==b)
						++sorted;
					if(arr[c]==c)
						++sorted;
					if(a==arr[arr[a]] && a!=arr[a]) {
						pcount+=2;
						problematic[a]=1;
						problematic[arr[a]]=1;
					}
					if(b==arr[arr[b]] && b!=arr[b]) {
						pcount+=2;
						problematic[b]=1;
						problematic[arr[b]]=1;
					}
					if(c==arr[arr[c]] && c!=arr[c]) {
						pcount+=2;
						problematic[c]=1;
						problematic[arr[c]]=1;
					}
				}
				if(pcount==2 && sorted==n-2) {
					flag=false;
					break;
				}
				if(pcount && pcount==n-sorted) { //pcount>=4 here
					ll j=1,a,b,c;
					while(j<=n) {
						if(problematic[j]==1) {
							a=j;
							break;
						}
						++j;
					}
					b=arr[j];
					j=a+1;
					while(j<=n) {
						if(problematic[j]==1 && j!=b) {
							c=arr[j];
							break;
						}
						++j;
					}
					i=a;
					problematic[a]=0;
					problematic[arr[a]]=0;
					problematic[b]=0;
					problematic[arr[b]]=0;
					problematic[c]=0;
					problematic[arr[c]]=0;
					pcount-=4;
					vector<ll> v;
					v.push_back(a);v.push_back(b);v.push_back(c);
					result.push_back(v);
					ll temp=arr[a];
					arr[a]=arr[c];
					arr[c]=arr[b];
					arr[b]=temp;
					++count;//1 rshift
					if(arr[a]==a)
						++sorted;
					if(arr[b]==b)
						++sorted;
					if(arr[c]==c)
						++sorted;

				}
				if(count>k)
					flag=false;
				}
			}
			if(count>k)
					flag=false;
			if(flag==false)
					cout<<"-1"<<endl;
			else {
				cout<<count<<endl;
				for(ll ii=0;ii< (ll) result.size();++ii) {
					for(ll j=0;j<(ll) result[ii].size();++j) {
						cout<<result[ii][j]<<" ";
					}
					cout<<endl;
				}
			}
		}
		return 0;
}
