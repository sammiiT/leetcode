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

};