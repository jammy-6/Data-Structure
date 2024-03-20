#include <bits/stdc++.h>
using namespace std;

int rs[100];

int main(){

    int num,radix;
    cin>>num>>radix;
    int cnt=0;
    do{
        rs[cnt++]=num%radix;
        num/=radix;
    }while(num!=0);

    bool flag = true;
    for(int i=0;i<cnt/2;i++){
        if(rs[i]!=rs[cnt-i-1])
        {
            cout<<"No"<<endl;
            flag = false;
            break;
        }
    }
    if(flag)
        cout<<"Yes"<<endl;
    for(int i=cnt-1;i>=0;i--){
        cout<<rs[i];
        if(i!=0)    cout<<" ";
    }
}