/*
add a&b until b>=0
*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

main()
{
	int n,m;
	int sum1 = 0, sum2 = 0, ans = 0, c = 0;
	vector<int> v1,v2;
	cin>>n>>m;
	for(int i =0;i<n;i++) {
		int num;
		cin>>num;
		v1.push_back(num);
	}
	cout<<"enter v2\n";
	for(int i =0;i<m;i++) {
		int num;
		cin>>num;
		v2.push_back(num);
	}
	c=0;
	for(int i=v1.size()-1;i>=0;i--){
		sum1 += v1[i]*pow(2,c++);
	}
	cout<<sum1<<endl;
	c=0;
	for(int i=v2.size()-1;i>=0;i--){
		sum2 += v2[i]*pow(2,c++);
	}
	cout<<sum2<<endl;
	while(sum2!=0) {
		ans += sum2&sum1;
		sum2 = sum2>>1;
	}
	cout<<ans;
}
