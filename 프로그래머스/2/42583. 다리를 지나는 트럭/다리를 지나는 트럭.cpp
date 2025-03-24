#include <bits/stdc++.h>

// 트럭들의 무게를 하나씩 순회
// 총 무게가 max_weight를 넘어가면 빼는 작업
// 안 넘어가면 모든 트럭 한칸 씩 이동
// 모든 트럭이 다리 위로 올라가면 마지막 트럭이 이동완료할 때 까지 step을 더하기

using namespace std;

int solution(int bridge_length, int max_weight, vector<int> truck_weights) {
    // 현재 다리 위에 있는 트럭들
    vector<pair<int, int>> running;
    int total_weight = 0, step = 0;
    
    for(auto now_weight : truck_weights){
        total_weight += now_weight;
        
        // 총 무게가 max_weight 넘어감
        if(max_weight < total_weight){
            while(max_weight < total_weight){
                total_weight -= running[0].first;
                int temp = bridge_length - running[0].second + 1;
                step += temp;
                for(auto& j : running) j.second += temp;
                running.erase(running.begin());
            }
            running.emplace_back(now_weight, 1);
        }
        else{
            running.emplace_back(now_weight, 0);
            for(auto&& j : running) j.second += 1;
            step += 1;
            if(bridge_length < running[0].second){
                total_weight -= running[0].first;
                running.erase(running.begin());
            }
        }
    }
    
    step += bridge_length - running[running.size() - 1].second + 1;
    
    return step;
    
}