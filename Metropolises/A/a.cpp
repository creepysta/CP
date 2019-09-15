#include <bits/stdc++.h>
using namespace std;

int binsrch(vector<int> v, int k) {
	int i = 0;
	int j = v.size()-1;
	int m =(i + j) / 2;
	
	while(i < j) {
		if(v[m] == k) {
			return m;
		}
		else if(k < v[m]) {
			j = m;
		}
		else if(k > v[m]) {
			i = m;
		}
		m = (i + j) / 2;
		//cout << i  << " "<< j << " "<< m << endl;
		if(m == i) {
			return m;
		}
	}
	
	return m;
}

int main() {
	vector<int> dollar = {1 , 2, 5, 10, 20, 50, 100};
	vector<int> euro = { 5, 10, 20, 50, 100, 200};
	
	int n, d, e;
	cin >> n >> d >> e;
	
	int td, te;
	td = n / d;
	te = n / e;
	
	int id = binsrch(dollar, td); 
	int ie = binsrch(euro, te);
	
	int temp1 = n - d*dollar[id] >= 0 ? n - d*dollar[id] : n;
	temp1 = temp1 >= temp1 - e*euro[binsrch(euro, temp1/e)] && temp1 - e*euro[binsrch(euro, temp1/e)] >= 0 ? temp1 - e*euro[binsrch(euro, temp1/e)] : temp1;
	
	int temp2 = n - e*euro[ie] >= 0 ? n - e*euro[ie] : n;
	temp2 = temp2 >= temp2 - d*dollar[binsrch(dollar, temp2/d)] && temp2 - d*dollar[binsrch(dollar, temp2/d)] >= 0 ? temp2 - d*dollar[binsrch(dollar, temp2/d)] : temp2;
	
	int minr = min(temp1, temp2);
	
	cout << minr << endl;
	
	return 0;
}
