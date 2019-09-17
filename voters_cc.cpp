/*
 * 
 * https://www.codechef.com/problems/VOTERS
 */
 /*
  * 5 6 5
	23 30 42 57 90
	21 23 35 57 90 92 
	21 23 30 57 90
 
	5
	21 23 30 57 90
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	vector<int> a1(n1);
	vector<int> a2(n2);
	vector<int> a3(n3);
	for(int &i : a1) {
		cin >> i;
	}
	for(int &i : a2) {
		cin >> i;
	}
	for(int &i : a3) {
		cin >> i;
	}
	int i=0, j=0, k=0;
	vector<int> ans;
	while(i < n1 || j < n2 || k < n3) {
		if(a1[i] == a2[j] && a1[i] == a3[k]) {
			ans.push_back(a1[i]);
			i = i < n1 ? i + 1: i; 
			j = j < n2 ? j + 1: j;
			k = k < n3 ? k + 1: k;
		} else if (a1[i] == a2[j]) {
			ans.push_back(a1[i]);
			i = i < n1 ? i + 1: i; 
			j = j < n2 ? j + 1: j;
		} else if (a2[j] == a3[k]) {
			ans.push_back(a2[j]);
			j = j < n2 ? j + 1: j;
			k = k < n3 ? k + 1: k;
		} else if (a1[i] == a3[k]) {
			ans.push_back(a1[i]);
			i = i < n1 ? i + 1: i;
			k = k < n3 ? k + 1: k;
		} else if (a1[i] < a2[j]) {
			i = i < n1 ? i + 1: i;
		} else if (a2[i] < a3[j]) { 
			j = j < n2 ? j + 1: j;
		} else {
			k = k < n3 ? k + 1: k;
		}
	}
	sort(ans.begin(), ans.end());
	auto it = unique(ans.begin(), ans.end());
	ans.resize(distance(ans.begin(), it));
	cout << ans.size() << '\n';
	for(int a : ans) {
		cout << a << '\n';
	}
	
	//int n = n1 + n2 + n3;
	//vector<int> a(n);
	//for(int &i : a) {
		//cin >> i;
	//}
	//vector<int> temp = a;
	//sort(temp.begin(), temp.end());
	//auto it = unique(temp.begin(), temp.end());
	//temp.resize(distance(temp.begin(), it));
	//int d = (int) temp.size();
	//int c = 0;
	//vector<int> ans;
	//for(int i = 0; i < d; i ++) {
		//c = count(a.begin(), a.end(), temp[i]);
		//if(c > 1) {
			//ans.push_back(temp[i]);
		//}
	//}
	//cout << ans.size() << '\n';
	//for(int i : ans) {
		//cout << i << '\n';
	//}
	//return 0;
}
