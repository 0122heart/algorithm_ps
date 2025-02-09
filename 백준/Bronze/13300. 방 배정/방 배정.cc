// 13300

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int num_of_participants, max_of_room;
    cin >> num_of_participants >> max_of_room;

    int info_of_students[2][6] = {};

    int sex, grade;
    for(int i = 0; i < num_of_participants; i++){
        cin >> sex >> grade;
        info_of_students[sex][grade - 1]++;
    }

    int ans = 0;
    for(auto& i : info_of_students){
        for(int j : i){
            ans += j / max_of_room;
            if(j % max_of_room) ans += 1;
        }
    }

    cout << ans;

    return 0;
}
