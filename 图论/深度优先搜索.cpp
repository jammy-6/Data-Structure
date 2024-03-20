#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{0, 1, 0, -1}, {1, 0, -1, 0}};
void dfs(vector<vector<bool>> &history, vector<vector<char>> &grid, int x,
         int y) {
  int nx, ny;
  for (int i = 0; i < 4; i++) {
    nx = x + dir[0][i];
    ny = y + dir[1][i];
    if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
      continue;
    if (!history[nx][ny] && grid[nx][ny] == '1') {
      history[nx][ny] = true;
      dfs(history, grid, nx, ny);
    }
  }
}

int numIslands(vector<vector<char>> &grid) {
  int ans = 0;
  vector<vector<bool>> history(grid.size(),
                               vector<bool>(grid[0].size(), false));
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (history[i][j] == false && grid[i][j] == '1') {
        history[i][j] = true;
        ans++;
        dfs(history, grid, i, j);
      }
    }
  }
  return ans;
}
int main() {

  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};
  cout << numIslands(grid) << endl;
  return 0;
}