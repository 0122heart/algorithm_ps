// 2531

#include <bits/stdc++.h>
using namespace std;

int num_of_plates, num_of_fishes, event, coupon, result = 0;
vector<int> fishes;
map<int, int> now;

void setting(){
    cin >> num_of_plates >> num_of_fishes >> event >> coupon;
    for(int i = 0; i < num_of_plates; i++){
        int temp;
        cin >> temp;
        fishes.push_back(temp);
    }
}

void searching(){
    auto it = fishes.begin();
    auto window_end = fishes.begin();
    now.clear();

    for(int i = 0; i < event; i++){
        now[*window_end]++;
        advance(window_end, 1);
        if(window_end == fishes.end()) window_end = fishes.begin();
    }

    now[coupon]++;
    result = now.size();

    while(it != fishes.end()){
        if (now[*it] > 1) {
            now[*it]--; // 값이 2 이상이면 1 감소
        } else {
            now.erase(*it); // 값이 1이면 key 삭제
        }
        now[*window_end]++;
        advance(window_end, 1);
        if(window_end == fishes.end()) window_end = fishes.begin();

        now[coupon]++;
        if(result < now.size()) result = now.size();
        advance(it, 1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    setting();
    searching();
    cout << result;
    return 0;
}