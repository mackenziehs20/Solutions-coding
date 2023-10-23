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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base call
        if(head == NULL) {
        return NULL;
        }
         
        //step1-we check that if k group is avaliable or not to reverse
        int avaliable= k, count = 0;
        ListNode* temp = head;
        while(avaliable > 0 && temp != NULL){
            temp = temp -> next;
           avaliable--;
        }
        
        if(avaliable == 0){
       // step2: reverse first k nodes

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        while(curr != NULL && count < k) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
       }
        // step3: Recursive call
        if(next != NULL) {
        head->next = reverseKGroup(next, k);
       }
       // step4: return head of reversed list
       return prev;
      }
      return head;
    }
};