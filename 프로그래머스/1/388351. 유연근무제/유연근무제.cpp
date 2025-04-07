#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> deadline, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    bool flag;
    
    for(auto& i : deadline){
        i += 10;
        int min = i % 100;
        i += 100 * (min / 60) - 60 * (min / 60);
    }
    
    for(int i = 0; i < deadline.size(); i++){
        flag = true;
        int day = startday - 1;
        for(int j = 0; j < 7; j++){
            day++;
            day %= 7;
            if(day == 6 || day == 0) continue;
            if(deadline[i] < timelogs[i][j]){
                flag = false;
                break;
            }
        }
        if(flag)
            answer += 1;
    }
    return answer;
}