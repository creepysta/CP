#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];

		int mini=n;
		int maxi=0;
		map<pair<int,int>,vector<int> >mp;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++)if(v[i]>v[j]){
				int t=((j-i)*120)/(v[i]-v[j]);
				int x=i*120+v[i]*t;
				assert(120*i+v[i]*t==120*j+v[j]*t);
				mp[make_pair(t,x)].push_back(i);
				mp[make_pair(t,x)].push_back(j);
			}
		}
		for(int i=0;i<n;i++){
			vector<bool>infected(n);
			infected[i]=true;      
			for(auto p:mp){
				bool spread=false;
				for(int x:p.second)spread|=infected[x];
				if(spread){
					for(int x:p.second){
						infected[x]=true;
					}
				}
			}
			int cnt=0;
			for(int x:infected)cnt+=x;
			mini=min(mini,cnt);
			maxi=max(maxi,cnt);
		}
		printf("%d %d\n",mini,maxi);
	}
	return 0;
}
