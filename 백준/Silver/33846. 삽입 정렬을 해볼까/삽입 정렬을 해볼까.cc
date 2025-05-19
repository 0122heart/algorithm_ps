#include <bits/stdc++.h>

using namespace std;

int result[1000000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int len_sequence, target;
    cin >> len_sequence >> target;
    for(int i = 0; i < len_sequence; i++) cin >> result[i];
    sort(result, result + target);
    for(int i = 0; i < len_sequence; i++) cout << result[i] << " ";
    return 0;
}