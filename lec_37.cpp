#include <bits/stdc++.h>
using namespace std;

bool judge(vector<vector<char>>& board,int row,int column,char val){
    //行检查
    for(int i=0;i<board[row].size();i++){
        if(board[row][i]!='.'&&board[row][i]==val) return false;
    }
    //列检查
    for(int i=0;i<board.size();i++){
        if(board[i][column]!='.'&&board[i][column]==val) return false;
    }

    //九宫格检查
    int rowStart = row/3*3;
    int colStart = column/3*3;
    for(int i=rowStart;i<rowStart+3;i++){
        for(int j=colStart;j<colStart+3;j++){
            if(board[i][j]!='.'&&board[i][j]==val) return false;
        }
    }
    return true;
}
bool backTracing(vector<vector<char>>& board,int row,int column){
    int i,j;
    for(i=row;i<board.size();i++){
        for(j=column;j<board[i].size();j++){
            if(board[i][j]=='.')
                break;
        }
        column = 0;
        if(board[i][j]=='.') break;
    }
    cout<<i<<" "<<j<<endl;
    if(i>=board.size()||board[i][j]!='.') 
        return true;

    for(char k='1';k<='9';k++){
        if(judge(board,i,j,k)){
            
            board[i][j] = k;
            if(backTracing(board,i,j))
                return true;
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    backTracing(board,0,0);
}


int main(){
    vector<vector<char>> board =  { {'5','3','.','.','7','.','.','.','.'}, {'6','.','.','1','9','5','.','.','.'}, {'.','9','8','.','.','.','.','6','.'}, {'8','.','.','.','6','.','.','.','3'}, {'4','.','.','8','.','3','.','.','1'}, {'7','.','.','.','2','.','.','.','6'}, {'.','6','.','.','.','.','2','8','.'}, {'.','.','.','4','1','9','.','.','5'}, {'.','.','.','.','8','.','.','7','9'}};

    solveSudoku(board);
}