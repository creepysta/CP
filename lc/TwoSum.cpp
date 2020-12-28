#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unsigned int j = nums.size() - 1;
			unsigned int i = 0;
			vector<int> cash = {target - nums[0]};
			vector<int> ans;
			// for ascending input
			// while (i < nums.size() && j >= 0) {
			//     int sum = nums[i] + nums[j];
			//     if(sum == target) {
			//         ans.push_back(i);                
			//         ans.push_back(j);
			//         break;
			//     } else if (sum < target) {
			//         i++;
			//     } else if (sum > target) {
			//         j--;
			//     }
			// }
			// for any input
			for(unsigned int i = 1; i < nums.size(); i++) {
				if(find(cash.begin(), cash.end(), nums[i]) != cash.end()) {
					ans.push_back(distance(cash.begin(), find(cash.begin(), cash.end(), nums[i])));
					ans.push_back(i);
				} else {
					cash.push_back(target-nums[i]);
				}
			}
			return ans;
		}
};

main() {
	Solution s;
	vector<int> a = {2,7,11, 15};
	vector<int> ans = s.twoSum(a, 41);
	for(int i : ans) {
		cout << i << endl;
	}
}
