#include <bits/stdc++.h>
using namespace std;

short r[2];
short g[2];
short b[2];

map<int,char> mm;
void print_num(int num){  
    
    if(num>=10)cout<<mm[num];
    else cout<<num;
}

int main(){

    mm[10]='A';
    mm[11]='B';
    mm[12]='C';
    int red,green,blue;
    cin>>red>>green>>blue;

    r[0]=red%13;
    red/=13;
    r[1]=red%13;

    g[0]=green%13;
    green/=13;
    g[1]=green%13;

    b[0]=blue%13;
    blue/=13;
    b[1]=blue%13;

    cout<<"#";
    print_num(r[1]);
    print_num(r[0]);

    print_num(g[1]);
    print_num(g[0]);

    print_num(b[1]);
    print_num(b[0]);

}