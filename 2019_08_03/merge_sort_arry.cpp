
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* tail;
        head=tail=NULL;
        while(l1&&l2){
            if(!head){
                if(l1->val<l2->val){
                    head=l1;
                    tail=l1;
                    l1=l1->next;
                    tail->next=NULL;
                }else{
                    head=l2;
                    tail=l2;
                    l2=l2->next;
                    tail->next=NULL;
                }
            }else{
                if(l1->val<l2->val){
                    tail->next=l1;
                    l1=l1->next;
                    tail=tail->next;
                    tail->next=NULL;
                }else{
                    tail->next=l2;
                    l2=l2->next;
                    tail=tail->next;
                    tail->next=NULL;
                }
            }
        }
        if(l1){
            if(!head){
                head=l1;
            }else{
                tail->next=l1;
            }
        }
        if(l2){
            if(!head){
                head=l2;
            }else{
                tail->next=l2;
            }
        }
         return head;
    }
       
};