class Solution {
public:
	//kind of merge sort algorithm
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        
        while(l1||l2){
            int val1 = (l1)?l1->val:INT_MAX;
            int val2 = (l2)?l2->val:INT_MAX;
            int input;
            if(val1<val2){
                input=val1;
                if(l1) l1=l1->next;
            }else{//val1>=val2
                input=val2;
                if(l2) l2=l2->next;
            }
            cur->next = new ListNode(input);
            cur=cur->next;
        }
        return dummy->next;
    }

    ListNode* mergeTwoLists_2(ListNode* list1, ListNode* list2) {//算法如同add_two_sum
        ListNode *cur = NULL;
        ListNode hdr(-1);
        cur = &hdr; //如果用當下新建的節點, 則沒辦法知道上一個節點
                    //所以新建節點必須用cur->next來指派
        while(list1||list2){
            int val1 = list1? list1->val : INT_MAX;
            int val2 = list2? list2->val : INT_MAX;
            //int merge = 0;
                
            if(val1 <= val2){
                cur->next = new ListNode(val1);
            //    cur = cur->next;
                list1 = list1 ? list1->next:NULL;    
            } else if(val1 > val2){
                cur->next = new ListNode(val2);
             //   cur = cur->next;
                list2 = list2 ? list2->next: NULL;
            } 
            cur = cur->next;
        }
        return hdr.next;
    }	
	

ListNode* mergeTwoLists_3(ListNode* list1, ListNode* list2) {//不新建new
        ListNode *cur= NULL;
        ListNode hdr(-1);
        cur = &hdr;
        
        while(list1||list2){
            int val1 = list1? list1->val : INT_MAX;
            int val2 = list2? list2->val : INT_MAX;
            
            if(val1<=val2){
                cur->next = list1;
                cur=cur->next;
                list1 = list1?list1->next:NULL;
            }else if(val1>val2){
                cur->next = list2;
                cur=cur->next;
                list2 = list2?list2->next:NULL;
            }            
        }
        return hdr.next;
}	
	
	
};
