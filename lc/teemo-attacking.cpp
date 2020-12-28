#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
	int ans = 0;
	int n = timeSeries.size();
	if(!n) return 0;
	if(n==1) return duration;
	for(int i=0; i+1 < n; i++) {
		int diff = timeSeries[i+1] - timeSeries[i];
		ans +=  diff > duration ? duration: diff;
	}
	ans += duration;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		vector<int> timeSeries = {1,4};
		int duration = 2
		//vector<int> timeSeries = {1,2};
		//int duration = 2;
		int ans = findPoisonedDuration(timeSeries, duration);
		cout << ans << endl;
	}
	return 0;
}
