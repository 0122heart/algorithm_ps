// 15649

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[8], is_used[8] = {};
vector<int> numbers;

void n_m(int now = 0){
    if(now == M){
        for(int i = 0; i < M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++){
        if(!is_used[i]){
            arr[now] = numbers[i];
            is_used[i] = 1;
            n_m(now + 1);
            is_used[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
    n_m();
    return 0;
}