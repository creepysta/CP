#include <bits/stdc++.h>
using namespace std;


main()
{
	vector<int> v = {5,1,2,4,3,3,11,4,4,1};
	// int v[] = {5,1,2,4,3,3,11,4,4,1};
	int max =  *std::max_element(v.begin(), v.end());
	cout << max;
	// cout << std::distance(v.begin(), (std::max_element(v.begin(), v.end())));
}
