#include <iostream>
#include <vector>
#include <deque>
using namespace std;



typedef struct Node{
    vector<struct Node *> childs;
}Node;

int n,m;//
Node tree[100];
int main(void){
    cin>>n>>m;
    int id,num,child;
    for(int i=0;i<m;i++){
        cin>>id>>num;
        for(int j=0;j<num;j++){
            cin>>child;
            tree[id].childs.push_back(&tree[child]);
        }
    }
    deque<Node *> list = {&tree[1]};
    Node * last = &tree[1];
    Node *p;
    int count = 0;
    vector<int> rs;

    //进行树的层次遍历
    while(list.size()){
        p = list[0];
        //判断当前节点是否为叶子节点
        if(p->childs.size()){
            for(int i=0;i<p->childs.size();i++){
                list.push_back(p->childs[i]);
            }
        }else{
            count++;
        }

        list.pop_front();

        if(p==last){
            rs.push_back(count);
            count =0;
            if(list.size()!=0)
                last = list[list.size()-1];
        }
    }

    for(int i=0;i<rs.size();i++){
        cout<<rs[i];
        if(i+1!=rs.size()) cout<<" ";
    }
}