#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int **points = new int*[4 * n + 1];
	for(int i = 0; i < 4 * n + 1; i++) {
		points[i] = new int[2];
		cin >> points[i][0] >> points[i][1];
	}
	for(int i = 0; i < 4 * n + 1; i++) {
		bool fi = points[i][0] > 0 && points[i][0] < n;
		bool fo = points[i][0] > n || points[i][0] < 0;
		bool si = points[i][1] > 0 && points[i][1] < n;
		bool so = points[i][1] > n || points[i][1] < 0;

		if((fi && si) || (fo || so)) {
			cout << points[i][0] << " " << points[i][1] << endl;
			break;
		}
	}

	delete points;

	return 0;
}
