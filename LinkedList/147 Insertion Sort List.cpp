class Solution {
public:
    ListNode *insertionSortList(ListNode* head){
        ListNode *dummy = new ListNode(-1);
         ListNode *cur ;//= dummy;

        for(;head!=NULL;){
            cur = dummy;//一定要設定一個新的hdr作為基準點, 因為用原來的head,在插入時會比較難處理
            while(cur->next && cur->next->val <= head->val){
                cur=cur->next;
            }
            ListNode *tmp = head->next;//head 要被insert至cu6所屬的list
            head->next=cur->next;//插入head,head的下一個節點要至像cur下一個節點
            cur->next=head;		//cur->next指向要插入的節點head
            head = tmp;			//設定新的head
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