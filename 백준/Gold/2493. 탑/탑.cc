// 249

#include <bits/stdc++.h>

using namespace std;

int num_of_towers;
stack<pair<int, int>> heights;
pair<int, int> info_of_tower;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> num_of_towers;
    heights.push({0, 100000001});
    int height;

    for(int tower_index = 1; tower_index < num_of_towers + 1; tower_index++){
        cin >> height;
        while(heights.top().second < height) heights.pop();
        cout << heights.top().first << " ";
        heights.push({tower_index, height});
    }

    return 0;
}