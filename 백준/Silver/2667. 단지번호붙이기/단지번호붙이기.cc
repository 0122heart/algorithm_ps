// 2667

#include <bits/stdc++.h>

using namespace std;

int num_of_rows, result = 0, d_row[] = {1, 0, -1, 0}, d_col[] = {0, 1, 0, -1};
vector<int> results;
string board[25];
bool visited[25][25];

void setting(){
    cin >> num_of_rows;
    for(int i = 0; i < num_of_rows; i++){
        cin >> board[i];
        fill(visited[i], visited[i] + num_of_rows, false);
    }
}

int bfs(int row, int col){
    int width = 1;
    visited[row][col] = true;
    queue<pair<int, int>> frontier;
    frontier.emplace(row, col);
    while(!frontier.empty()){
        pair<int, int> now = frontier.front(); frontier.pop();
        for(int dir = 0; dir < 4; dir++){
            int n_row = now.first + d_row[dir];
            int n_col = now.second + d_col[dir];
            if(n_row < 0 || num_of_rows <= n_row || n_col < 0 || num_of_rows <= n_col ||
                visited[n_row][n_col] ||
                board[n_row][n_col] == '0') continue;
            width += 1;
            visited[n_row][n_col] = true;
            frontier.emplace(n_row, n_col);
        }
    }
    return width;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    setting();
    for(int i = 0; i < num_of_rows; i++){
        for(int j = 0; j < num_of_rows; j++)
            if(board[i][j] == '1' && !visited[i][j]){
                result += 1;
                results.push_back(bfs(i, j));
            }
    }
    sort(results.begin(), results.end());
    cout << result << "\n";
    for(auto i : results) cout << i << "\n";
    return 0;
}