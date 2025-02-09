// 1919

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    string word1, word2;
    cin >> word1 >> word2;

    int alphabet[26] = {};

    for(char c : word1) alphabet[c - 'a']++;
    for(char c : word2) alphabet[c - 'a']--;

    int ans = 0;
    for(int count : alphabet) ans += abs(count);

    cout << ans;

    return 0;
}
