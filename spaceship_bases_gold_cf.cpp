#include <bits/stdc++.h>
using namespace std;

bool sortvec(vector<long> &v1, vector<long> &v2) {
	return v1[0] < v2[0];
}

int main()
{

	long s, b;
	cin >> s >> b;

	vector<long> spaceships;
	vector<vector<long>> base_golds(b);
	vector<long> gold;


	for(long i = 0; i < s; i++) {
		long temp;
		cin >> temp;
		spaceships.push_back(temp);
	}
	for(long i =0; i < b; i++) {
		base_golds[i] = vector<long>(2);
		long t1, t2;
		cin >> t1 >> t2;
		base_golds[i][0] = t1;
		base_golds[i][1] = t2;
	}
	
	sort(base_golds.begin(), base_golds.end(), sortvec);

	for(long i = 0; i < s; i++) {
		long sum = 0;
		for(long j = 0; spaceships[i] >= base_golds[j][0]; j++) {
			sum += base_golds[j][1];
		}
		cout << sum << " ";
	}
	cout << endl;

	return 0;
}
