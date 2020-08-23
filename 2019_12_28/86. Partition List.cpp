/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l_head= nullptr;
        ListNode* l_tail= nullptr;
        ListNode* r_head= nullptr;
        ListNode* r_tail= nullptr;
        ListNode* cur=head;
        if(!head){
            return head;
        }
        while(cur){
            if(cur->val<x){
                if(l_head==nullptr){
                    l_head=cur;
                    l_tail=cur;
                }else{
                    l_tail->next=cur;
                    l_tail=cur;
                }
            }else{
                if(r_head==nullptr){
                    r_head=cur;
                    r_tail=cur;
                }else{
                    r_tail->next=cur;
                    r_tail=cur;
                }
            }
            cur=cur->next;
        }
        if(l_head&&r_head){
            l_tail->next=r_head;
            r_tail->next=nullptr;
        }else if(l_head){
            return l_head;
        }else{
            return r_head;
        }
        return l_head;
    }
};