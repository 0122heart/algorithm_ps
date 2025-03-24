#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for(int i : arr){
        if(answer.empty()) answer.push_back(i);
        else if(*(answer.end() - 1) != i) answer.push_back(i);
    }
    
    return answer;
}