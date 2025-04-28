// 2579

#include <bits/stdc++.h>
using namespace std;

int num_stairs;
int score_of_stair[300];
int result[300][2];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> num_stairs;
    for(int i = 0; i < num_stairs; i++) cin >> score_of_stair[i];
    result[0][0] = 0;
    result[0][1] = score_of_stair[0];
    result[1][0] = score_of_stair[1];
    result[1][1] = score_of_stair[0] + score_of_stair[1];
    for(int i = 2; i < num_stairs; i++){
        result[i][0] = max(result[i - 2][0], result[i - 2][1]) + score_of_stair[i];
        result[i][1] = result[i - 1][0] + score_of_stair[i];
    }
    cout << max(result[num_stairs - 1][0], result[num_stairs - 1][1]);
}
