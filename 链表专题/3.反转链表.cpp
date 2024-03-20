#include "ListNode.h"
#include <bits/stdc++.h>


class Solution {
public:

    //非递归版本
    ListNode* reverseList_v1(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *temp = NULL;

        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    ListNode* reverseList(ListNode* head) {
        //return reverseList_v2(head,NULL);
        return reverseList_v3(head);
    }

    //递归版本
    ListNode* reverseList_v2(ListNode* head,ListNode *pre) {
        if(head==NULL) return pre;
        else{
            ListNode *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
            return reverseList_v2(head,pre);
        }
    }

    //递归版本
    ListNode* reverseList_v3(ListNode* head) {
        if(head==NULL) return NULL;
        else if(head->next==NULL) return head;
        else{
            ListNode *last = reverseList_v3(head->next);
            head->next->next = head;
            head->next = NULL;
            return last;
        }
    }
};