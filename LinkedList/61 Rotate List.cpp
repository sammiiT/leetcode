//===類似題===
62. Unique Paths
1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers
1836. Remove Duplicates From an Unsorted Linked List
1634. Add Two Polynomials Represented as Linked Lists
//===思路===


//=====
ListNode* helper(ListNode* head, int k) {
    ListNode hdr(-1);
    ListNode *f,*r;
    
    if(!head||!head->next) return head;
    hdr.next = head;
    f=r=&hdr;
/*計算節點個數*/    
    int cnt = 0;
    while(r&&r->next){
        r=r->next;
        cnt++;
    }
/*計算k是不是會超出cnt範圍*/    
    k%=cnt;//k=k/cnt;
    if(k==0) return head;
    
/*計算要被rotate節點的前一個節點, */
    r = f;
    for(int i=0;i<k;i++){ r=r->next; }
    while(r&&r->next){
        f=f->next;
        r=r->next;
    }
/*執行rotate,區段重新段開再連結*/
    ListNode* tmp = f->next;
    f->next = r->next;
    r->next = hdr.next;
    hdr.next = tmp;

    return hdr.next;

}


//===
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

ListNode* rotateRight(ListNode* head, int k) {
        ListNode *prev,*cur;
        ListNode vnode(-1);
        int n=0;
        
        
        for(ListNode *t = head; t; t = t->next) n++;
        if(n==0) return NULL;
        k=k%n;
        
        vnode.next = head;
        prev = &vnode;
        cur = head;
        
        //(n-k)//位移(n-k)次
        for(int i=0; i<(n-k); i++){
            prev = prev->next;
            cur = cur->next;
        }
        
        prev->next = NULL;//
        vnode.next = cur;//
        
        prev = &vnode;
        for(;cur!=NULL;){
            prev = prev->next;
            cur = cur->next;
        }        
        prev->next = head;
        
        return vnode.next;
    }


