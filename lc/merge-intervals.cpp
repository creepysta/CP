#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge0(vector<vector<int>>& intervals) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
	int n = intervals.size();
    if(n==0) {return {};}
	vector<vector<int>> ans;
	sort(intervals.begin(), intervals.end(), [] (const vector<int> &a, const vector<int> &b) {
		if(a[0] == b[0]) return a[1] < b[1];
		return a[0] < b[0];
	});
    ans.push_back(intervals[0]);
    for(int i = 1; i < n; i++) {
        if(intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        } else {
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        }
    }
	return ans;
}


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
	int n = intervals.size();
	vector<vector<int>> ans;
	sort(intervals.begin(), intervals.end(), [] (const vector<int> &a, const vector<int> &b) {
		if(a[0] == b[0]) return a[1] < b[1];
		return a[0] < b[0];
	});
	for(int i = 0; i < n; i++) {
		int lastnum = intervals[i][1];
		int j = i;
		for(int p=i; j+1<n && p < n; j++) {
			if(intervals[p][1] >= intervals[j+1][0]) {
				if(intervals[p][1] < intervals[j+1][1]) p = j+1;
				lastnum = max(lastnum, max(intervals[p][1], intervals[j+1][1]));
			} else {
				break;
			}
		}
		ans.push_back({intervals[i][0], lastnum});
		i = j;
	}
	return ans;
}


int main() {
	vector<vector<int>> intervals  = {{2,3},{4,5},{6,7},{8,9},{1,10}};
	//vector<vector<int>> intervals  ={{1,3},{2,6},{8,10},{15,18}};
	//vector<vector<int>> intervals  = {{2,3},{5,5},{2,2},{3,4},{3,4}};
	//vector<vector<int>> intervals  = {{1,3},{0,2},{2,3},{4,6},{4,5},{5,5},{0,2},{3,3}};
	//vector<vector<int>> intervals  = {{0,0},{1,2},{5,5},{2,4},{3,3},{5,6},{5,6},{4,6},{0,0},{1,2},{0,2},{4,5}};
	for(int i = 0; i < (int) intervals.size(); i++, cout << endl) for(int j = 0; j < 2; j++) cout << intervals[i][j] << ' ';
	auto result = merge(intervals);
	cout << "ans" << endl;
	for(int i = 0; i < (int) result.size(); i++, cout << endl) for(int j = 0; j < 2; j++) cout << result[i][j] << ' ';
	auto result0 = merge0(intervals);
	cout << "correct" << endl;
	for(int i = 0; i < (int) result0.size(); i++, cout << endl) for(int j = 0; j < 2; j++) cout << result0[i][j] << ' ';
	return 0;
}
