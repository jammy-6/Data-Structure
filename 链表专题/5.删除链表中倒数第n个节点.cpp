#include "ListNode.h"
#include <bits/stdc++.h>


class Solution {
public:
    //快慢指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tempHead = new ListNode(-1,head);
        ListNode *slow=tempHead,*fast=tempHead;
        while(fast && n--){
            fast=fast->next;
        }
        while(fast&&fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next = slow->next->next;
        return tempHead->next;
    }
};