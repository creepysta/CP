#include <bits/stdc++.h>
using namespace std;


// 0 1 0 2 1 0 1 3 2 1 2 1

// best
/*
int trap(vector<int>& height) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
            ++left;
        }
        else {
            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
            --right;
        }
    }
    return ans;
}
*/

// concise
/*
int trap(const vector<int> &height) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int water = 0;
	int n = height.size();
	if(!n) return 0;
	int maxeleml = 0, maxelemr = 0;
	int maxposr = n-1, maxposl = 0;
	// left max elem pos
	for(int j = 0, k = n-1; j < n; j++, k--) {
		if(maxeleml < height[j]) {
			maxeleml = height[j];
			maxposl = j;
		}
        if(maxelemr < height[k]) {
            maxelemr = height[k];
            maxposr = k;
        }
	}
	int pl = 0, pr = n-1;
	// calc left water
	for(int i = pl, j = pr; i < n; i++, j--) {
		if(i <= maxposl and height[i] <= height[pl]) {
			water += height[pl] - height[i];
		} else {
			pl = i;
		}
        if(j >= maxposr and height[j] <= height[pr]) {
            water += height[pr] - height[j];
        } else {
            pr = j;
        }
	}
	// calc middle water
	for(int i = maxposl; i <= maxposr; i++) {
        water += height[maxposl] - height[i];
	}
	return water;
}

*/



// elaborate
int trap(vector<int> &height) {
	int water = 0;
	int n = height.size();
	if(!n) return 0;
	int maxelem = 0;
	int maxposr = n-1, maxposl = 0;
	// left max elem pos
	for(int j = 0; j < n; j++) {
		if(maxelem < height[j]) {
			maxelem = height[j];
			maxposl = j;
		}
	}
	maxelem = 0;
	// right max elem pos
	for(int j = n - 1; j >= 0; j--) {
		if(maxelem < height[j]) {
			maxelem = height[j];
			maxposr = j;
		}
	}
	int i = 0;
	while(i < n and !height[i]) i++;
	int p = i;
	// calc left water
	for(i = p+1; i <= maxposl; i++) {
		if(height[i] <= height[p]) {
			water += height[p] - height[i];
		} else {
			p = i;
		}
	}
	i = n-1;
	while(i >= 0 and !height[i]) i--;
	p = i;
	// calc right water
	for(i = p-1; i >= maxposr; i--) {
		if(height[i] <= height[p]) {
			water += height[p] - height[i];
		} else {
			p = i;
		}
	}
	// calc middle water
	for(i = maxposl ; i <= maxposr; i++) {
		if(height[i] <= height[p]) {
			water += height[p] - height[i];
		} else {
			p = i;
		}
	}
	return water;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int &i:a) cin >> i;
		cout << trap(a) << endl;
	}
}
