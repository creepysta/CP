#include<iostream>
using namespace std;

int main()
{
/*	char *s = "sam";
	cout << s << endl;
	s++;
	cout << s << endl;
*/
	
	int *num,i;
	num = new int[10];
	for(i=0;i<10;i++)
		num[i] = i+1;

	for(i=0;i<10;i++)
		cout<<num[i]<<endl;

	delete [] num;
	
	for(i=0;i<10;i++)
		cout<<num[i]<<endl;

	return 0;
}
