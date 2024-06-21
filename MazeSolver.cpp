#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include <utility>
#include<algorithm>
#include<windows.h>
#include "MazeSolver.h"

using namespace std;

int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};


void changeColor(int desiredColor){ 
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
} 

Maze::Maze(int n_,int m_,vector<vector<char>>maze_):n(n_),m(m_),maze(maze_){}
bool Maze::check(int x,int y){
		return (x>=0 && x<n && y>=0 && y<m && maze[x][y]!='#');
}

bool Maze::pathFinderUsingBfs(int sx,int sy,int ex,int ey){
		queue<pair<int,int>>q;
		bool vis[n][m];
		bool ok=false;
		pair<int,int>parent[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				vis[i][j]=0;
				parent[i][j]={-1,-1};
			}
		}
		q.push({sx,sy});
		vis[sx][sy]=1;
		while(!q.empty()){
			pair<int,int>p=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int nx=p.first+dx[i],ny=p.second+dy[i];
				if (check(nx,ny) && !vis[nx][ny]){
					vis[nx][ny]=1;
					q.push({nx,ny});
					parent[nx][ny]={p.first,p.second};
					if (nx==ex && ny==ey){
						ok=true;
						break;
					}
				}
			}
		}
		if (ok==false){
			return 0;
		}
		string ans;
		int curx=ex,cury=ey;
		maze[curx][cury]='X';
		while(parent[curx][cury]!=make_pair(-1,-1)){
			pair<int,int>p=parent[curx][cury];
			if (curx-p.first==0){   //same row 
				if (cury>p.second) ans+='R';
				else ans+='L';
			}
			else { // same column
				if (curx>p.first) ans+='D';
				else ans+='U';
			}
			curx=p.first;
			cury=p.second;
			maze[curx][cury]='X';
		}
		reverse(ans.begin(),ans.end());
		return 1;
}


void Maze::output(){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if (maze[i][j]=='X'){
					changeColor(1);
				}
				else {
					changeColor(7);
				}
				cout<<maze[i][j];
			}
			cout<<endl;
		}
	changeColor(7);
}