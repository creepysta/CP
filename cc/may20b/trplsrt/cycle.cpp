#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
	//vector<int> a = {-1,2,1,5,3,4};
	//vector<int> a = {-1,5,4,2,1,3};
	//vector<int> a = {-1,2,1,5,7,6,11,4,10,3,9,8};
	//vector<int> a = {-1,5,4,3,2,1};
	//vector<int> a = {-1,4,1,2,3,6,5};
	
	int n = 7;
	//cin >> n;
	//vector<int> a(n+1, 0);
	vector<int> a = {-1, 5,2,1,3,4,7,6};
	vector<int> cycle(n+1, 0);
	//for(ll i=1; i <=n; i++) {
		//cin >> a[i];
	//}
	int c = 1;
	vector<vector<int>> cc;
	for(int i = 1;i <= n; i++) {
		int prev = a[i];
		int ptr = i;
		if(!cycle[ptr]) {
			ll mem = 0;
			vector<int> temp;	
			do {
				//cout << ptr << endl;
				temp.push_back(ptr);
				ptr = a[ptr];
				cycle[ptr] = c;
				mem++;
			} while(prev != a[ptr]);
			if(mem==1)
				cycle[ptr] = 0;
			else {
				c++;
				cc.push_back(temp);
			}
		}
	}
	for(int i=0; i < (int) cc.size(); i++) {
		for(int j=0; j < (int) cc[i].size(); j++) {
			cout << cc[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
