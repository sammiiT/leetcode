class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode *pre,*cur;
        ListNode hdr(-1);
        
        pre = &hdr;
        cur = head;
        hdr.next = head;
        
        for(int i=0; i<m-1; ++i){
            cur = cur->next;
            pre = pre->next;
        }
        
        
        for(int i=m; i<n; ++i){
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
             
        }
        
        return hdr.next;
    }
};