// 12852

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
    cout << numbers[target] << "\n";

    while(target != 1){
        cout << target << " ";
        if(numbers[target - 1] == numbers[target] - 1) target -= 1;
        else if(target % 2 == 0 && numbers[target / 2] == numbers[target] - 1) target /= 2;
        else if(target % 3 == 0 && numbers[target / 3] == numbers[target] - 1) target /= 3;
    }
    cout << 1;
}


int main(){
    setting();
    process();

    return 0;
}