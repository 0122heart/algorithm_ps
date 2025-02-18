#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;
int the_num_of_rows, the_num_of_cols, the_num_of_drawing = 0, max_size_of_drawing = 0;
int d_row[] = {1, 0, -1, 0}, d_col[] = {0, 1, 0, -1};

void setting() {
    cin >> the_num_of_rows >> the_num_of_cols;
    
    board.resize(the_num_of_rows, vector<int>(the_num_of_cols));
    visited.assign(the_num_of_rows, vector<bool>(the_num_of_cols, false));

    for(int i = 0; i < the_num_of_rows; i++) {
        for(int j = 0; j < the_num_of_cols; j++) {
            cin >> board[i][j];
        }
    }
}

bool check_boundary(int row, int col) {
    return 0 <= row && row < the_num_of_rows && 0 <= col && col < the_num_of_cols;
}

void bfs(pair<int, int> start) {
    queue<pair<int, int>> frontier;
    frontier.push(start);
    visited[start.first][start.second] = true;
    
    int size = 1; // 처음 방문한 노드 포함

    while(!frontier.empty()) {
        pair<int, int> cur = frontier.front();
        frontier.pop();
        
        for(int direction = 0; direction < 4; direction++) {
            int cur_row = cur.first + d_row[direction];
            int cur_col = cur.second + d_col[direction];

            if(check_boundary(cur_row, cur_col) && board[cur_row][cur_col] && !visited[cur_row][cur_col]) {
                visited[cur_row][cur_col] = true;
                frontier.push(make_pair(cur_row, cur_col));
                size += 1;
            }
        }
    }

    max_size_of_drawing = max(max_size_of_drawing, size);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    setting();

    for(int row = 0; row < the_num_of_rows; row++) {
        for(int col = 0; col < the_num_of_cols; col++) {
            if(!visited[row][col] && board[row][col]) {
                bfs(make_pair(row, col));
                the_num_of_drawing += 1;
            }
        }
    }

    cout << the_num_of_drawing << "\n" << max_size_of_drawing;
    return 0;
}
