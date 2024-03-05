#include<vector>
#include <string>

using namespace std;
    string path;
    string target;
    vector<vector<bool>> used; 
bool judge(int row,int column,int i,int j){
    return i>=0 && j>=0 &&i<row &&j<column;
}

bool backTracing(vector<vector<char>>& grid,int i,int j,int idx){
    if(grid[i][j]!=target[idx]) 
        return false;
    used[i][j]=true;
    path.push_back(grid[i][j]);
    if(path==target) return true;
    if(i+1<grid.size() && !used[i+1][j] &&backTracing(grid,i+1,j,idx+1)){
        return true;
    }
    if(i-1>=0  && !used[i-1][j] &&backTracing(grid,i-1,j,idx+1)){
        return true;
    }
    if(j+1<grid[0].size() && !used[i][j+1] &&backTracing(grid,i,j+1,idx+1)){
        return true;
    }
    if(j-1>=0 && !used[i][j-1] &&backTracing(grid,i,j-1,idx+1)){
        return true;
    }
    path.pop_back();
    used[i][j] = false;
    return false;

}
bool wordPuzzle(vector<vector<char>>& grid, string target) {
    ::target = target;
    used = vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size(),false));
    return backTracing(grid,0,0,0);
}

int main(){
    vector<vector<char>> grid = { {'A','B','C','E'}, {'S','F','C','S'},{'A','D','E','E'}};
    string target = "ABCCED";
    wordPuzzle(grid,target);
}