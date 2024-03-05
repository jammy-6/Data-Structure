#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cur = 0,next,sum=0;
    for(int i=0;i<n;i++){
        cin>>next;
        if(next>cur)
            sum+=6*abs(cur-next);
        else if(next<cur)
            sum+=4*abs(cur-next);
        cur = next;
    }

    sum+=5*n;
    cout<<sum;

    return 0;
}