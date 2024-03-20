#include <iostream>
#include <vector>
#include <cctype>

using namespace std;
int m,n,c1,c2;
int num_of_teams[500],mindis[500];
vector<int> v[500];
int dis[500][500];
int paths,teams;

void dfs(int cur,int cur_len,int cur_teams){
    //cur_len过长，及时止损
    if(cur_len>mindis[cur]) return;
    if(cur==c2){
        if(cur_len==mindis[c2]){
            paths++;
            if(cur_teams>teams) teams = cur_teams;
        }else{
            mindis[cur] = cur_len;
            paths = 1;
            teams = cur_teams;
        }
    }else{
        if(cur_len<mindis[cur]){
            mindis[cur] = cur_len;
        }
        for(int i=0;i<v[cur].size();i++){
            int j=v[cur][i];
            dfs(j,cur_len+dis[cur][j],cur_teams+num_of_teams[j]);
        }
    }


}


int main()
{
    cin>>m>>n>>c1>>c2;
    
    for(int i=0;i<m;i++) cin>>num_of_teams[i];
    int j,k,l;
    for(int i=0;i<n;i++){
        cin>>j>>k>>l;
        v[j].push_back(k);
        v[k].push_back(j);
        dis[j][k] = l;
        dis[k][j] = l;
    }
    for(int i=0;i<m;i++) mindis[i] = 100000000;
    dfs(c1,0,num_of_teams[c1]);
    cout<<paths<<" "<<teams;
}