#include <bits/stdc++.h>
using namespace std;

int count=1;
int num;

void generate(int prev_num,int prev_count){
    int temp = prev_num*10;
    if(temp>num){
        return;
    }
    for(int i=0;i<=9;i++){
        if(temp+i<=num){
            if(i==1){
                // printf("%d\n",temp+i);
                ::count+=prev_count+1;
                generate(temp+i,prev_count+1);
            }else{
                // if(prev_count!=0)
                // printf("%d\n",temp+i);
                ::count+=prev_count;
                generate(temp+i,prev_count);
            }
        }

    }

}

int main()
{
    // freopen("in.txt","r",stdin);
    cin>>num;
    if(num<10){
        printf("%d",::count);
        return 0;
    }
    for(int i=1;i<=9;i++){
        if(i!=1)
        generate(i,0);
        else 
        generate(i,1);
    }

    printf("%d",::count);


    return 0;
}