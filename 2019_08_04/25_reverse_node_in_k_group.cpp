/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    std::pair<ListNode*,ListNode*>Reverse( ListNode* head){
        ListNode* new_head=nullptr;
        ListNode* new_tail=nullptr;
        ListNode* cur_node=head;
        while(cur_node){
            ListNode* tmp_next=cur_node->next;
            cur_node->next=new_head;
            new_head=cur_node;
            if(!new_tail){
                new_tail=head;
            }
            cur_node=tmp_next;
        }
        return {new_head,new_tail};
    }
     ListNode* KRemaining( ListNode* head,int k){
        int count=1;
        while(head&&count<k){
            head=head->next;
            count++;
        }
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head=nullptr;
        ListNode* last_tail=nullptr;
        ListNode* next_head=nullptr;
        while(ListNode* tail=KRemaining(head,k)){
            next_head=tail->next;
            tail->next=nullptr;
            std::pair<ListNode*,ListNode*> ret=Reverse(head);
            if(!new_head){
                new_head=ret.first;
            }
            if(last_tail){
                last_tail->next=ret.first;
            }
            last_tail=ret.second;
            head=next_head;
        }
        if(last_tail){
            last_tail->next=head;
        }
        if(!new_head){
            new_head=head;
        }
        return new_head;
    }
};