#include<iostream>
#include <cstring>
using namespace std;
char early_id[20];
char late_id[20];
char early_sign[10] = "23:59:59";
char late_sign[10] = "00:00:01";
int m;
int main(){
    char id[20];
    char sign_in[10];
    char sign_out[10];
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>id>>sign_in>>sign_out;
        if(strcmp(sign_in,early_sign)<=0){
            strcpy(early_id,id);
            strcpy(early_sign,sign_in);
        }
        if(strcmp(sign_out,late_sign)>=0){
            strcpy(late_id,id);
            strcpy(late_sign,sign_out);
        }
    }
    cout<<early_id<<" "<<late_id;
}   