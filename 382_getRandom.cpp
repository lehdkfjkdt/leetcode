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
    ListNode* head_=nullptr;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head_=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i=1;
        ListNode* cur=head_;
        int ret=-1;
        while(cur!=nullptr){
            if(rand() % (i) == 0){
                ret=cur->val;
            }
            cur=cur->next;
            i++;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */