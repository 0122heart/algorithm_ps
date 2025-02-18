#include <bits/stdc++.h>
using namespace std;

int num_of_rows, num_of_cols, no_tomato = 0;
vector<vector<int>> board;
queue<pair<int, int>> frontier;
int d_row[] = {1, 0, -1, 0}, d_col[] = {0, 1, 0, -1};

void setting() {
    cin >> num_of_cols >> num_of_rows;
    board.assign(num_of_rows, vector<int>(num_of_cols, 0));
    int tomato, riped = 0;

    for (int i = 0; i < num_of_rows; i++) {
        for (int j = 0; j < num_of_cols; j++) {
            cin >> tomato;
            board[i][j] = tomato;
            if (tomato == 1) {
                frontier.emplace(i, j);  // 익은 토마토를 큐에 바로 추가
                riped++;
            } else if (tomato == -1) {
                no_tomato++;
            }
        }
    }

    // 모든 토마토가 이미 익어있는 경우
    if (no_tomato + riped == num_of_cols * num_of_rows) {
        cout << 0;
        exit(0);
    }
}

bool check_boundary(int row, int col) {
    return 0 <= row && row < num_of_rows && 0 <= col && col < num_of_cols;
}

void bfs() {
    while (!frontier.empty()) {
        auto [cur_row, cur_col] = frontier.front();
        int now_value = board[cur_row][cur_col];
        frontier.pop();

        for (int direction = 0; direction < 4; direction++) {
            int next_row = cur_row + d_row[direction];
            int next_col = cur_col + d_col[direction];

            if (check_boundary(next_row, next_col) && board[next_row][next_col] == 0) {
                board[next_row][next_col] = now_value + 1;
                frontier.emplace(next_row, next_col);
            }
        }
    }
}

void make_result() {
    int result = 0;
    for (auto& row : board) {
        for (int value : row) {
            if (value == 0) {  // 익지 않은 토마토가 있음
                cout << -1;
                return;
            }
            result = max(result, value);
        }
    }
    cout << result - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    setting();
    bfs();
    make_result();
    return 0;
}
