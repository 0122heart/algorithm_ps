#include<bits/stdc++.h>
using namespace std;

int d_row[] = {1, 0, -1, 0}, d_col[] = {0, 1, 0, -1};
int step[100][100];

int bfs(vector<vector<int>>& maps){
    // setting
    int num_of_rows = maps.size();
    int num_of_cols = maps[0].size();
    for(int i = 0; i < num_of_rows; i++) fill(step[i], step[i] + num_of_cols, -1);
    queue<pair<int, int>> frontier;
    frontier.emplace(0, 0);
    step[0][0] = 1;
    
    // bfs
    while(!frontier.empty()){
        auto now = frontier.front(); frontier.pop();
        
        // exit condition
        if(now.first == num_of_rows - 1 && now.second == num_of_cols - 1){
            return step[now.first][now.second];
        }
        
        // next
        for(int dir = 0; dir < 4; dir++){
            int n_row = now.first + d_row[dir];
            int n_col = now.second + d_col[dir];
            if(n_row < 0 || num_of_rows <= n_row || n_col < 0 || num_of_cols <= n_col) continue;
            if(!maps[n_row][n_col] || step[n_row][n_col] != -1) continue;
            frontier.emplace(n_row, n_col);
            step[n_row][n_col] = step[now.first][now.second] + 1;
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = bfs(maps);
    return answer;
}