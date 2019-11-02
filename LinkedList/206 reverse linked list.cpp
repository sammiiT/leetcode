class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *cur,*pre;
        if(head==NULL||head->next==NULL) return head;
        
        cur = head;
        pre = NULL;
        while(cur!=NULL){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    
    
    ListNode* reverseList_ok(ListNode* head) {
        ListNode *cur,*pre;
        ListNode hdr(-1);
        
        if(head==NULL||head->next==NULL) return head;
        hdr.next = head;
        pre = &hdr;
        cur = head;
        
        
        while(cur!=NULL){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        head->next=NULL;
        return pre;
        
    }
};