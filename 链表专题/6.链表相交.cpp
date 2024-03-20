#include "ListNode.h"
#include <bits/stdc++.h>


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA,*curB = headB;
        int lenA=0,lenB=0;
        while(curA){
            ++lenA;
            curA = curA->next;
        }

        while(curB){
            ++lenB;
            curB = curB->next;
        }
        curA = headA,curB = headB;
        if(lenB>lenA){
            swap(lenA,lenB);
            swap(curA,curB);
        }

        int diff = lenA-lenB;
        while(--diff >=0&&curA){
            curA = curA->next;
        }

        while(curA&&curB){
            if(curA==curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return NULL;
    }
};
