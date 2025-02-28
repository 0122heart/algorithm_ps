// 7562

#include <bits/stdc++.h>
#define ROW first
#define COL second

using namespace std;

int num_testcases, size_of_board;
pair<int, int> start, target;
int visited[300][300];
int d_row[] = {1, 1, 2, 2, -1, -1, -2, -2}, d_col[] = {2, -2, 1, -1, 2, -2, 1, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_testcases;
    while(num_testcases--){
        cin >> size_of_board;
        cin >> start.ROW >> start.COL;
        cin >> target.ROW >> target.COL;
        for(int i = 0; i < size_of_board; i++) fill(visited[i], visited[i] + size_of_board, -1);
        if(start == target) cout << 0 << "\n";
        queue<pair<int, int>> frontier;
        frontier.push(start);
        visited[start.first][start.second] = 0;
        while(!frontier.empty()){
            pair<int, int> now = frontier.front();
            frontier.pop();
            for(int dir = 0; dir < 8; dir++){
                int n_row = now.first + d_row[dir];
                int n_col = now.second + d_col[dir];
                if(n_row < 0 || size_of_board <= n_row || n_col < 0 || size_of_board <= n_col || visited[n_row][n_col] != -1) continue;
                if(n_row == target.first && n_col == target.second) cout << visited[now.first][now.second] + 1 << "\n";
                frontier.emplace(n_row, n_col);
                visited[n_row][n_col] = visited[now.first][now.second] + 1;
            }
        }
    }
    return 0;
}