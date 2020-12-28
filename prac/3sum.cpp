#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int k) {
	vector<vector<int>> ans;
	if(nums.empty()) return ans;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	for(int i = 0; i < n; i++) {
		if(i== 0 || (i>0 && nums[i] != nums[i-1])) {
			int low = i+1;
			int high = n-1;
			int tofind = 0-nums[i];
			while(low < high) {
				int sum = nums[low] + nums[high];
				if(sum == tofind) {
					ans.push_back({nums[i], nums[low], nums[high]});
					while(low < high && nums[low] == nums[low+1]) low++;
					while(low < high && nums[high] == nums[high-1]) high--;
					low++;
					high--;
				} else if(sum < tofind) low ++;
				else high --;
			}
		}
	}
	return ans;
}


int32_t main() {
	int n, k;
	cin >> n >> k;
	vector<int> nums;
	for(int &i : nums) cin >> i;
	auto ans = threeSum(nums, k);
	for(auto ii : ans) {
		for(auto i : ii) {
			cout << i << ' ';
		}
		cout << endl;
	}
	return 0;
}
