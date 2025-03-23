#include <string>
#include <vector>

using namespace std;
int real_target;
int result = 0;
int now = 0;

void bfs(vector<int>& numbers, int index){
    if(index == numbers.size()){
        if(now == real_target) result += 1;
        return;
    }
    for(int i : {numbers[index], -numbers[index]}){
        now += i;
        bfs(numbers, index + 1);
        now -= i;
    }
}

int solution(vector<int> numbers, int target) {
    real_target = target;
    bfs(numbers, 0);
    return result;
}