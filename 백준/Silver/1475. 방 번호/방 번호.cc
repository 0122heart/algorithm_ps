#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int input;
    cin >> input;

    int need_num[10] = {};

    while(input){
        need_num[input % 10]++;
        input /= 10;
    }

    need_num[9] += need_num[6];
    need_num[9] = need_num[9] / 2 + need_num[9] % 2;
    need_num[6] = need_num[9];

    cout << *max_element(need_num, need_num + 10);
}
