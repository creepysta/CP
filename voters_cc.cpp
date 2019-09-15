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
	//vector<int> a1(n1);
	//vector<int> a2(n2);
	//vector<int> a3(n3);
	//vector<int> ans;
	//for(int i=0; i < n1 ; i++) {
		//scanf("%d", &a1[i]);
	//}
	//for(int i=0; i < n2 ; i++) {
		//scanf("%d", &a2[i]);
		//if(find(a1.begin(), a1.end(), a2[i]) != a1.end() && (ans.empty() || find(ans.begin(), ans.end(), a2[i]) == ans.end())) {
			//ans.push_back(a2[i]);
		//}
	//}
	//for(int i=0; i < n3 ; i++) {
		//scanf("%d", &a3[i]);
		//if((find(a1.begin(), a1.end(), a3[i]) != a1.end() || find(a2.begin(), a2.end(), a3[i]) != a2.end()) && (ans.empty() || find(ans.begin(), ans.end(), a3[i]) == ans.end())) {
			//ans.push_back(a3[i]);
		//}
	//}
	//sort(ans.begin(), ans.end());
	//cout << ans.size() << '\n';
	//for(int i : ans) {
		//cout << i << '\n';
	//}
	
	int n = n1 + n2 + n3;
	vector<int> a(n);
	for(int &i : a) {
		cin >> i;
	}
	vector<int> temp = a;
	sort(temp.begin(), temp.end());
	auto it = unique(temp.begin(), temp.end());
	temp.resize(distance(temp.begin(), it));
	int d = (int) temp.size();
	int c = 0;
	vector<int> ans;
	for(int i = 0; i < d; i ++) {
		c = count(a.begin(), a.end(), temp[i]);
		if(c > 1) {
			ans.push_back(temp[i]);
		}
	}
	cout << ans.size() << '\n';
	for(int i : ans) {
		cout << i << '\n';
	}
	return 0;
}
