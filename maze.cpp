#include<bits/stdc++.h>
using namespace std;

bool canReach(int maze[5][5], int r, int c){
	if(maze[r][c] == 'E')
		return true;

	if(maze[r][c] == '*')
		return false;

	maze[r][c] = '*';

	// up
	if(r-1 >= 0)
		if(canReach(maze, r-1, c))
			return true;

	// down
	if(r+1 <= 4)
		if(canReach(maze, r+1, c))
			return true;

	/// left
	if(c-1 >= 0)
		if(canReach(maze, r, c-1))
			return true;

	// right
	if(c+1 <= 4)
		if(canReach(maze, r, c+1))
			return true;


	return false;
}

signed main(){
	int maze[5][5] = {
		{'*','*','*','*','E'},
		{'*','S',' ','*',' '},
		{' ','*',' ','*',' '},
		{'*',' ',' ',' ',' '},
		{' ','*',' ','*','*'},
	};

	if(canReach(maze, 1, 1)){
		cout<<"Path Exists";
	}else{
		cout<<"Path doesn't Exists";
	}

	return 0;
}