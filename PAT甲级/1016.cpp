#include <bits/stdc++.h>
using namespace std;

class Record{
    public:
    int sM=-1,sD,sh,sm;
    int eM=-1,eD,eh,em;
    int lasting=0;
    int price=0;
};
class Customer{
    public:
    string name;
    int month;
    Record recs[32];
};

void handle(Customer &cus,string time,string type);
//single price for per hour
vector<int> sp_ph(25);
map<string,Customer> cuss;
void check(Customer &cus);
int main(){
    int dp = 0;
    for(int i=0;i<24;i++){
        cin>>sp_ph[i];
        dp+=sp_ph[i]*60;
    }
    sp_ph[24] = dp;

    int n;
    cin>>n;
    string name,time,type;
    

    for(int i=0;i<n;i++){
        cin>>name>>time>>type;
        if(cuss.count(name)){
            handle(cuss[name],time,type);
        }else{
            Customer cus;
            cus.name=name;
            handle(cus,time,type);
            cuss[name]=cus;
        }
    }


    for(auto it=cuss.begin();it!=cuss.end();it++){
        check(it->second);
        printf("%s %02d\n",it->first.c_str(),it->second.month);
        const Customer & cur_cus = it->second;
        double total_price = 0;
        for(int i=1;i<32;i++){
            if(cur_cus.recs[i].sM!=-1&&cur_cus.recs[i].eM!=-1){
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                cur_cus.recs[i].sD,cur_cus.recs[i].sh,cur_cus.recs[i].sm,
                cur_cus.recs[i].eD,cur_cus.recs[i].eh,cur_cus.recs[i].em,
                cur_cus.recs[i].lasting,
                cur_cus.recs[i].price/100.0
                );
                total_price+= cur_cus.recs[i].price/100.0;
            }
        }
        printf("Total amount: $%.2lf\n",total_price);
    }



}
void handle(Customer &cus,string time,string type){
    int M,D,h,m;
    sscanf(time.c_str(),"%d:%d:%d:%d",&M,&D,&h,&m);
    cus.month = M;
    if(type=="on-line"){
        cus.recs[D].sM=M;
        cus.recs[D].sD=D;
        cus.recs[D].sh=h;
        cus.recs[D].sm=m;
    }else{
        cus.recs[D].eM=M;
        cus.recs[D].eD=D;
        cus.recs[D].eh=h;
        cus.recs[D].em=m;
    }


}

void check(Customer &cus){
    int sM,sD,sh,sm;
    int eM,eD,eh,em;
    for(int i=1;i<32;i++){
        if(cus.recs[i].sM!=-1&&cus.recs[i].eM==-1){
            int j;
            bool flag = false;
            for(j=i+1;j<32;j++){
                if(cus.recs[j].sM!=-1&&cus.recs[j].eM==-1){
                    break;
                }
                if(cus.recs[j].sM==-1&&cus.recs[j].eM!=-1){
                    flag=true;
                    break;
                }
            }
            if(flag){
                cus.recs[i].eD = cus.recs[j].eD;
                cus.recs[i].eM = cus.recs[j].eM;
                cus.recs[i].eh = cus.recs[j].eh;
                cus.recs[i].em = cus.recs[j].em;
            }else{
                continue;
            }

        }

        if(cus.recs[i].sM!=-1&&cus.recs[i].eM!=-1){
            cus.recs[i].lasting = (cus.recs[i].eD-cus.recs[i].sD)*1440
                            +(cus.recs[i].eh-cus.recs[i].sh)*60
                            +(cus.recs[i].em-cus.recs[i].sm);

            //计算这次通话的费用
            int sD=cus.recs[i].sD,
            sh = cus.recs[i].sh,
            sm=cus.recs[i].sm,
            eD=cus.recs[i].eD,
            eh=cus.recs[i].eh,
            em=cus.recs[i].em;
            int price = 0;
            
            if(sD!=eD){
                price+=(60-sm)*sp_ph[sh];
                for(int j=sh+1;j<=23;j++)
                    price+=sp_ph[j]*60;
                for(int j=sD+1;j<eD;j++)
                    price+=sp_ph[24];
                
                for(int j=eh-1;j>=0;j--)
                    price+=sp_ph[j]*60;
                price+=(em)*sp_ph[eh];
            }else if(eh!=sh){
                price+=(60-sm)*sp_ph[sh];
                for(int j=sh+1;j<eh;j++)
                    price+=sp_ph[j]*60;
                price+=(em)*sp_ph[eh];
            }else{
                price+=(em-sm)*sp_ph[eh];
            }
            cus.recs[i].price = price;
        }

        
    }

    
}