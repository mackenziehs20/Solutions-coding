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
    ListNode *detectCycle(ListNode *head) {

        

        if(head==NULL || head ->next==NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* meet = NULL;
        int count = 0;
        while(fast&&fast->next){
          //  prev = slow;
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
             meet = slow;
             break;
               
            }
        }
        ListNode* curr = head;
      if(meet == NULL){
          return NULL;
      }
      else{
       while(curr!=meet){
           meet=meet->next;
           curr=curr->next;
       }
       return meet;
      }
        
    }
};