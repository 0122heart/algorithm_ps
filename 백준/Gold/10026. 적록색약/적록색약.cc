// 10026

#include <bits/stdc++.h>
#define ROW first
#define COL second
using namespace std;

int N;
int d_row[] = {1, 0, -1, 0}, d_col[] = {0, 1, 0, -1};
string board[100];
queue<pair<int, int>> red, red2, green, blue;

void setting(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> board[i];
        for(int j = 0; j < N; j++){
            if(board[i][j] == 'R'){
                red.emplace(i, j);
                red2.emplace(i, j);
            }
            else if(board[i][j] == 'G'){
                green.emplace(i, j);
                red2.emplace(i, j);
            }
            else blue.emplace(i, j);
        }
    }
}

bool check_boundary(int row, int col){
    return 0 <= row && row < N && 0 <= col && col < N;
}

int bfs(queue<pair<int, int>>& q_of_targets, char target, char target2 = '.'){
    int result = 0;
    bool visited[100][100];
    for(int i = 0; i < N; i++) fill(visited[i], visited[i] + N, false);

    while(!q_of_targets.empty()){
        pair<int, int> now = q_of_targets.front(); q_of_targets.pop();

        // 이미 방문 했다면
        if(visited[now.ROW][now.COL]) continue;

        // 아직 방문 X
        result += 1;
        queue<pair<int, int>> frontier;
        frontier.push(now);
        visited[now.ROW][now.COL] = true;

        while(!frontier.empty()){
            now = frontier.front(); frontier.pop();
            for(int dir = 0; dir < 4; dir++){
                int next_row = now.ROW + d_row[dir];
                int next_col = now.COL + d_col[dir];
                if(check_boundary(next_row, next_col) &&
                    visited[next_row][next_col] == false &&
                    (board[next_row][next_col] == target || board[next_row][next_col] == target2)){
                    visited[next_row][next_col] = true;
                    frontier.emplace(next_row, next_col);
                }
            }
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    setting();
    int normal = bfs(blue, 'B');
    int abnormal = normal;
    normal += bfs(red, 'R') + bfs(green, 'G');
    abnormal += bfs(red2, 'R', 'G');
    cout << normal << " " << abnormal;
    return 0;
}