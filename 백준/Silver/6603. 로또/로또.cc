// 6603

#include <bits/stdc++.h>
using namespace std;

int num_of_numbers;
int result[6];
int is_used[12];
vector<int> numbers;

void setting(){
    cin >> num_of_numbers;
    if(!num_of_numbers) exit(0);

    numbers.resize(num_of_numbers);
    for(int i = 0; i < num_of_numbers; i++) cin >> numbers[i];

    fill(is_used, is_used + num_of_numbers, 0);
}

void lotto(int now, int before = -1){
    if(now == 6){
        for(int i : result) cout << i << " ";
        cout << "\n";
        return;
    }

    int st = 0;
    if(now) st = before;
    for(int i = before + 1; i < num_of_numbers; i++){
        if(is_used[i]) continue;
        result[now] = numbers[i];
        is_used[i] = 1;
        lotto(now + 1, i);
        is_used[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        setting();
        lotto(0);
        cout << "\n";
    }
}