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