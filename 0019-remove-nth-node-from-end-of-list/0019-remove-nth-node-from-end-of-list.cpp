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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL){
            return NULL;
        }
        
        ListNode* one = head;
        ListNode* two = head;
        
        //creating a gap of n nodes
        for(int i = 1; i <= n; i++){
            one = one->next;
        }
        if(one == NULL){
            return head->next;
        }
        
        while(one->next){
            one = one->next;
            two = two->next;
        }
        ListNode* tempe = two->next;
        two->next = tempe->next;
        delete(tempe);
        
        return head;
        
        
    }
};