#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int nums[3];

    for(int i = 0; i < 3; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            if(nums[i] > nums[j])
                swap(nums[i], nums[j]);
        }
    }

    for(auto i : nums){
        cout << i << " ";
    }
    return 0;
}
