#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int> pq; // 우선순위 큐 (가장 큰 우선순위부터)

    for (int i = 0; i < priorities.size(); i++) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }

    int answer = 0;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        // 현재 문서의 우선순위가 가장 높지 않으면 다시 뒤로
        if (cur.second < pq.top()) {
            q.push(cur);
        } else {
            // 인쇄함
            pq.pop();
            answer++;
            if (cur.first == location) return answer;
        }
    }

    return answer;
}
