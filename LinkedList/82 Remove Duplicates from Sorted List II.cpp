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

ListNode* deleteDuplicates_II(ListNode* head) {
        ListNode *prev,*cur;
        ListNode vnode(-1);
        int duplicate = 0;
        
        vnode.next = head;
        prev = &vnode;
        cur = head;
        
        for(;cur&&cur->next;){

            if((cur->val)==(cur->next->val)) {//相等
                ListNode *tmp = cur->next->next;
                delete cur->next;
                cur->next = tmp;
                duplicate = 1;

            } else {//不相等
                if(duplicate){
                    ListNode *tmp = cur;
                    cur = cur->next;
                    prev->next = cur;
                    delete tmp;
                    duplicate = 0;
                } else {
                    prev=prev->next;    
                    cur=cur->next;
                }
            }
        }
        
        if(duplicate){//[1,1] => output []
                    ListNode *tmp = cur;
                    cur = cur->next;
                    prev->next = cur;
                    delete tmp;
                    duplicate = 0;
        } 
        return vnode.next;    
}

Input: 1->2->3->3->4->4->5
Output : 1->2->5

Input : 1->1->1->2->3
Output : 2->3
