#include <bits/stdc++.h>
#define location first
#define step second

using namespace std;

int subin, daughter;
int board[100001] = {0,};
queue<int> subins;

bool check_boundary(int next) {
    return 0 <= next && next < 100001 && board[next] == 0;
}

void bfs() {
    while (!subins.empty()) {  // 안전한 반복 조건
        int now = subins.front();
        subins.pop();

        vector<int> candidate = {now + 1, now - 1, 2 * now};
        candidate.erase(remove_if(candidate.begin(), candidate.end(), 
                                  [](int next) { return !check_boundary(next); }), 
                        candidate.end());

        for (int i : candidate) {
            if (i == daughter) {
                cout << board[now] + 1;
                return;
            }

            board[i] = board[now] + 1;
            subins.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> subin >> daughter;
    subins.emplace(subin);

    if (subin == daughter) {
        cout << 0;  // 시작 위치와 목표 위치가 같다면 바로 종료
        return 0;
    }

    bfs();
    return 0;
}
