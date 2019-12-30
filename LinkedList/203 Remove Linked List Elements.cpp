class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur=new ListNode(-1),*dummy;
        if(head==NULL) return head;
        
        cur->next = head;
        dummy = cur;
        
        // while(cur && cur->next){
        while(cur->next){
            if(cur->next->val==val){
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }else
               cur=cur->next;
        }
        
        return dummy->next;
    }
};
Input:  1->2->6->3->4->5->6, val = 6
Output : 1->2->3->4->5