#include <iostream>
#include <algorithm>
using namespace std;

int k,temp;



int main(){

    cin>>k;
    int *nums = new int[k+1];
    int *sum = new int[k+1];

    for(int i=1;i<=k;i++){
        cin>>nums[i];
    }
    sum[0] = 0;
    for(int i=1;i<=k;i++){
        sum[i] = sum[i-1]+nums[i];
    }

    int start=-1,end=-1,max_sum=0;
    int * min_index = sum;
    for(int i=1;i<=k;i++){
        
        if(sum[i] - *min_index>max_sum ||(max_sum==0&&(sum[i] - *min_index )==0)){
            max_sum = sum[i] - *min_index;
            start = nums[min_index-sum+1];
            end = nums[i];
        }
        if(*min_index>sum[i]) min_index = sum+i;
    }


    if(start!=-1&&end!=-1)
        cout<<max_sum<<" "<<start<<" "<<end;
    else
        cout<<0<<" "<<nums[1]<<" "<<nums[k];

}

