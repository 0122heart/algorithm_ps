// 11328

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int num_of_testcases;
    cin >> num_of_testcases;

    string original_string, changed_string;
    unsigned int length_of_original;
    int alphabet[26];

    for(int test = 0; test < num_of_testcases; test++){
        cin >> original_string >> changed_string;

        if((length_of_original = original_string.length()) == changed_string.length()){
            fill(alphabet, alphabet + 26, 0);
            for(int index = 0; index < length_of_original; index++){
                alphabet[original_string[index] - 'a']++;
                alphabet[changed_string[index] - 'a']--;
            }

            if(all_of(alphabet, alphabet + 26, [](int count){return count == 0;})) cout << "Possible\n";
            else cout << "Impossible\n";
        }
        else cout << "Impossible\n";
    }

    return 0;
}
