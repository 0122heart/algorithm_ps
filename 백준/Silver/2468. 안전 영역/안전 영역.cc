// 2468

int num_of_rows, num_of_cols, heighest = 0, temp_result, result = 1;
int d_row[] = {1, 0, -1, 0}, d_col[] = {0, 1, 0, -1};
int board[100][100];
bool visited[100][100];

#include <bits/stdc++.h>
using namespace std;

void setting(){
    cin >> num_of_rows; num_of_cols = num_of_rows;
    for(int i = 0; i < num_of_rows; i++){
        for(int j = 0; j < num_of_cols; j++){
            cin >> board[i][j];
            heighest = max(heighest, board[i][j]);
        }
    }
}

void bfs(int row, int col){
    visited[row][col] = true;
    queue<pair<int, int>> frontier;
    frontier.emplace(row, col);

    while(!frontier.empty()){
        pair<int, int> now = frontier.front(); frontier.pop();
        for(int dir = 0; dir < 4; dir++){
            int n_row = now.first + d_row[dir];
            int n_col = now.second + d_col[dir];
            if(n_row < 0 || num_of_rows <= n_row || n_col < 0 || num_of_cols <= n_col) continue;
            if(!visited[n_row][n_col] && board[n_row][n_col]){
                board[n_row][n_col]--;
                frontier.emplace(n_row, n_col);
                visited[n_row][n_col] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    setting();
    while(heighest--){
        temp_result = 0;
        for(int i = 0; i < num_of_rows; i++) fill(visited[i], visited[i] + num_of_cols, false);

        for(int i = 0; i < num_of_rows; i++){
            for(int j = 0; j < num_of_cols; j++){
                if(board[i][j] && !visited[i][j]){
                    board[i][j]--;
                    temp_result++;
                    bfs(i, j);
                }
            }
        }
        result = max(result, temp_result);
    }
    cout << result;
    return 0;
}