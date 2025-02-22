// 10799

#include <bits/stdc++.h>

using namespace std;

int result = 0, temp_result = 0;

void process(){
    string input;
    cin >> input;

    char before = input[0];
    temp_result += 1;
    
    for(int i = 1; i < input.length(); i++){
        if(input[i] == '(') temp_result += 1;
        else{
            temp_result -= 1;
            if(before == '(') result += temp_result;
            else result += 1;
        }
        before = input[i];
    }

    cout << result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    process();
    return 0;
}