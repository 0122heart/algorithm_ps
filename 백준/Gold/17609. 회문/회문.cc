#include <iostream>

using namespace std;

int judge_palindrome(string, int, int, int);

int main()
{
    int the_number_of_string;
    cin >> the_number_of_string;

    for(int i = 0; i < the_number_of_string; i++){
        string temp;
        cin >> temp;
        int judged = judge_palindrome(temp, 0, temp.length() - 1, 0);
        cout << judged - 1 << endl;
    }
}

int judge_palindrome(string str, int start_index, int end_index, int chance){
    if(1 < chance)
        return 3;

    while(start_index < end_index){
        // 문자가 같을 때 : 통과
        if(str[start_index] == str[end_index]){
            start_index++;
            end_index--;
        }
        else{
            return min(judge_palindrome(str, start_index + 1, end_index, chance + 1), judge_palindrome(str, start_index, end_index - 1, chance + 1));
        }
    }

    if(1 == chance){
        return 2;
    }
    else{
        return 1;
    }

}
