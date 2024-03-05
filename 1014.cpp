#include <bits/stdc++.h>
using namespace std;

typedef struct stu{

    int process_time;
    int start_time;
    int finsh_time;
}Stu;

int n,m,k,q;
int main(){
    cin>>n>>m>>k>>q;
    deque<Stu> queues[n];
    vector<Stu> stus(k);
    for(int i=0;i<k;i++){
        cin>>stus[i].process_time;
    }
    

    for(int i=0;i<n*m;i++){
        if(i<n){
            stus[i].start_time = 480;
            stus[i].finsh_time = stus[i].start_time+stus[i].process_time;
        }else{
            stus[i].start_time = queues[i%n].back().finsh_time;
            stus[i].finsh_time = stus[i].start_time + stus[i].process_time;
        }
        queues[i%n].push_back(stus[i]);
    }

    for(int i=n*m;i<k;i++){
        int min_idx = 0;
        for(int j=1;j<n;j++){
            if(queues[j].front().finsh_time< queues[min_idx].front().finsh_time){
                min_idx = j;
            }
        }
        stus[i].start_time = queues[min_idx].back().finsh_time;
        stus[i].finsh_time = stus[i].start_time + stus[i].process_time;
        
        if(stus[i].finsh_time<=17*60){
            queues[min_idx].pop_front();
            queues[min_idx].push_back(stus[i]);
        }

    }

    int query_num;
    for(int i=0;i<q;i++){
        cin>>query_num;
        query_num--;
        if(stus[query_num].finsh_time <=17*60)
            printf("%02d:%02d\n",stus[query_num].finsh_time/60,stus[query_num].finsh_time%60);
        else
            printf("Sorry\n");
    }





}