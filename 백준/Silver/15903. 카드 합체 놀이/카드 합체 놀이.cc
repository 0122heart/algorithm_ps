// 15903

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int num_of_cards, num_of_adds;
    priority_queue<ll, vector<ll>, greater<ll>> cards;

    cin >> num_of_cards >> num_of_adds;

    int temp;
    while(num_of_cards--){
        cin >> temp;
        cards.push(temp);
    }

    while(num_of_adds--){
        ll one = cards.top(); cards.pop();
        one += cards.top(); cards.pop();
        cards.push(one); cards.push(one);
    }

    ll result = 0;
    while(!cards.empty()){
        result += cards.top();
        cards.pop();
    }
    cout << result;
    return 0;
}