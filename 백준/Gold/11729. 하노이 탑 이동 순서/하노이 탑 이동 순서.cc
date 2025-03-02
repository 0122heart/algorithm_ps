// 11729

#include <bits/stdc++.h>
using namespace std;

void hanoi(int start, int target, int num){
    if(num == 1){
        cout << start << " " << target << "\n";
        return;
    }
    hanoi(start, 6 - start - target, num - 1);
    cout << start << " " << target << "\n";
    hanoi(6 - start - target, target, num - 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int num;
    cin >> num;
    cout << (1<<num) - 1 << "\n";
    hanoi(1, 3, num);
    return 0;
}