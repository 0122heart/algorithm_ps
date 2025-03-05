// 15656

#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[8];
vector<int> numbers;

void setting(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
}

void n_m(int now = 0){
    if(now == M){
        for(int i = 0; i < M; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < N; i++){
        arr[now] = numbers[i];
        n_m(now + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    setting();
    n_m();
    return 0;
}