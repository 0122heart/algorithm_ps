#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int now, bae;
    char result[5] = {'E', 'A', 'B', 'C', 'D'};
    for(int i = 0; i < 3; i++){

        bae = 0;
        for(int j = 0; j < 4; j++){
            cin >> now;
            if(now == 0) bae++;
        }
        cout << result[bae] << "\n";
    }
    return 0;
}
