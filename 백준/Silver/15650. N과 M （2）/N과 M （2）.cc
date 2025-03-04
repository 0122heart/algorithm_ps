// 15649

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[9] = {};
int is_used[9] = {};

void n_m(int now){
    if(now == M){
        for(int i = 0; i < M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = arr[now - 1] + 1; i <= N; i++){
        if(!is_used[i]){
            arr[now] = i;
            is_used[i] = 1;
            n_m(now + 1);
            is_used[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        arr[0] = i;
        is_used[i] = 1;
        n_m(1);
    }
    return 0;
}