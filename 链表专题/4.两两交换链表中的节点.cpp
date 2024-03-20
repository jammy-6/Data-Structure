#include "ListNode.h"
#include <bits/stdc++.h>


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *tempHead  = new ListNode(-1,head);
        ListNode *p = tempHead;
        ListNode *temp;
        while(p->next && p->next->next){
            temp = p->next->next;
            p->next->next = temp->next;
            temp->next = p->next;
            p->next = temp;
            p= p->next->next;
        }
        return tempHead->next;
    }
};