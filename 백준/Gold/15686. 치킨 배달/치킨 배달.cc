#include <bits/stdc++.h>
using namespace std;

int num_of_rows, max_chicken, result = INT_MAX;
int board[50][50];
vector<pair<int, int>> chicken, home;
bool delete_chicken[13];

void setting() {
    cin >> num_of_rows >> max_chicken;
    
    for (int i = 0; i < num_of_rows; i++) {
        for (int j = 0; j < num_of_rows; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) home.emplace_back(i, j);
            if (board[i][j] == 2) chicken.emplace_back(i, j);
        }
    }
}

int calc_distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void process(int start, int count) {
    if (count == chicken.size() - max_chicken) {
        int temp_result = 0;
        
        for (auto h : home) {
            int now_distance = INT_MAX;
            for (int j = 0; j < chicken.size(); j++) {
                if (delete_chicken[j]) continue;
                now_distance = min(now_distance, calc_distance(h, chicken[j]));
            }
            temp_result += now_distance;
        }
        
        result = min(result, temp_result);
        return;
    }

    for (int i = start; i < chicken.size(); i++) {
        if (!delete_chicken[i]) {
            delete_chicken[i] = true;
            process(i + 1, count + 1);
            delete_chicken[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setting();
    process(0, 0);
    cout << result;
    return 0;
}
