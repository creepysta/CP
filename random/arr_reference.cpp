#include <iostream>

using namespace std;

void display(int (&a)[5])
{
	for(int i=0;i<5;i++)
		printf("%d\n",a[i]);
}

int main()
{
	int a[5] = {1,2,3,4,5};
	display(a);
	return 0;
}
