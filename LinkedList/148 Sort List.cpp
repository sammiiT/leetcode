class Solution {
public:
	//跟merge sort做比較
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
        // ListNode hdr(-1);
        ListNode *f,*s,*pre;
        f=s=pre=head;//這種找到的中點,是second
        
        //有錯誤,剩下兩個節點的代入皆會變成 l1=s,l2=s; li=l2=s=head;
        // f=s=pre=&hdr;
        // hdr.next = head;
        
        while(f&&f->next){
            pre=s;
            s=s->next;
            f=f->next->next;
        }
        
        pre->next = NULL;
        ListNode *l1 = head;
        ListNode *l2 = s;
        return merge(sortList(l1),sortList(l2));
        // return merge(sortList(head),sortList(s));
    }

	ListNode* sortList_OK(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		// ListNode hdr(-1);
		ListNode *f, *s, *pre;
		f = s = pre = head;//這種找到的中點,是second

		//有錯誤,剩下兩個節點的代入皆會變成 l1=s,l2=s; li=l2=s=head;
		// f=s=pre=&hdr;
		// hdr.next = head;

		while (f&&f->next) {
			pre = s;
			s = s->next;
			f = f->next->next;
		}

		pre->next = NULL;
		ListNode *l1 = sortList(l1);
		ListNode *l2 = sortList(l2);
		return merge(sortList(l1), sortList(l2));
		// return merge(sortList(head),sortList(s));
	}




    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val<l2->val){
            l1->next = merge(l1->next,l2);
            return l1;
        }else{//l1->val >= l2->val
            l2->next = merge(l1,l2->next);
            return l2;
        }
    }
    
};