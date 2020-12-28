#include <bits/stdc++.h>
using namespace std;

// 2 1 5 6 2 3
// 1 2 3 3 3 2 3 3 3
int largestRectangleArea(const vector<int>& heights) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n = heights.size();
	if(!n) return 0;
	int ans = 0;
    bool sorted = is_sorted(heights.begin(), heights.end());
    if(sorted) {
        int area = 0;
        for(int i = 0; i < n; i++) {
            area = max(area, heights[i]*(n-i));
        }
        return area;
    }
	for(int i = 0; i < n ;i++) {
		int left = i-1, right = i+1;
		bool gl=true, gr=true;
		while(left >= 0 || right <= n-1) {
			if(gl && left >= 0 && heights[left] >= heights[i]) left --;
			else gl =false;
			if(gr && right < n && heights[right] >= heights[i]) right++;
			else gr = false;
			if(!(gl || gr)) break;
		}
		ans = max(ans, abs(right-left-1)*heights[i]);
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int &i : a) cin >> i;
		//for(int i : a) cout << i << ' ';
		//cout << endl;
		cout << largestRectangleArea(a) << endl;
	}
	return 0;
}
