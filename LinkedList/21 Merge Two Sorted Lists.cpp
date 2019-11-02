class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        
        while(l1||l2){
            int val1 = (l1)?l1->val:INT_MAX;
            int val2 = (l2)?l2->val:INT_MAX;
            int input;
            if(val1<val2){
                input=val1;
                if(l1) l1=l1->next;
            }else{//val1>=val2
                input=val2;
                if(l2) l2=l2->next;
            }
            cur->next = new ListNode(input);
            cur=cur->next;
        }
        
        return dummy->next;
    }
};