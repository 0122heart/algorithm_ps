#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string original, boom;
    cin >> original >> boom;

    vector<char> result;
    int boom_len = boom.size();

    for (char c : original) {
        result.push_back(c);

        if (result.size() >= boom_len) {
            bool is_boom = true;
            for (int i = 0; i < boom_len; ++i) {
                if (result[result.size() - boom_len + i] != boom[i]) {
                    is_boom = false;
                    break;
                }
            }

            if (is_boom) {
                for (int i = 0; i < boom_len; ++i) result.pop_back();
            }
        }
    }

    if (result.empty()) cout << "FRULA";
    else for (char c : result) cout << c;

    return 0;
}
