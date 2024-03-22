#include <bits/stdc++.h>
using namespace std;

//广度优先搜素
vector<vector<int>> dir{{0, 0, 1, -1}, {1, -1, 0, 0}};
int bfs(vector<vector<int>> &grid, int x, int y) {
  deque<pair<int, int>> que;
  que.push_back({x, y});
  int count = 0;
  grid[x][y] = 0;
  count++;
  while (!que.empty()) {
    pair<int, int> p = que.front();
    que.pop_front();
    int x = p.first;
    int y = p.second;

    for (int i = 0; i < 4; i++) {
      int nx = x + dir[0][i];
      int ny = y + dir[1][i];
      if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() ||
          grid[nx][ny] == 0)
        continue;
      grid[nx][ny] = 0;
      count++;
      que.push_back({nx, ny});
    }
  }
  return count;
}

int numEnclaves(vector<vector<int>> &grid) {
  int count = 0;
  int n = grid.size(), m = grid[0].size();
  for (int i = 0; i < n; i++) {
    if (grid[i][0] == 1)
      bfs(grid, i, 0);
    if (grid[i][m - 1] == 1)
      bfs(grid, i, m - 1);
  }
  for (int i = 0; i < m; i++) {
    if (grid[0][i] == 1)
      bfs(grid, 0, i);
    if (grid[n - 1][i] == 1)
      bfs(grid, n - 1, i);
  }
  count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1)
        count += bfs(grid, i, j);
    }
  }
  return count;
}
int main() {
  vector<vector<int>> grid = {{0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                              {1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1},
                              {1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1},
                              {1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0},
                              {1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1},
                              {1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
                              {1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                              {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0}};
  cout << numEnclaves(grid);
}