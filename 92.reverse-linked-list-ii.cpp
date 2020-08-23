/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n||head==nullptr){
            return head;
        }
        ListNode* pre_start=nullptr;
        ListNode* start = head;
        ListNode* end = head;
        ListNode* cur = head;
        int count=1;
        while(count<m){
            pre_start=cur;
            cur=cur->next;
            ++count;
        }
        end = cur;
        start =cur;
        cur=cur->next;
        ++count;
        ListNode* next=nullptr;
        while(count<=n){
           next=cur->next;
           cur->next=start;
           start=cur;
           cur=next; 
           ++count;
        }
        if(pre_start==nullptr){
            head=start;
        }else{
            pre_start->next=start;
        }
        end->next=next;
        return head;
    }
};
// @lc code=end

