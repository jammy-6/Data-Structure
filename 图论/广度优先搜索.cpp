#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0, 1, 0, -1}, {1, 0, -1, 0}};
void bfs(vector<vector<bool>> &history, vector<vector<char>> &grid, int x,
         int y) {
  queue<pair<int, int>> q;
  history[x][y] = true;
  q.push({x, y});
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dir[0][i];
      int ny = y + dir[1][i];
      //判断是否合法
      if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
        continue;

      if (history[nx][ny] == false && grid[nx][ny] == '1') {
        history[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
}

int numIslands(vector<vector<char>> &grid) {
  int ans = 0;
  vector<vector<bool>> history =
      vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (history[i][j] == false && grid[i][j] == '1') {
        ans++;
        bfs(history, grid, i, j);
      }
    }
  }
  return ans;
}
int main() {

  vector<vector<char>> grid = {{'1', '0', '1', '1', '0', '1', '1'}};
  numIslands(grid);
  return 0;
}