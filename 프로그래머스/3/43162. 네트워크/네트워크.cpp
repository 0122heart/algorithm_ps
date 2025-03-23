#include <bits/stdc++.h>

using namespace std;

void bfs(int row, int n, vector<vector<int>>& computers){
    for(int i = 0; i < n; i++){
        if(computers[row][i]){
            computers[row][i] = 0;
            bfs(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j]){
                answer++;
                computers[i][j] = 0;
                bfs(j, n, computers);
            }
        }
    }
    return answer;
}