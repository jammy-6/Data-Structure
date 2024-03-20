#include <bits/stdc++.h>
using namespace std;

// 如何判断图是否为连通图，通过连通分量的数量来判断
// 如果遍历到的点刚好为被破坏的城市，则不+1
void dfs(int city);
vector<vector<int>> roads(1010);
bool visit[1010];
int n, m, k,check;
int main()
{

    cin >> n >> m >> k;
    // 构建邻接矩阵
    int start, end;

    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        roads[start].push_back(end);
        roads[end].push_back(start);
    }

    for(int i=0;i<k;i++){
        cin>>check;
        memset(visit,0,sizeof(visit));
        int sum=0;
        for(int j=1;j<=n;j++){
            if(j!=check&&visit[j]==0){
                sum++;
                dfs(j);
            }
        }
        cout<<sum-1<<endl;
        
    }
  
}

void dfs(int city)
{
    visit[city] = true;
    for(int i=0;i<roads[city].size();i++){
        if(!visit[ roads[city][i] ]&&roads[city][i]!=check){
            dfs(roads[city][i]);
        }
    }
}