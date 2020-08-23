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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* my_head=nullptr;
        ListNode* my_tail=nullptr;
        if(!second) return head;
        while(first&&second){
            ListNode* next_first=first->next->next;
            second->next=first;
            first->next=nullptr;
            if(!my_head){
                my_head=second;
            }
            if(my_tail){
                my_tail->next=second;
            }
            my_tail=first;
            first=next_first;
            if(!next_first||!next_first->next){
                my_tail->next=next_first;
                break;
            }
            second=next_first->next;
        }
        return my_head;
    }
};