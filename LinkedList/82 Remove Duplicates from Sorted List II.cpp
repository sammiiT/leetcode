class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        int same = 0;
        ListNode hdr(-1);
        ListNode *cur,*prev;
        
        hdr.next = head;
        prev = &hdr;
        cur = head;
        
        while(cur && cur->next){//至少有兩個
            if(cur->val==cur->next->val){
                ListNode *tmp=cur->next;
                same = 1;
                cur->next = tmp->next;
                delete tmp;
            }else{
                if(same==1){
                    ListNode *tmp =cur->next;
                    prev->next = tmp;
                    delete cur;
                    cur = tmp;
                    same = 0;
                }else{
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
        
        if(same==1 && cur){
            prev->next = cur->next;
            delete cur;
        }
        return hdr.next;
    }
};