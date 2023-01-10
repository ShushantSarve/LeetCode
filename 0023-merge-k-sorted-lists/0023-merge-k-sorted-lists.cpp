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

class compare{
  public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }    
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // create min heap with listNode* type by creating compare function
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        int k = lists.size();
        if(k == 0) return NULL;
        
        // insert the 1st element of every linked list
        for(int i=0; i<k; i++){
            if(lists[i]){
                minHeap.push(lists[i]);
            }
        }
        
        // initalise two pointers head and tail
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(!minHeap.empty()){
            
            ListNode* temp = minHeap.top();
            minHeap.pop();
            
            if(temp->next){
                minHeap.push(temp->next);
            }
            
            if(!head){
                // inserting if linked list is empty
                head = temp;
                tail = temp;
            }
            else{
                // inserting in filled linked list
                tail->next = temp;
                tail = temp;
            }
        }
        return head;        
    }
};