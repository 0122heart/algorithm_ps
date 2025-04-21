#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto& cmd : commands){
        vector<int> result;
        for(int i = cmd[0] - 1; i < cmd[1]; i++){
            result.push_back(array[i]);
        }
        sort(result.begin(), result.end());
        answer.push_back(result[cmd[2] - 1]);
    }
    return answer;
}