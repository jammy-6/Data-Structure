#include <bits/stdc++.h>
using namespace std;

//k皇后回溯算法

const int num = 8;
int p[num+1];
int flag[num+1];
int count=0;
vector<vector<int>> rs;
void print_ans(int *ans);
void generate(int index){
    if(index==num+1){
        ::count++;
        print_ans(p);
        printf("-----------------------------\n");
        rs.push_back(vector<int>(p+1,p+num+1));
        return;
    }else{
        for(int i=1;i<=num;i++){
            if(!flag[i]){
                bool f = true;
                for(int j=1;j<index;j++){
                    if(abs(index-j)==abs(p[j]-i)){
                        f = false;
                        break;
                    }
                }
                if(f){
                    p[index] = i;
                    flag[i] = true;
                    generate(index+1);
                    flag[i] = false;
                }
            }
        }
    }
}

void print_ans(int *ans){
    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++){
            if(ans[i]==j){
                printf("1");
            }else{
                printf("0");
            }
            if(j==num){
                printf("\n");
            }else{
                printf(" ");
            }
        }
    }
}

int main()
{

    generate(1);
    cout<<::count<<endl;
    return 0;
}