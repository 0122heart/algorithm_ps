// 2847

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    stack<int> levels;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        levels.push(temp);
    }
    int before = 20000;
    int result = 0;
    while(!levels.empty()){
        if(levels.top() < before){
            before = levels.top();
        }
        else{
            result += levels.top() - before + 1;
            before = levels.top() - levels.top() + before - 1;
        }
        levels.pop();
    }
    cout << result;

    return 0;
}