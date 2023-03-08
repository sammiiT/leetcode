//====類似題 =====
2131. Longest Palindrome by Concatenating Two Letter Words
763. Partition Labels
654. Maximum Binary Tree
//===思路2===
int helper2(ListNode* head) {
    int res=0;
    stack<ListNode*> stk;
    ListNode hdr(-1);
    ListNode *f,*b;
    hdr.next = head;
    f = b = &hdr;
    while(b&&b->next){
        f=f->next;
        b=b->next->next;
    }
    b = f->next;
    while(b){
        stk.push(b);
        b=b->next;
    }
    f = hdr.next;
    while(!stk.empty()){
        res = max(res,(stk.top()->val+ f->val));
        stk.pop();
        f = f->next;
    }
    return res;
}

//===思路===
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
        f->next=NULL;//截斷,少了這個會錯,用stack做,不用考慮此
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
