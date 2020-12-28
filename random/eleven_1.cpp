#include<bits/stdc++.h>
#include<fstream>
using namespace std;

main()
{
	// i)
	ofstream outfile;
	outfile.open("myfile.txt");
	for(int i=0;i<10;i++) {
		outfile << (rand()%10)+1<<" ";
	}
	outfile.close();

	// ii)
	outfile.open("myfile.txt",ios::app);
	for(int i=0;i<10;i++)
		outfile<< rand()%20 + 1 << " ";
	outfile.close();

	int a[100];

	ifstream infile;
	infile.open("myfile.txt");
	infile >> a;
	infile.close();
}