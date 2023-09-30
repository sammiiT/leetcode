//===類似題===
84. Largest Rectangle in Histogram
1836. Remove Duplicates From an Unsorted Linked List
//===思路===
(*)遇到重複的數值, (cur->val ==cur->next->val)
當下節點跳過next, 連結next->next
(*)沒有遇到重複, 則cur=cur->next;
//=====
ListNode* deleteDuplicates(ListNode* head) {
    ListNode hdr(-1);
    ListNode* cur = head;
    hdr.next = head;
    while(cur&&cur->next){//至少有兩個節點
        if(cur->val ==cur->next->val)
            cur->next = cur->next->next;
        else 
            cur = cur->next;    
    }
    return hdr.next;
}
//===寫法2===
ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* f;
        ListNode* r;
        f = head;
        r = head->next;
        while(r){
            if(f->val==r->val){
                r = r->next;
                f->next = r;
            }else{
                f = r;
                r = r->next;
            }
        }
        return head;
}


//===寫法3===
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
