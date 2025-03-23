#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string original, boom;
    cin >> original >> boom;

    string result;
    int boom_len = boom.length();

    for (char c : original) {
        result.push_back(c);

        // result의 마지막 부분이 boom과 일치하는지 확인
        if (result.size() >= boom_len &&
            result.substr(result.size() - boom_len, boom_len) == boom) {
            // 폭발 문자열 발견 → 제거
            result.erase(result.end() - boom_len, result.end());
        }
    }

    if (result.empty()) cout << "FRULA";
    else cout << result;

    return 0;
}
