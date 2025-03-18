// 5014

#include <bits/stdc++.h>
using namespace std;

int heighest, now, target, up, down;
int board[1000001];

void setting(){
    cin >> heighest >> now >> target >> up >> down;
    fill(board, board + heighest + 1, -1);
    if(now == target){
        cout << 0;
        exit(0);
    }
    board[now] = 0;
}

void bfs(){
    queue<int> frontier;
    frontier.push(now);
    while(!frontier.empty()){
        int now = frontier.front(); frontier.pop();
        for(int i : {now + up, now - down}){
            if(i < 1 || heighest < i || board[i] != -1) continue;
            if(i == target){
                cout << board[now] + 1;
                return;
            }
            board[i] = board[now] + 1;
            frontier.push(i);
        }
    }
    cout << "use the stairs";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    setting();
    bfs();
    return 0;
}