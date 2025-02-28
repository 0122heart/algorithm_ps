// 2583

#include <bits/stdc++.h>

using namespace std;

int num_of_rows, num_of_cols, num_of_blocked, result, coordi_of_blocked[4];
int d_row[] = {1, 0, -1, 0}, d_col[] = {0, 1, 0, -1};
vector<int> results;
bool board[101][101];

void setting(){
    cin >> num_of_rows >> num_of_cols >> num_of_blocked;
    for(int i = 0; i < num_of_rows; i++) fill(board[i], board[i] + num_of_cols, true);
    for(int i = 0; i < num_of_blocked; i++){
        int start_col, end_col, start_row, end_row;
        cin >> start_col >> start_row >> end_col >> end_row;
        for(int j = start_row; j < end_row; j++) fill(board[j] + start_col, board[j] + end_col, false);
    }
}

int bfs(int row, int col){
    int width = 1;
    queue<pair<int, int>> frontier;
    frontier.emplace(row, col);
    board[row][col] = false;
    while(!frontier.empty()){
        pair<int, int> now = frontier.front();
        frontier.pop();
        for(int dir = 0; dir < 4; dir++){
            int n_row = now.first + d_row[dir];
            int n_col = now.second + d_col[dir];
            if(n_row < 0 || num_of_rows <= n_row || n_col < 0 || num_of_cols <= n_col || board[n_row][n_col] == false) continue;
            width += 1;
            frontier.emplace(n_row, n_col);
            board[n_row][n_col] = false;
        }
    }
    return width;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    setting();
    for(int i = 0; i < num_of_rows; i++){
        for(int j = 0; j < num_of_cols; j++){
            if(board[i][j]){
                result += 1;
                results.push_back(bfs(i, j));
            }
        }
    }
    sort(results.begin(), results.end());
    cout << result << "\n";
    for(auto i : results) cout << i << " ";
    return 0;
}