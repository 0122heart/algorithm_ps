#include <bits/stdc++.h>

using namespace std;

int time_split(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3));
    return 60 * h + m;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // 정수로 변경
    int int_video_len = 0, int_pos = 0, int_op_start = 0, int_op_end = 0;
    int_video_len = time_split(video_len);
    int_pos = time_split(pos);
    int_op_start = time_split(op_start);
    int_op_end = time_split(op_end);
    
    if(int_op_start <= int_pos && int_pos <= int_op_end) int_pos = int_op_end;
    for(auto cmd : commands){
        if(cmd == "next"){
            int_pos += 10;
            if(int_video_len < int_pos) int_pos = int_video_len;
        }
        else if(cmd == "prev"){
            int_pos -= 10;
            if(int_pos < 0) int_pos = 0;
        }
        if(int_op_start <= int_pos && int_pos <= int_op_end) int_pos = int_op_end;
    }
    
    stringstream ss;
    ss << setw(2) << setfill('0') << int_pos / 60 << ":";
    ss << setw(2) << setfill('0') << int_pos % 60;

    return ss.str();
}