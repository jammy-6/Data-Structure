#include "ListNode.h"
#include <bits/stdc++.h>

class MyLinkedList {

ListNode *head; 
public:
    MyLinkedList() {
        head = new ListNode(-1,NULL);
    }
    void display(){
        ListNode *p = head->next;
        while(p){
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    int get(int index) {
        ListNode *p = head;
        while(p->next){
            index--;
            if(index<0) break;
            p = p->next;
        }
        if(p->next) return p->next->val;
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode * addNode = new ListNode(val,head->next);
        addNode->next = head->next;
        head->next = addNode;

    }
    
    void addAtTail(int val) {
        ListNode *addNode = new ListNode(val,NULL);
        ListNode *p = head; 
        while(p->next){
            p=p->next;
        }
        p->next = addNode;
    }
    
    void addAtIndex(int index, int val) {
        
        ListNode *addNode = new ListNode(val,NULL);
        ListNode *p = head; 
        while(p->next||index==0){
            index--;
            if(index<0) break;
            p=p->next;
        }
        if(index<0 && p){
            addNode->next = p->next;
            p->next = addNode;
        }

    }
    
    void deleteAtIndex(int index) {
        ListNode *p = head;
        while(p->next){
            index--;
            if(index<0) break;
            p=p->next;
        }
        if(p->next){
            ListNode *temp = p->next;
            p->next = temp->next;
            delete temp;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */