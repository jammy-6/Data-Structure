
#include <bits/stdc++.h>
using namespace std;
/*
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 02 = 1
*/
class Solution {
public:
    int compute(int n){
        int rs=0;
        while(n){
            rs+=(n%10)*(n%10);
            n/=10;
        }
        return rs;
    }

    bool isHappy(int n) {

        unordered_set<int> s;
        s.insert(n);
        
        while(true){
            int temp = compute(n);
            if(temp==1) return true;
            if(s.count(temp)==0){
                s.insert(temp);
                n = temp;
            }else{
                break;
            }
        }
        return false;
    }
};