#include <bits/stdc++.h>
using namespace std;

int num_tests, start, target;
string board[10000];

void process() {
    fill(board, board + 10000, "");

    queue<int> frontier;
    frontier.push(start);
    board[start] = ".";

    while (!frontier.empty()) {
        int now = frontier.front();
        frontier.pop();

        if (now == target) {
            board[now] = board[now].substr(1);
            cout << board[now] << "\n";
            return;
        }

        for (char cmd : {'D', 'S', 'L', 'R'}) {
            int next;
            if (cmd == 'D') {
                next = (2 * now) % 10000;
            } else if (cmd == 'S') {
                next = (now == 0) ? 9999 : now - 1;
            } else if (cmd == 'L') {
                next = (now % 1000) * 10 + (now / 1000);
            } else {
                next = (now % 10) * 1000 + (now / 10);
            }

            if (board[next].empty()) {
                board[next] = board[now] + cmd;
                frontier.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_tests;
    while (num_tests--) {
        cin >> start >> target;
        process();
    }

    return 0;
}
