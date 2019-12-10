//
// Created by william  on 12/9/19.
//

#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H
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
using namespace std;
#define mmm 9//row
#define nnn 9
#define down 1
#define rightM 2
#define leftM 4
#define up 8
typedef pair<int, int> pii;
class Maze{

public:
    vector <int> block_row;
    vector <int> block_column;
    vector <int> block_direct;
    struct xyPoint{
        int x;
        int y;
    }start,end;

    int x_num=1,y_num=1;
    int a[100][100];
    void init(){//将地图全部置1=wall
        for(int i=0;i<=mmm+1;i++){
            for(int j=0;j<=nnn+1;j++){
                a[i][j]=1;//wall
            }
        }
        a[1][1]=2;
        start.x=1;//定义起始点
        start.y=1;
    }
    void push_into_vec(int x,int y,int direct){//把一组数据存放进三个vector容器中
        block_row.push_back(x);
        block_column.push_back(y);
        block_direct.push_back(direct);
    }
    int count(){//计算当前位置周围 墙的个数
        int cnt=0;
        if(x_num+1<=mmm){
            push_into_vec(x_num+1,y_num,down);
            cnt++;
        } //down
        if(y_num+1<=nnn){
            push_into_vec(x_num,y_num+1,rightM);
            cnt++;
        } //rightM
        if(x_num-1>=1){
            push_into_vec(x_num-1,y_num,up);
            cnt++;
        } //up
        if(y_num-1>=1){
            push_into_vec(x_num,y_num-1,leftM);
            cnt++;
        } //leftM
        return cnt;
    }

    vector<vector<int>> generateMaze(){
        init();
        srand((unsigned)time(NULL));//随机数种子
        count();
        while(block_row.size()){//第一步压入两堵墙（起点右边和起点下面）进入循环
            int num=block_row.size();
            int randnum=rand()%num;//生成0-num-1之间的随机数，同时也是vector里的下标
            x_num=block_row[randnum];
            y_num=block_column[randnum];
            switch(block_direct[randnum]){//选择一个方向进行后续操作，起始点 邻块 目标块 三块区域在同一直线上 随后移动到目标块的位置
                case down:{
                    x_num++;
                    break;
                }
                case rightM:{
                    y_num++;
                    break;
                }
                case leftM:{
                    y_num--;
                    break;
                }
                case up:{
                    x_num--;
                    break;
                }
            }
            if(a[x_num][y_num]==1){//目标块如果是墙
                a[block_row[randnum]][block_column[randnum]]=2;//打通墙
                a[x_num][y_num]=2;//打通目标块
                count();//再次计算当前位置周围的邻墙个数并保存进vector
            }
            block_row.erase(block_row.begin()+randnum);//删除这堵墙(把用不了的墙删了，对于那些已经施工过了不必再施工了，同时也是确保我们能跳出循环)
            block_column.erase(block_column.begin()+randnum);
            block_direct.erase(block_direct.begin()+randnum);
        }

        for(int i=0;i<=mmm+1;i++){
            printf("%d:\t",i);
            for(int j=0;j<=nnn+1;j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }


        //switch 1->0 2->1 wall removed;
        vector<vector<int>> maze;
        for(int i=1;i<mmm+2;i++){
            vector<int> l;
            for(int j=1;j<nnn+2;j++){
                if(a[i][j]==2){
                    l.push_back(0);
                }else{
                    l.push_back(1);
                }
            }
            maze.push_back(l);

        }

        return maze;

    }
    void dfs(int &min_t, int a[10][10], int m, int n, int i, int j, vector<pii> tmp, vector<vector<int>> visited, vector<vector<pii>> &res)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || a[i][j] == 1 || visited[i][j]) return;

        if (!visited[i][j]) tmp.push_back(make_pair(i, j));

        visited[i][j] = true;

        if (i == m - 1 && j == n - 1)
        {
            res.push_back(tmp);
            if (tmp.size() < min_t)
                min_t = tmp.size();
            return;
        }
        dfs(min_t,a, m, n, i + 1, j, tmp, visited, res);
        dfs(min_t,a, m, n, i - 1, j, tmp, visited, res);
        dfs(min_t,a, m, n, i, j + 1, tmp, visited, res);
        dfs(min_t,a, m, n, i, j - 1, tmp, visited, res);
    }


};
#endif //MAZE_MAZE_H
