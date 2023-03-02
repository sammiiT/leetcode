//===類似題===
25. Reverse Nodes in k-Group
1206. Design Skiplist
439. Ternary Expression Parser
1171. Remove Zero Sum Consecutive Nodes from Linked List
//===思路===
(*)至少要有兩個節點,才能計算
- while(r&&r->next){} //至少有兩個節點

(*)要有三個節點;假設為f,r,t; 其中t為r->next

   f  r  t                       f  t  r                                   f  r  t=r->next  
   h  o  o  o  o  o  o  x    =>  h  o  o  o  o  o  o  x   =>更新指標  h  o  o  o  o  o  o  x       

f作為連結前一個list的節點
r,t作為兩者交換的節點
//======
    ListNode* swapPairs(ListNode* head) {
        ListNode hdr(-1);
        ListNode *f,*r;//,*c;
        hdr.next = head;
        f = &hdr;
        r = hdr.next;
    
// f r t
        while(r&&r->next){
            ListNode *t = r->next;
            r->next = t->next;
            t->next = r;
            f->next = t;

            f = r;
            r = r->next;
        }
        return hdr.next;
    }
//======
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
        ListNode hdr(-1);
        ListNode *cur,*pre;
        
        pre = &hdr;
        cur = head;
        hdr.next = head;
        //延伸至K個節點的swap
        while(cur!=NULL){
        for(int i=1; i<2; ++i){
            if(cur&&cur->next){
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
        }
        pre = cur;
        cur=cur->next;
        }
        return hdr.next;
    }
    
    ListNode* swapPairs_OK(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
        ListNode hdr(-1);
        ListNode *cur,*prev;
        
        hdr.next = head;
        prev = &hdr;
        cur = head;
        
        //至少要有兩個,才能作swap
        while(cur && (cur->next!=NULL)){
            ListNode *tmp1;
            ListNode *tmp2;
            
            tmp1 = cur->next;
            tmp2 = tmp1->next;
            
            tmp1->next = cur;
            cur->next = tmp2;
            prev->next = tmp1;
            
            prev = cur;
            cur = tmp2;                   
            
            
/*
            cur = tmp2;
            prev= tmp1->next; 
*/            
        }
        return hdr.next;
    }


	ListNode* swapPairs_OK2(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode hdr(-1);
		ListNode *pre, *cur;
		pre = &hdr;
		pre->next = head;
		cur = head;

		while (cur && cur->next) {
			ListNode* tmp = cur->next;
			cur->next = tmp->next;
			tmp->next = pre->next;
			pre->next = tmp;
			pre = cur;
			cur = cur->next;
		}
		return hdr.next;
	}
	 
	 
    ListNode* swapPairs_3(ListNode* head) {
        ListNode *prev,*cur,*tmp;
        ListNode vnode(-1);
        int i = 0;
        
        vnode.next = head;
        prev = tmp = &vnode;
        cur = head;
        
        for(;cur!=NULL;){
            for(i=2;i>0;i--){
                tmp = tmp->next;
                if(!tmp) break;
            }
        
            if(i==0){//
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = prev->next;
                prev->next = t;
                
            }else{//remain
                break;
            }
            
            prev = tmp = cur;
            cur = cur->next;
        }
        return vnode.next;
    }	 

};
