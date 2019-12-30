class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* cur,*pre;
        ListNode hdr(-1);
        int n = 0;
        
        cur=head;
        while(cur!=NULL){//計算個數
            cur=cur->next;
            n++;
        }
        k=k%n;
        
        pre = &hdr;
        cur = pre;
        hdr.next= head;
        //計算倒數第k個的前一個
        for(int i=0; i<k; ++i){
            cur= cur->next;
        }
        while(cur && cur->next){
            cur=cur->next;
            pre = pre->next;
        }
        
        cur->next = hdr.next;//第二部分連到第一部分的頭
        hdr.next = pre->next;//頭變成第二部分的頭
        pre->next = NULL;//第一段的尾指向NULL
        return hdr.next;
        
    }
};
	      f
	      |
          v   
    h->O->O->O->O->NULL

		  s	     f
		  | 	 |
          v      v
	h->O->O->O->O->NULL



