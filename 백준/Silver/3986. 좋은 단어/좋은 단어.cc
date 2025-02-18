// 3986

#include <bits/stdc++.h>

using namespace std;

int result = 0, the_num_of_words;
stack<char> is_crossing;
string word;

void clear(){
    while(!is_crossing.empty()) is_crossing.pop();
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> the_num_of_words;
    for(int i = 0; i < the_num_of_words; i++){
        cin >> word;
        for(char j : word){
            if(!is_crossing.empty() && is_crossing.top() == j) is_crossing.pop();
            else is_crossing.push(j);
        }
        if(is_crossing.empty()) result += 1;
        clear();
    }
    cout << result;

    return 0;
}