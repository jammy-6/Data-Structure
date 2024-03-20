#include "ListNode.h"
#include <bits/stdc++.h>


class Solution {
public:

    //快慢指针判断是否存在环形链表，返回环形链表入口
    ListNode *detectCycle(ListNode *head) {
        ListNode *fp = head,*sp=head;
        while(fp&&fp->next){
            sp=sp->next;
            fp=fp->next->next;

            if(fp==sp){ //存在环，开始找入口
                ListNode* index1=head,*index2=fp;
                while(index1!=index2){
                    index1=index1->next;
                    index2=index2->next;
                } 
                return index1;
            }

        }
        return NULL;
    }
};