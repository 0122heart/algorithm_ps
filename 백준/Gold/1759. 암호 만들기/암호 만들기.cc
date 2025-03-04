// 1759

#include <bits/stdc++.h>

using namespace std;

int len_of_pw, num_of_chars;
char pw[15];
vector<char> chars;

void setting(){
    cin >> len_of_pw >> num_of_chars;
    for(int i = 0; i < num_of_chars; i++){
        char temp;
        cin >> temp;
        chars.push_back(temp);
    }
    sort(chars.begin(), chars.end());
}

bool check_aeiou(char now){
    return now == 'a' || now == 'e' || now == 'i' || now == 'o' || now == 'u';
}

void n_m(int now = 0, int used = 0, int aeiou = 0, int others = 0){
    if(now == len_of_pw){
        if(1 <= aeiou && 2 <= others){
            for(int i = 0; i < len_of_pw; i++) cout << pw[i];
            cout << "\n";
        }
        return;
    }

    for(int i = used; i < num_of_chars; i++){
        pw[now] = chars[i];
        if(check_aeiou(chars[i])) n_m(now + 1, i + 1, aeiou + 1, others);
        else n_m(now + 1, i + 1, aeiou, others + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    setting();
    n_m();
    return 0;
}