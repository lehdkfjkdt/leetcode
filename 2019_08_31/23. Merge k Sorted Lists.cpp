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
    ListNode* mergeTwoLists(ListNode* l, ListNode* r){
        ListNode* pre=new ListNode(0);
        ListNode* tail=pre;
        while(l&&r){
            if(l->val<r->val){
                tail->next=l;
                tail=tail->next;
                l=l->next;
            }else{
                tail->next=r;
                tail=tail->next;
                r=r->next;
            }
        }
        if(l){
            tail->next=l;
        }
        if(r){
            tail->next=r;
        }
        ListNode* ret=pre->next;
        delete pre;
        return ret;
    }
    ListNode* mergeLists(vector<ListNode*>& lists, int l_index,int r_index){
        if(l_index==r_index){
            return lists[l_index];
        }else if(r_index-l_index==1){
            return mergeTwoLists(lists[l_index],lists[r_index]);
        }else{
            int mid=(l_index+r_index)/2;
            ListNode* l_ret=mergeLists(lists,l_index,mid);
            ListNode* r_ret=mergeLists(lists,mid+1, r_index);
            return mergeTwoLists(l_ret,r_ret);
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.size()==0){
             return nullptr;
         }else if(lists.size()==1){
             return lists[0];
         }else{
             return mergeLists(lists,0,lists.size()-1);
         }
    }
};