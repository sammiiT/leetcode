class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL|| head->next==NULL) return head;
        ListNode hdr(-1);
        ListNode *pre,*cur;
        
        pre = &hdr;
        cur= head;
        hdr.next = head;
        
        while(cur && cur->next){
            if(cur->val!=cur->next->val){
                pre=cur;
                cur=cur->next;
            }else{//cur->val == cur->next->val
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
        }
        return hdr.next;        
    }

	ListNode* deleteDuplicates_OK(ListNode* head) {//不需要hdr,且不需要pre
		if (head == NULL || head->next == NULL) return head;
		ListNode *pre, *cur;

		pre = cur = head;
		while (cur && cur->next) {//至少兩個
			ListNode* tmp = cur->next;
			if (cur->val == tmp->val) {
				cur->next = tmp->next;
				delete tmp;
			}
			else {
				cur = cur->next;
			}
		}
		return pre;
	}

	 
ListNode* deleteDuplicates_2(ListNode* head) {
        ListNode* f;
        f = head;
        
        while(f && f->next){
            if(f->val==f->next->val){
                ListNode* tmp = f->next;
                f->next = f->next->next;
                delete tmp;
            }else{
                f = f->next;
            }
        }
        return head;
}	 
	 

};

Input: 1->1->2->3->3
Output : 1->2->3

Input : 1->1->2
Output : 1->2
