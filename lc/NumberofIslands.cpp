#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
	int count = 0;
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[i].size(); j++) {
			if(grid[i][j] == '1') {
				count += 1;
				remIsland(grid, i, j);
			}
		}
	}
	return count;
}
void remIsland(vector<vector<char>>& grid, int i, int j) {
	if(i <0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0')
		return;
	grid[i][j] = '0';
	remIsland(grid, i-1, j);
	remIsland(grid, i+1, j);
	remIsland(grid, i, j-1);
	remIsland(grid, i, j+1);
}

int main() {
	vector<vector<char>> grid = {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}};
	
	cout << numIslands(&grid);
	
	return 0;
}
