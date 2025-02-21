// 1463

#include <bits/stdc++.h>

using namespace std;

int numbers[1000001];
int target;

void setting(){
    numbers[1] = 0;
    cin >> target;
}

void process(){
    for(int num = 2; num < target + 1; num++){
        if(num % 2 == 0 && num % 3 == 0) numbers[num] = min({numbers[num / 2], numbers[num / 3], numbers[num - 1]}) + 1;
        else if(num % 2 == 0) numbers[num] = min(numbers[num / 2], numbers[num - 1]) + 1;
        else if(num % 3 == 0) numbers[num] = min(numbers[num / 3], numbers[num - 1]) + 1;
        else numbers[num] = numbers[num - 1] + 1;
    }
}

int main(){
    setting();
    process();
    cout << numbers[target];
    return 0;
}