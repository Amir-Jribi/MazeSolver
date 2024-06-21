
#ifndef MAZESOLVER_H  //file guard to ensure that we are defining mazesolver just once
#define MAZESOLVER_H

#include<iostream>
#include<vector>
using namespace std;

class Maze{
private:
	int n,m;
	vector<vector<char>>maze;
public:
	Maze(int n_,int m_,vector<vector<char>>maze_);
	bool check(int x,int y);
	bool pathFinderUsingBfs(int sx,int sy,int ex,int ey);
	void output();
};


#endif // MAZESOLVER_H