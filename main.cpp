#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include <utility>
#include<algorithm>
#include<windows.h>
#include"MazeSolver.h"


using namespace std;




int main(){
	vector<vector<char>> grid={
		{'.','.','.','.','#','.','.','.'},
		{'#','#','#','.','.','.','#','.'},
		{'.','#','#','#','#','#','#','.'},
		{'.','#','#','#','#','#','#','.'},
		{'.','.','.','.','.','.','.','.'},
	};
	Maze m(5,8,grid);
	if (m.pathFinderUsingBfs(0,0,4,7))m.output();

	// for(int i=0;i<5;i++){
	// 	for(int j=0;j<8;j++){
	// 		if (i==1 ){
	// 			changeColor(1);
	// 			cout <<grid[i][j]; // with color green
	// 		}
	// 		else {
	// 			changeColor(7);
	// 			cout<<grid[i][j]; //normal color
	// 		}
			
	// 	}
	// 	cout<<endl;
	// }

}