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
    ListNode* findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==NULL && right==NULL)return NULL;
        if(left==NULL)return right;
        if(right==NULL)return left;
        ListNode* ans=new ListNode(-1);
        ListNode* i=left;
        ListNode* j=right;
        ListNode* c=ans;
        while(i && j){
            if(i->val >= j->val){
                c->next=j;
                c=j;
                j=j->next;
            }
            else{
                c->next=i;
                c=i;
                i=i->next;
            }
        }
        if(i){
            c->next=i;
        }
        else if(j){
            c->next=j;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* left=head;
        ListNode* mid=findmid(head);
        ListNode* right=mid->next;
        mid->next=NULL;
        //divide
        left=sortList(left);
        right=sortList(right);
        //merge
        ListNode* mergedLL=merge(left,right);
        return mergedLL;
    }
};