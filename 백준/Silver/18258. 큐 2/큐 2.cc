// 18258

#include <bits/stdc++.h>

using namespace std;

int the_num_of_cmds;
string cmd;
queue<int> numbers;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> the_num_of_cmds;

    for(int i = 0; i < the_num_of_cmds; i++){
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            numbers.push(num);
        }
        else if(cmd == "pop"){
            if(!numbers.empty()){
                cout << numbers.front() << "\n";
                numbers.pop();
            }
            else cout << -1 << "\n";
        }
        else if(cmd == "size"){
            cout << numbers.size() << "\n";
        }
        else if(cmd == "empty"){
            cout << numbers.empty() << "\n";
        }
        else if(cmd == "front"){
            if(!numbers.empty()) cout << numbers.front() << "\n";
            else cout << -1 << "\n";
        }
        else if(cmd == "back"){
            if(!numbers.empty()) cout << numbers.back() << "\n";
            else cout << -1 << "\n";
        }
    }

    return 0;
}