/*
 * Longest Increasing Subsequence
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a = {50, 3, 10, 7, 40, 80};

	int temp = -1;
	int count = 1, mCount = INT_MIN;
	int f = 0;
	int c= 0;

	while(c < a.size()) {
		c += 1;
		temp += 1;
		f = 0;
		count = 1;
		for(int i = c; i < a.size(); i++) {

			if(a[temp] < a[i]) {
				f = 0;
				temp = i;
				count ++;
			} else {
				if(f < 1) {
					temp = i-1;
				}
				f+= 1;
			}
			cout << a[i] << "\t" << temp << "\t" << count <<  endl;
		}
		cout << count << endl;
		if(mCount <= count) {
			mCount = count;
		}
	}

	cout << mCount << endl;

	return 0;
}
