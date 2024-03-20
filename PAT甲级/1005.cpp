#include<iostream>
#include <cstring>

using namespace std;


char *word[10] = {"zero","one","two","three","four","five","six","seven","eight","night"};
char num[110];
int main(){
    int rs=0;
    cin>>num;

    for(int i=0;i<strlen(num);i++){
        rs+=num[i]-'0';
    }

    sprintf(num,"%d",rs);

    rs = strlen(num);
    for(int i=0;i<rs;i++){
        cout<<word[num[i]-'0'];
        if(i+1!=rs) cout<<" ";
    }


    
}