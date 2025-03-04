// 15649

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[8] = {};

void n_m(int now){
    if(now == M){
        for(int i = 0; i < M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
        arr[now] = i;
        n_m(now + 1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    n_m(0);
    return 0;
}