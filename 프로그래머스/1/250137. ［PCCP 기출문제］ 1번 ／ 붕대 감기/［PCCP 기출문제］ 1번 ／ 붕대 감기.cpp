#include <bits/stdc++.h>

using namespace std;

void heal(vector<int> bandage, int& max_hp, int& now_hp, int& healing_time){
    now_hp += bandage[1];
    healing_time++;
    if(healing_time == bandage[0]){
        now_hp += bandage[2];
        healing_time = 0;
    }
    if(max_hp < now_hp) now_hp = max_hp;
}

int solution(vector<int> bandage, int max_hp, vector<vector<int>> attacks) {
    int now_hp = max_hp;
    int time = 0;
    int healing_time = 0;
    
    // 공격을 순회
    for(auto attack : attacks){
        int attack_time = attack[0];
        int attack_damage = attack[1];
        
        // 공격X -> 붕대감을 때
        while(time < attack_time){
            heal(bandage, max_hp, now_hp, healing_time);
            time++;
        }
        
        // 공격받을 때
        now_hp -= attack_damage;
        healing_time = 0;
        if(now_hp <= 0) return -1;
        time++;
    }
    return now_hp;
}