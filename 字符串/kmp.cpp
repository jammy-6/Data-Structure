#include <iostream>
#include <string>
#include <vector>
using namespace std;

//aabaacaabaa

vector<int> getNext(string patt){
    vector<int> next;
    next.push_back(0);
    int pattLen = 0;
    int i = 1;
    while(i<patt.size()){
        if(patt[pattLen]==patt[i]){
            next.push_back(++pattLen);
            i++;
        }else{
            if(pattLen==0){
                next.push_back(0);
                i++;
            }else{
                pattLen = next[pattLen-1];
            }
        }
    }

    return next;
}

int strStr(string str,string patt){
    vector<int> next = getNext(patt);
    int i=0,j=0;
    while(i<str.size()){
        if(str[i]==patt[j]){
            i++,j++;
        }else if(j>0){
            j=next[j-1];
        }else{
            i+=1;
        }
        if(j==patt.size()){
            return i-j;
        }
    }
}

int main(){
    string patt = "aabaaf";
    vector<int> next = getNext(patt);
    for(int i=0;i<next.size();i++) cout<<next[i]<<" ";
}