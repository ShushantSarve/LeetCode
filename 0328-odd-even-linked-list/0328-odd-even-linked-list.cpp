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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL){
            return NULL;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* oddTemp = odd;
        ListNode* evenTemp = even;
        
        while(odd != NULL || even != NULL){
            
            if(oddTemp->next == NULL || evenTemp->next == NULL){
                oddTemp->next = even;
                break;
            }
            
            oddTemp->next = evenTemp->next;
            oddTemp = evenTemp->next;
            
            evenTemp->next = oddTemp->next;
            evenTemp = oddTemp->next;
            
        }
        return head;
    }
};