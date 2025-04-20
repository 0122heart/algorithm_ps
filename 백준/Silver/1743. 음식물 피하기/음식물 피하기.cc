#include <bits/stdc++.h>

using namespace std;

bool board[100][100];
int num_of_rows, num_of_cols, num_of_trash, result = 0;
int d_row[] = {1, 0, -1, 0}, d_col[] = {0, 1, 0, -1};

void bfs(int r, int c){
    int temp = 1;
    queue<pair<int, int>> frontier;
    frontier.emplace(r, c);
    while(!frontier.empty()){
        pair<int, int> now = frontier.front(); frontier.pop();
        for(int d = 0; d < 4; d++){
            int next_r = now.first + d_row[d];
            int next_c = now.second + d_col[d];
            if(next_r < 0 || num_of_rows <= next_r || next_c < 0 || num_of_cols <= next_c) continue;
            if(!board[next_r][next_c]) continue;
            board[next_r][next_c] = false;
            frontier.emplace(next_r, next_c);
            temp++;
        }
    }
    if(result < temp) result = temp;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> num_of_rows >> num_of_cols >> num_of_trash;
    while(num_of_trash--){
        int r, c;
        cin >> r >> c;
        board[r - 1][c - 1] = true;
    }
    for(int r = 0; r < num_of_rows; r++){
        for(int c = 0; c < num_of_cols; c++){
            if(board[r][c]){
                board[r][c] = false;
                bfs(r, c);
            }
        }
    }
    cout << result;
}