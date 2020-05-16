/*
Odd Even Linked List
=====================
URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3331/

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/
#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    void insert(ListNode * &head, ListNode * &tail, int val){
        ListNode * temp = new ListNode(val);
        if(head==NULL)
            head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
    }

    void printlist(ListNode * &head){
        if(head==NULL){
            cout<<"Empty List";
            return;
        }
        ListNode * temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    ListNode* oddEvenList(ListNode* &head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode * l1H = NULL;
        ListNode * l2H = NULL;
        ListNode * l1T = NULL;
        ListNode * l2T = NULL;
        ListNode * temp = head;
        int counter = 1;
        
        while(temp!=NULL){
            if(counter==1){
                if(l1H==NULL)
                    l1H=l1T=temp;
                else{
                    l1T->next=temp;
                    l1T=temp;
                }
            }
            else{
                if(l2H==NULL)
                    l2H=l2T=temp;
                else{
                    l2T->next=temp;
                    l2T=temp;
                }
                
            }
            temp=temp->next;
            counter = counter==1?2:1;
        }
        
        l2T->next=NULL;
        l1T->next=l2H;
        return l1H;
        
    }
};

int main(){
    ListNode * head = NULL;
    ListNode * tail = NULL;
    Solution().insert(head,tail,1);
    Solution().insert(head,tail,2);
    Solution().insert(head,tail,3);
    Solution().insert(head,tail,4);
    Solution().insert(head,tail,5);
    Solution().insert(head,tail,6);
    Solution().printlist(head);

    head=Solution().oddEvenList(head);
    Solution().printlist(head);

    
}