class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL|| head->next==NULL) return head;
        ListNode hdr(-1);
        ListNode *pre,*cur;
        
        pre = &hdr;
        cur= head;
        hdr.next = head;
        
        while(cur && cur->next){
            if(cur->val!=cur->next->val){
                pre=cur;
                cur=cur->next;
            }else{//cur->val == cur->next->val
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
        }
        return hdr.next;
        
    }
};