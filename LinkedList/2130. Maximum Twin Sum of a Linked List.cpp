//====類似題 =====
2131. Longest Palindrome by Concatenating Two Letter Words
763. Partition Labels
654. Maximum Binary Tree

int helper0(ListNode* head){
        ListNode *f,*r;
        ListNode hdr(-1);
        stack<ListNode*> stk;
        int res = 0;

        hdr.next=head;
        f = r = &hdr;

        while(r&&r->next){
            f=f->next;
            r=r->next->next;        
        }

        r = f->next;
        f->next=NULL;//截斷,少了這個會錯
        f=hdr.next;
        while(f){
            stk.push(f);
            f = f->next;
        }
        while(r){
            res = max(res,(r->val + stk.top()->val));
            stk.pop();
            r=r->next;
        }
        return res;
}

int pairSum(ListNode* head) {
        return helper0(head);    
}
