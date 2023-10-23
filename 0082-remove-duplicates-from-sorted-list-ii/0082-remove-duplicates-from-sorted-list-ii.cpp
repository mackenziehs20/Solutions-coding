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
vector<int>reject;
    void rejected(ListNode* node){
        while(node->next!=nullptr){
            if(node->val==node->next->val){
                reject.push_back(node->val);
            }
            node=node->next;
        }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return head;
        ListNode* res=new ListNode();
        ListNode* temp=res;
        rejected(head);
        while(head!=nullptr){
            auto i=find(reject.begin(),reject.end(),head->val);
            if(i==reject.end()){
                temp->next=new ListNode(head->val);
                temp=temp->next;
            }
            head=head->next;
        }
        return res->next;
    }
};