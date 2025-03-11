// 4179

#include <bits/stdc++.h>
using namespace std;

int num_of_rows, num_of_cols;
string board[1000];
int fire_board[1000][1000], jihun_board[1000][1000];
int d_row[] = {1, 0, -1, 0}, d_col[] = {0, 1, 0, -1};
queue<pair<int, int>> fire, jihun;

void setting(){
    cin >> num_of_rows >> num_of_cols;
    for(int i = 0; i < num_of_rows; i++){
        cin >> board[i];
        fill(fire_board[i], fire_board[i] + num_of_cols, -1);
        fill(jihun_board[i], jihun_board[i] + num_of_cols, -1);
        for(int j = 0; j < num_of_cols; j++){
            if(board[i][j] == 'F'){
                fire.emplace(i, j);
                fire_board[i][j] = 0;
            }
            else if(board[i][j] == 'J'){
                jihun.emplace(i, j);
                jihun_board[i][j] = 0;
            }
        }
    }
}

void bfs_fire(){
    while(!fire.empty()){
        pair<int, int> now = fire.front(); fire.pop();
        for(int dir = 0; dir < 4; dir++){
            int n_row = now.first + d_row[dir];
            int n_col = now.second + d_col[dir];
            if(n_row < 0 || num_of_rows <= n_row || n_col < 0 || num_of_cols <= n_col) continue;
            if(fire_board[n_row][n_col] != -1 || board[n_row][n_col] == '#') continue;
            fire_board[n_row][n_col] = fire_board[now.first][now.second] + 1;
            fire.emplace(n_row, n_col);
        }
    }
}

void bfs_jihun(){
    while(!jihun.empty()){
        pair<int, int> now = jihun.front(); jihun.pop();
        for(int dir = 0; dir < 4; dir++){
            int n_row = now.first + d_row[dir];
            int n_col = now.second + d_col[dir];
            if(n_row < 0 || num_of_rows <= n_row || n_col < 0 || num_of_cols <= n_col){
                cout << jihun_board[now.first][now.second] + 1;
                return;
            }
            if(jihun_board[n_row][n_col] != -1 || board[n_row][n_col] == '#') continue;
            if(fire_board[n_row][n_col] != -1 && fire_board[n_row][n_col] <= jihun_board[now.first][now.second] + 1) continue;
            jihun_board[n_row][n_col] = jihun_board[now.first][now.second] + 1;
            jihun.emplace(n_row, n_col);
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    setting();
    bfs_fire();
    bfs_jihun();
    return 0;
}