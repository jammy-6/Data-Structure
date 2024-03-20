#include <bits/stdc++.h>
using namespace std;

// 递归生成矩阵元素
/*
10101
0000
000
00
0
*/
int ans = 0;
void
backTracing(vector<vector<int>>& matrix, int x, int y)
{
  // 递归完成
  if (y == matrix.size()) {
    // 如果当前结果符合条件，则＋1
    if (matrix[y - 1][x] == 1)
      ans++;
    return;
  }

  for (int i = 0; i <= 2; i++) {

    if (i == 0) {
      matrix[y][x] =
        (matrix[y - 1][x] == 1 && matrix[y - 1][x + 1] == 1) ? 1 : 0;
    } else if (i == 1) {
      matrix[y][x] =
        (matrix[y - 1][x] == 1 || matrix[y - 1][x + 1] == 1) ? 1 : 0;
    } else {
      matrix[y][x] = (matrix[y - 1][x] != matrix[y - 1][x + 1]) ? 1 : 0;
    }

    if (x == matrix.size() - y - 1) { // 当前行元素赋值完毕，进入到下一行
      backTracing(matrix, 0, y + 1);
    } else { // 继续当前行
      backTracing(matrix, x + 1, y);
    }
  }
}

// 请将输入替换为以下这行
//  IN[0] = 1,IN[1] = 0,IN[2] = 1,IN[3] = 0,IN[4] = 1
int
main()
{
  // 请在此输入您的代码
  string s;
  getline(cin, s);
  vector<int> data;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '=') {
      data.push_back(stoi(string(s.begin() + i + 1, s.begin() + i + 3)));
    }
  }
  vector<vector<int>> matrix(data.size(), vector<int>(data.size(), 0));
  matrix[0] = data;
  backTracing(matrix, 0, 1);
  std::cout << ans << std::endl;
  return 0;
}