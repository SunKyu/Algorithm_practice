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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode prenode(0);
        ListNode* p = &prenode;
        
        int sum = 0;
        int carry = 0;
        while(l1  || l2  || carry ){
            int val1 = 0;
            int val2 = 0;
            if(l1){
                val1 = l1->val;
                l1 = l1->next;
            }
            if(l2){
                val2 = l2->val;
                l2 = l2->next;
            }
            sum = (val2+val1+carry);
            carry = (sum)/10;
            p->next = new ListNode(sum%10);
            p = p->next;
            
        }
        return prenode.next;
    }
};