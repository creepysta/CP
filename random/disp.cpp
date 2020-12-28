#include <bits/stdc++.h>
using namespace std;

int main() {
	int height = 3, nodes = (1<<3) - 1, 
		last_level = nodes - (1<<(height-1)) - 1;
	int node = 1;
	for(int i = 0; i < height; i++) {
		string num = to_string(node);
		for(int j = 0; j < (1 << i); j++) {
			//cout << setw(1 << (height - i)) << right << node;
			node ++;
		}
		cout << endl;
	}
}
