#include "ListNode.h"
#include <bits/stdc++.h>

//删除指定元素
ListNode* removeElements(ListNode* head, int val) {
    ListNode * dump = new ListNode(-1,head);
    ListNode * p = dump;
    ListNode * temp;
    while(p->next){
        if(p->next->val==val){
            temp = p->next;
            p->next = temp->next;
            delete temp;
        }else{
            p = p->next;
        }
        
    }
    temp = dump->next;
    delete dump;
    return temp;
}

