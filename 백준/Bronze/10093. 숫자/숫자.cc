#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    long long start, end;
    cin >> start >> end;

    if(start == end){
        cout << 0 << "\n";
        return 0;
    }

    if(end < start){
        swap(start, end);
    }

    // 수의 개수 출력
    cout << end - start - 1 << "\n";

    // 오름차순 출력
    for(long long i = start + 1; i < end; i++) cout << i << " ";

    return 0;
}
