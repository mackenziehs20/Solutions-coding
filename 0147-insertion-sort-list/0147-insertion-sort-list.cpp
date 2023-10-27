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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode *start=new ListNode(0);
        start->next=head;
        ListNode *temp=head;
        ListNode *prev1=start;
        while(temp!=NULL)
        {
            ListNode *it=start->next;
            ListNode *prev2=start;
            while(it!=temp)
            {
                if(it->val > temp->val)
                {
                    prev1->next=temp->next;
                    temp->next=it;
                    prev2->next=temp;
                    temp=prev1->next;
                    break;
                }
                prev2=it;
                it=it->next;
            }
            if(it==temp)
            {
                prev1=temp;
                temp=temp->next;
            }
        }
        return start->next;
    }
};