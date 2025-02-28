// 13549

#include <bits/stdc++.h>

using namespace std;

int board[100001];
int start, target;

void setting(){
    fill(board, board + 100001, 100001);
    cin >> start >> target;
    board[start] = 0;
    if(start == target){cout << 0; exit(0);}
}

bool check_boundary(int x){
    return 0 <= x && x < 100001;
}

void bfs(){
    queue<int> frontier;
    frontier.push(start);
    while(!frontier.empty()){
        int now = frontier.front(); frontier.pop();
        if(now == target){cout << board[now]; return;}
        if(check_boundary(now + 1) && board[now] + 1 < board[now + 1]){
            board[now + 1] = board[now] + 1;
            frontier.push(now + 1);
        }
        if(check_boundary(now - 1) && board[now] + 1 < board[now - 1]){
            board[now - 1] = board[now] + 1;
            frontier.push(now - 1);
        }
        if(check_boundary(2 * now) && board[now] < board[2 * now]){
            board[2 * now] = board[now];
            frontier.push(2 * now);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    setting();
    bfs();
    return 0;
}