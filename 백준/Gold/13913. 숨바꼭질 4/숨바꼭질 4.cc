// 13549

#include <bits/stdc++.h>

using namespace std;

int board[100001];
int start, target;

void setting(){
    fill(board, board + 100001, -1);
    cin >> start >> target;
    board[start] = true;
    if(start == target){
        cout << 0 << "\n";
        cout << start;
        exit(0);
    }
}

bool check_boundary(int x){
    return !(0 <= x && x < 100001 && board[x] == -1);
}

void bfs(){
    queue<int> frontier;
    frontier.push({start});
    while(!frontier.empty()){
        int now = frontier.front(); frontier.pop();
        vector<int> candidates = {now + 1, now - 1, 2 * now};
        candidates.erase(
            remove_if(candidates.begin(), candidates.end(), check_boundary),
            candidates.end());
        for(auto candidate : candidates){
            if(candidate == target){
                board[target] = now;
                return;
            }
            board[candidate] = now;
            frontier.push(candidate);
        }

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    setting();
    bfs();
    vector<int> result;
    result.push_back(target);
    while(board[target] != start){
        result.push_back(board[target]);
        target = board[target];
    }
    reverse(result.begin(), result.end());
    cout << result.size() << "\n" << start << " ";
    for(auto i : result) cout << i << " ";

    return 0;
}