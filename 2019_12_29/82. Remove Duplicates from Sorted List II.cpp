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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* n_head=nullptr;
        ListNode* n_tail=nullptr;
        while(head){
            if(head->next&&head->val==head->next->val){
                while(head->next&&head->next->val==head->val){
                    head=head->next;
                }
            }else{
                if(!n_head){
                    n_head=n_tail=head;
                }else{
                    n_tail->next=head;
                    n_tail=head;
                }
            }
            head=head->next;
        }
        if(n_tail){
            n_tail->next=nullptr;
        }
        return n_head;
    }
};