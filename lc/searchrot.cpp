/*
	author: Creepysta
	27-03-2021 11:59:47
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
#define int int64_t
#ifdef LOCAL
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); cerr << "debug: [ "; err(_it, args); }
#else
#define debug(args...) 0
#endif
#define tmpt template < class T
#define ostop ostream& operator<<(ostream& o
#define itfr { o << "[";for(auto e : v) o << e << ", "; o<<"\b\b]"; return o;}
void err(istream_iterator<string> it) { cerr << "\b\b ]\n";}
tmpt , class... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << ": "  << a << ", "; err(++it, args...); }
tmpt > ostop , const vector<T> &v) itfr
tmpt > ostop , const set<T> &v) itfr
tmpt , class V> ostop , const map<T,V> &v) itfr
tmpt , class V> ostop , const pair<T,V> &p) { o << "(";o << p.first << ", " << p.second << ")"; return o;}

bool solve(const vector<int> &nums, int target) {
	int low = 0, n = nums.size(), high = n-1;
	while(low < high) {
		int mid = (low + high) / 2;
		debug("befr", low, mid, high, nums[mid], nums[high])
		if(nums[mid] == nums[high])
			high --;
		else if(nums[mid] > nums[high])
			low = mid + 1;
		else
			high = mid;
		debug("aftr", low, mid, high, nums[mid], nums[high])
	}
	int idx = high;
	auto f = [&](int l, int h) {
		while(l <= h) {
			int m = (h+l)/2;
			if(nums[m] == target)
				return true;
			else if(nums[m] > target)
				h = m-1;
			else
				l = m + 1;
		}
		return false;
	};
	return f(0,idx-1) || f(idx, n-1);
}

void solve() {
	int n, target;
	//cin >> n;
	//vector<int> a(n);
	vector<int> a{1,1,1,1,1,1,1,2,1,1,1};
	target = 2;
	//for(int & i : a)
		//cin >> i;
	//cin >> target;
	bool got = solve(a,target), g = false;
	for(int i : a)
		if(target == i)
			g = true;
	assert(got == g);
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

