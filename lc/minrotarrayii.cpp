/*
	author: Creepysta
	25-03-2021 23:10:48
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

int rep(const vector<int>& nums) {
	int n = nums.size();
	int low = 0, high = n -1;
	while(low<high) {
		int mid = (low + high) / 2;
		if(nums[mid] == nums[high])
			high--;
		else if(nums[mid] > nums[high]) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	return nums[low];
}

int uniq(const vector<int> &nums) {
	//int n = nums.size();
	//int low = 0, high = n-1;
	//while(low < high) {
		//int mid = (low + high) / 2;
		//if(nums[mid] > nums[high]) {
			//low = mid+1;
		//} else {
			//high = mid;
		//}
	//}
	//return nums[low];
	int n = nums.size();
	int low = 0, high = n-1, ans = -1;
	while(low <= high) {
		int mid = (low + high) / 2;
		debug("before",low,high,mid,nums[mid],nums[n-1])
		if(nums[mid] > nums[n-1]) {
			low = mid+1;
		} else {
			ans = mid;
			high = mid-1;
		}
		debug("after", low,high,mid,nums[mid],nums[n-1])
	}
	return nums[ans];
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 10000;
#ifndef LOCAL
	cin >> t;
#endif
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
#ifndef LOCAL
		int m;
		cin >> m;
		vector<int> nums(m);
		for(int &i : nums)
			cin >> i;
		int ans = rep(nums);
		cout << ans << '\n';
#else
		mt19937 rng(tt);
		int n = 10, x = rng() % 100;
		vector<int> a(n);
		set<int> s;
		for(int i = 0; i < n; i++) {
			/* for rep */
			if(rng() % 100 > 30)
				x = rng() % 100;
			a[i] = x;
			/* for uniq */
			//while(s.find(x) != s.end())
				//x = rng()%100;
			//a[i] = x;
			//s.insert(x);
		}
		sort(a.begin(), a.end());
		int k = 0;
		do {
			debug(a);
			//int got = uniq(a);
			int got = rep(a);
			int ans = *min_element(a.begin(), a.end());
			bool ok = got == ans;
			debug(got, ans);
			cout << boolalpha << ok << endl;
			if(!ok) {
				getchar();
				//return 0;
			}
			k++;
			rotate(a.begin(), a.begin() + n-1, a.end());
		//} while(next_permutation(a.begin(), a.end()));
		} while(k <= n);
#endif
	}
	return 0;
}


