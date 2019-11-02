class Solution {
public:
    ListNode *insertionSortList(ListNode* head){
        ListNode *dummy = new ListNode(-1);
         ListNode *cur ;//= dummy;

        for(;head!=NULL;){
            cur = dummy;
            while(cur->next && cur->next->val <= head->val){
                cur=cur->next;
            }
            ListNode *tmp = head->next;
            head->next=cur->next;
            cur->next=head;
            head = tmp;
        }
        return dummy->next;
   
    }
    
    ListNode* insertionSortList_OK(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        if(head==NULL||head->next==NULL) return head;
        ListNode *cur;
        
        
        while(head){
            ListNode* tmp=head->next;
            cur = dummy;
            while((cur->next) && (cur->next->val<=head->val))
                cur=cur->next;
            
            
            head->next = cur->next;
            cur->next =  head;
            head = tmp;
        }
        return dummy->next;
        
        
    }
};