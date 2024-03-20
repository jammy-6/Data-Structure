#include <bits/stdc++.h>
using namespace std;


bool is_prime(int num){
    if(num<=1) return false;
    if(num==2) return true;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)
            return false;
    }
    return true;
}


//num转换成对应进制，反转后再转成十进制数
int to_radix(int num,int radix){
    short rs[100];
    int cnt=0;
    do{
        rs[cnt++]=num%radix;
        num/=radix;
    }while(num!=0);

    int ans = 0,t=1;
    for(int i=cnt-1;i>=0;i--){
        ans+=rs[i]*t;
        t*=radix;
    }

    return  ans;
}


int main(){
    int num,radix;
    while(true){
        cin>>num;
        if(num<0) break;
        else{
            cin>>radix;
            if(is_prime(num)&&is_prime(to_radix(num,radix))){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }


}