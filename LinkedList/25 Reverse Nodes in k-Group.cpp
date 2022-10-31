class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {//swap k node, not reverse list
		if (head==NULL||head->next==NULL) return head;
		
		ListNode *pre,*cur;
        ListNode hdr(-1);
        int n = 0;
        for(ListNode *t = head;t; t=t->next) ++n;
        
        pre = &hdr;
        cur = head;
        pre->next = cur;
        
        int count = n;
        
        //while(count>k){}會出錯, 當count = k時,會出錯
        while(count>=k){
            for(int i=1;i<k;++i){
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            count-=k;
            pre = cur;
            cur =cur->next;
        }
        return hdr.next;
    }
};

/* //fail
ListNode* reverseKGroup(ListNode* head, int k){
    
    ListNode *tmp,*prev,*cur;
    ListNode vnode(-1);
    int i,j;
    
    vnode.next = head;
    prev = tmp = &vnode;
    cur = head;
    
    for(;cur!=NULL;) {
    
        for(i=k; i>0; i--){//是否可以滿足 k-group
            tmp = tmp?tmp->next:NULL;
            if(!tmp) break;
        }
        
        if(i==0) {//如果滿足 k-group, 則開始做轉換
            for(j=0; j<k-1; j++) { 
                ListNode *t= cur->next;
                cur->next = t->next;
                t->next = prev->next;
                prev->next = t;
            }
        } else {//不滿足k-group,則跳出第一級迴圈
          break;  
        }
        
        // 跳到新的group 
        prev = cur;
        cur = cur->next;
    }
    return vnode.next;
}

*/

