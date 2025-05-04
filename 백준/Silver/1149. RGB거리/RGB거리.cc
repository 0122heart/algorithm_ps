// 1149

#include <bits/stdc++.h>
using namespace std;

int num_house;
int result[1000][3];
int red[1000], green[1000], blue[1000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> num_house;
    for(int i = 0; i < num_house; i++){
        cin >> red[i] >> green[i] >> blue[i];
    }
    result[0][0] = red[0];
    result[0][1] = green[0];
    result[0][2] = blue[0];
    for(int i = 1; i < num_house; i++){
        result[i][0] = min(result[i - 1][1], result[i - 1][2]) + red[i];
        result[i][1] = min(result[i - 1][0], result[i - 1][2]) + green[i];
        result[i][2] = min(result[i - 1][0], result[i - 1][1]) + blue[i];
    }
    cout << min(min(result[num_house - 1][0], result[num_house - 1][1]),result[num_house - 1][2]);
}
