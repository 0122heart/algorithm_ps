// 18808

#include <bits/stdc++.h>
using namespace std;

int num_of_rows, num_of_cols, num_of_stickers, row_of_stickers, col_of_stickers;
int board[40][40];
int sticker[10][10];

// 90도 회전하는 함수
void rotate_quarter(int (&origin)[10][10]){
    int temp[10][10];
    for(int i = 0; i < row_of_stickers; i++)
        for(int j = 0; j < col_of_stickers; j++)
            temp[i][j] = origin[i][j];

    for(int row = 0; row < row_of_stickers; row++){
        for(int col = 0; col < col_of_stickers; col++){
            origin[col][row_of_stickers - 1 - row] = temp[row][col];
        }
    }
}

bool OOB(int row, int col){
    return row < 0 || num_of_rows <= row || col < 0 || num_of_cols <= col;
}

void putting(int row, int col){
    for(int i = 0; i < row_of_stickers; i++)
        for(int j = 0; j < col_of_stickers; j++)
            if(sticker[i][j])
                board[i + row][j + col] = sticker[i][j];
}

// 스티커 붙일 수 있는지 체크
bool can_put(int row, int col){
    for(int i = 0; i < row_of_stickers; i++)
        for(int j = 0; j < col_of_stickers; j++)
            if(OOB(i + row, j + col) || sticker[i][j] + board[i + row][j + col] == 2)
                return false;

    putting(row, col);
    return true;
}


// 스티커 붙이기
void put_sticker(){
    for(int rotation = 0; rotation < 4; rotation++){
        for(int i = 0; i < num_of_rows; i++)
            for(int j = 0; j < num_of_cols; j++)
                if(can_put(i, j)) return;

        rotate_quarter(sticker);
        swap(row_of_stickers, col_of_stickers);
    }
}

// 붙은 스티커 체크
void check_put(){
    int result = 0;
    for(int i = 0; i < num_of_rows; i++){
        for(int j = 0; j < num_of_cols; j++){
            if(board[i][j]) result++;
        }
    }
    cout << result;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> num_of_rows >> num_of_cols >> num_of_stickers;

    for(int i = 0; i < num_of_rows; i++)
        fill(board[i], board[i] + num_of_cols, 0);

    for(int i = 0; i < num_of_stickers; i++){
        cin >> row_of_stickers >> col_of_stickers;
        for(int j = 0; j < row_of_stickers; j++){
            for(int k = 0; k < col_of_stickers; k++)
                cin >> sticker[j][k];
        }
        put_sticker();
    }

    check_put();
    return 0;
}