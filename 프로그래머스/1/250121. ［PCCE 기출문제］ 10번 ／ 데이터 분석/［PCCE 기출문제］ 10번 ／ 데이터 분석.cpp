#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> datas, string ext, int val_ext, string sort_by) {
    map<string, int> info = {
        {"code", 0},
        {"date", 1},
        {"maximum", 2},
        {"remain", 3}
    };
    
    int choice = info[ext];
    vector<vector<int>> answer;
    for(auto& data : datas)
        if(data[choice] < val_ext) answer.push_back(data);
    
    int choice_sort = info[sort_by];
    sort(answer.begin(), answer.end(), 
         [choice_sort](vector<int> one, vector<int> other){return one[choice_sort] < other[choice_sort];});
    return answer;
}