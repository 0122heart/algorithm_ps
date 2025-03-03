// 6593

#include <bits/stdc++.h>
using namespace std;

struct ROOM{
    int layer; int row; int col;
    ROOM(int layer, int row, int col) : layer(layer), row(row), col(col){}
    bool operator==(const ROOM other) const{
        return other.layer == this->layer && other.row == this->row && other.col == this->col;
    }
};

int num_of_layers, num_of_rows, num_of_cols;
string building[30][30];
int board[30][30][30];
int d_layer[] = {1, -1, 0, 0, 0, 0}, d_row[] = {0, 0, 1, 0, -1, 0}, d_col[] = {0, 0, 0, 1, 0, -1};
ROOM start(0, 0, 0), target(0, 0, 0);

void setting(){
    string trash;
    for(int layer = 0; layer < num_of_layers; layer++){
        for(int row = 0; row < num_of_rows; row++){
            cin >> building[layer][row];
            fill(board[layer][row], board[layer][row] + num_of_cols, -1);
            for(int col = 0; col < num_of_cols; col++){
                if(building[layer][row][col] == 'S') start = ROOM(layer, row, col);
                if(building[layer][row][col] == 'E') target = ROOM(layer, row, col);
            }
        }
    }
}

bool check_boundary(int layer, int row, int col){
    return layer < 0 || num_of_layers <= layer ||
        row < 0 || num_of_rows <= row ||
            col < 0 || num_of_cols <= col;
}

void bfs(){
    queue<ROOM> frontier;
    frontier.push(start);
    board[start.layer][start.row][start.col] = 0;

    while(!frontier.empty()){
        ROOM now = frontier.front(); frontier.pop();
        for(int dir = 0; dir < 6; dir++){
            int n_layer = now.layer + d_layer[dir];
            int n_row = now.row + d_row[dir];
            int n_col = now.col + d_col[dir];
            if(check_boundary(n_layer, n_row, n_col)) continue;
            if(building[n_layer][n_row][n_col] == 'E'){
                cout << "Escaped in " << board[now.layer][now.row][now.col] + 1 << " minute(s).\n";
                return;
            }
            if(building[n_layer][n_row][n_col] == '.' && board[n_layer][n_row][n_col] == -1){
                board[n_layer][n_row][n_col] = board[now.layer][now.row][now.col] + 1;
                frontier.emplace(n_layer, n_row, n_col);
            }
        }
    }

    cout << "Trapped!\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(true){
        cin >> num_of_layers >> num_of_rows >> num_of_cols;
        if(num_of_layers + num_of_rows + num_of_cols == 0) return 0;
        setting();
        if(start == target){
            cout << "Escaped in " << 0 << " minute(s).\n";
            continue;
        }
        bfs();
    }
}