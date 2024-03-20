#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getNext(string patt) {
  int pattLen = 0;
  vector<int> next(patt.size(), 0);
  next[0] = 0;
  int i = 1;
  while (i < patt.size()) {
    if (patt[pattLen] == patt[i]) {
      next[i] = ++pattLen;
      i++;
    } else if (pattLen > 0) {
      pattLen = next[pattLen - 1];
    } else {
      next[i] = 0;
      i++;
    }
  }
  return next;
}

int strStr(string str, string patt) {
  vector<int> next = getNext(patt);
  int i = 0, j = 0;
  while (i < str.size()) {
    if (str[i] == patt[j]) {
      i++, j++;
    } else if (j > 0) {
      j = next[j - 1];
    } else {
      i++;
    }
    if (j == patt.size()) {
      return i - j;
    }
  }
  return -1;
}
int main() {
  string patt = "aabaaf";
  vector<int> next = getNext(patt);
  for (int i = 0; i < next.size(); i++)
    cout << next[i] << " ";
}