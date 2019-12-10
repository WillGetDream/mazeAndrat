#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include "maze.h"
using namespace std;
/*Prim's algorithm */
int main(){
    int m=9, n=9;
    int a[10][10];
    vector<vector<int>> ms;
    Maze maze;
    ms=maze.generateMaze();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j]=ms.at(i).at(j);
            cout<<ms.at(i).at(j);
        }
        cout<<endl;
    }
    vector<pii> res;
    vector<vector<int>> visited(m, vector<int>(n, false));
    vector<vector<pii>> ret;
    int min_t = 101;
    //random set last one
    //a[4][4]=rand()%2;
    maze.dfs(min_t ,a, m, n, 0, 0, res, visited, ret);

    if(ret.size()>0){
        for (int i = 0; i < ret.size(); i++)
        {
            if (min_t == ret[i].size())
            {
                for (int k = 0; k < min_t; k++)
                {
                    cout << '(' << ret[i][k].first << ',' << ret[i][k].second << ')' << endl;
                }
            }
        }
    }else{
        cout<<"no";
    }


    //ratOfMaze.shortestDistance(mz,b,e);

//    cout<<"Example Input:00,10,20,22,32,42,43";
//    //cin>>input;
//    cout<<"Correct Answer is: "+str<<endl;
//    if(input.compare(str)==0){
//        cout<<"won";
//
//    }
    return 0;
}

