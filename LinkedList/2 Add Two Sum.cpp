class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);//會有dangling pointer
        ListNode *cur = dummy;
        int carry = 0;

        while(l1||l2){
                int val1 = (l1)?l1->val:0;
                int val2 = (l2)?l2->val:0;

                int sum = val1+val2+carry;
                carry = sum/10;

                cur->next = new ListNode(sum%10);
                cur = cur->next;

                if(l1) l1=l1->next;
                if(l2) l2=l2->next;
        }
        if(carry){
                cur->next = new ListNode(1);
                // cur->next->next = NULL;
        }
        return dummy->next; 
    }

	ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1);
		ListNode* cur = &dummy;
		int carry = 0;

		while(l1||l2){
			int val1 = (l1) ? l1->val : 0;
			int val2 = (l2) ? l2->val : 0;

			int sum = carry + val1 + val2;
			carry = sum / 10;
			cur->next = new ListNode(sum % 10);

			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		if (carry) cur->next = new ListNode(1);
		return dummy.next;
	}


};