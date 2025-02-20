// 1697

#include <bits/stdc++.h>
#define location first
#define step second

using namespace std;

int subin, daughter;
int board[100001] = {0,};
queue<int> subins;

bool check_boundary(int next){
    return !(0 <= next && next < 100001 && board[next] == 0);
}

void bfs(){
    while(1){
        int now = subins.front();
        subins.pop();

        vector<int> candidate = {now + 1, now - 1, 2 * now};
        candidate.erase(remove_if(candidate.begin(), candidate.end(), check_boundary), candidate.end());

        for(int i : candidate){
            if(i == daughter){
                cout << board[now] + 1;
                return;
            }

            board[i] = board[now] + 1;
            subins.push(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> subin >> daughter;
    if(subin == daughter){
        cout << 0;
        return 0;
    }
    subins.emplace(subin);
    bfs();
    return 0;
}