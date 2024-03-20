#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

long long int convert210(const char *num,int radix){
    long long int rs = 0;
    int size = strlen(num);
    long long int temp =1;
    for(int i=size-1;i>=0;i--){
        if(isdigit(num[i])){
            rs+=temp*(num[i]-'0');
        }else{
            rs+=temp*(num[i]-'a'+10);
        }
        temp*=radix;
    }
    return rs;
}

int getminradix(const char *num){
    int size = strlen(num);
    long long int radix = 2;
    for(int i=0;i<size;i++){
        if(isdigit(num[i])&&(num[i]-'0'+1)>radix){
            radix = num[i]-'0'+1;
        }else if(isalpha(num[i])&&(num[i]-'a'+11)>radix){
            radix = num[i]-'a'+11;
        }
    }
    return radix;
}


int main(){
    char n1[20];
    char n2[20];

    scanf("%s",n1);
    scanf("%s",n2);

    int tag,radix;
    scanf("%d %d",&tag,&radix);

    long long int num1,num2;
    if(tag==1){
        num1 = convert210(n1,radix);
    }else{
        num1 = convert210(n2,radix);
        strcpy(n2,n1);
    }

    long long int min_radix,max_radix = num1+1;

    min_radix = getminradix(n2);
    long long int i = (min_radix+max_radix)/2;

    while(min_radix<max_radix){
        num2 = convert210(n2,i);
        if(num2>num1){
            max_radix = i-1;
        }
        else if(num2==num1){
            cout<<i;
            return 0;
        }else{
            min_radix = i+1;
        }
        i = (max_radix+min_radix)/2;
    }
    if(convert210(n2,min_radix)==num1){
        cout<<min_radix;
        return 0 ;
    }
  
    cout<<"Impossible";
}