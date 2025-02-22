// 13335

#include <bits/stdc++.h>

using namespace std;

int num_of_trucks, distance_of_bridge, max_weight, result = 0;
queue<int> trucks;
deque<pair<int, int>> running;

void setting(){
    cin >> num_of_trucks >> distance_of_bridge >> max_weight;
    for(int i = 0; i < num_of_trucks; i++){
        int truck;
        cin >> truck;
        trucks.push(truck);
    }
}

void process(){
    int total_weight = 0;
    while(!trucks.empty()){
        result += 1;
        for(auto& i : running) i.second += 1;
        if(running.front().second == distance_of_bridge + 1){
            total_weight -= running.front().first;
            running.pop_front();
        }
        if(total_weight + trucks.front() <= max_weight){
            running.emplace_back(trucks.front(), 1);
            total_weight += trucks.front();
            trucks.pop();
        }
    }
    result += distance_of_bridge - running.back().second + 1;
    cout << result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    setting();
    process();
}