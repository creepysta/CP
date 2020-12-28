#include <iostream>
#include<map>
#include<iterator>

using namespace std;

map<int, string> table = {{1,"one"},{2,"two"}, {3,"three"},{4,"four"},{5,"five"}};
map<int, string>::iterator it;

void acceptNumber() {
	int i;
	cin >> i;
	it = table.find(i);
	if(it != table.end()) {
		cout<<table.find(i)->second<<endl;
		return;
	}
	throw "Number is not available\n";
}

int main()
{
	int i=0,j;
	try {
		acceptNumber();
	}
	catch(char const *msg) {
		cout<<msg;
	}
	return 0;
}
