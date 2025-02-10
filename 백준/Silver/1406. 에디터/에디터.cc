// 1406

#include <bits/stdc++.h>

using namespace std;

string initial_string;
int num_of_cmd;
list<char> editor;
list<char>::iterator cursor;

void setting(){
    cin >> initial_string;
    for(auto alphabet : initial_string) editor.push_back(alphabet);

    cin >> num_of_cmd;

    cursor = editor.end();
}

void cmd(){
    char cmd;

    for(int i = 0; i < num_of_cmd; i++){
        cin >> cmd;
        if(cmd == 'L'){
            if(cursor != editor.begin()) cursor--;
        }
        else if(cmd == 'D'){
            if(cursor != editor.end()) cursor++;
        }
        else if(cmd == 'B'){
            if(cursor != editor.begin()){
                cursor = editor.erase(--cursor);
            }
        }
        else{
            char input;
            cin >> input;
            cursor = ++editor.insert(cursor, input);
        }
    }
}

void print(){
    for(auto i : editor)
        cout << i;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    setting();
    cmd();
    print();


    return 0;
}
