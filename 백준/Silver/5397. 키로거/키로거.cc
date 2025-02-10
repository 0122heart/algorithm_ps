// 5397

#include <bits/stdc++.h>

using namespace std;

int num_of_tests;
list<char> password;
list<char>::iterator cursor = password.begin();

void setting(){
    cin >> num_of_tests;
}

void trace_password(char input){
    if(input == '>'){
        if(cursor != password.end()) cursor++;
    }
    else if(input == '<'){
        if(cursor != password.begin()) cursor--;
    }
    else if(input == '-'){
        if(!password.empty() && cursor != password.begin()){
            cursor = password.erase(--cursor);
        }
    }
    else{
        password.insert(cursor, input);
    }
}

void find_password(){
    string pw;
    cin >> pw;
    for(auto i : pw) trace_password(i);
    for(auto i : password) cout << i;
    cout << "\n";
}

int main(){
    setting();
    for(int test = 0; test < num_of_tests; test++){
        find_password();
        password.clear();
        cursor = password.begin();
    }
    return 0;
}
