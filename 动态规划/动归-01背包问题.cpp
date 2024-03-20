#include<bits/stdc++.h>
using namespace std;


class Thing{
public:
    int weight; //物品重量
    int value;  //物品价值
    friend bool operator<(const Thing&t1,const Thing&t2){
        if(t1.weight==t2.weight)return t1.value<t2.value;
        return t1.weight<t2.weight;
    }  
};

//动态规划思想
int main(){
    //填充数据
    int M,N;
    cin>>M>>N;
    vector<Thing> ts(M,Thing());
    for(int i=0;i<M;i++) cin>>ts[i].weight;
    for(int i=0;i<M;i++) cin>>ts[i].value;
    sort(ts.begin(),ts.end());
    vector<vector<int>> dp=vector<vector<int>>(M,vector<int>(N+1,0));
    //初始化操作
    for(int j=ts[0].weight;j<=N;j++) dp[0][j]=ts[0].value;
    //递推公式
    for(int i=1;i<M;i++){
        for(int j=0;j<=N;j++){
            if(j<ts[i].weight){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-ts[i].weight]+ts[i].value);
            }
        }
    }
    cout<<dp[M-1][N];
}