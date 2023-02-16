//===類似題===
207. Course Schedule
156. Binary Tree Upside Down
2074. Reverse Nodes in Even Length Groups
2487. Remove Nodes From Linked List
//===思路====

//====
ListNode* helper2(ListNode* head){
    //沒有節點,或只有一個節點    
    if(!head||!head->next) return head;
    ListNode *pre,*cur;
    pre = NULL;
    cur = head;
    while(cur){
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}
//=====
ListNode* helper1(ListNode* head){
        ListNode *pre,*cur;
        pre=NULL;
        cur=head;
        while(cur!=NULL){
            ListNode* tmp = cur->next;//紀錄cur->next, 因為會斷開原本的cur->next,去指向後前一個節點
            cur->next = pre;//指向前一個節點
            pre = cur;//前一個節點往後移
            cur = tmp;//cur 更新,待做下一次運算
        }
        return pre;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *cur,*pre;
        if(head==NULL||head->next==NULL) return head;
        
        cur = head;
        pre = NULL;
        while(cur!=NULL){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    
    
    ListNode* reverseList_ok(ListNode* head) {
        ListNode *cur,*pre;
        ListNode hdr(-1);
        
        if(head==NULL||head->next==NULL) return head;
        hdr.next = head;
        pre = &hdr;
        cur = head;
        
        
        while(cur!=NULL){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        head->next=NULL;
        return pre;
        
    }
    
     ListNode* reverseList_2(ListNode* head) {
        ListNode *prev,*cur,*tmp;
        
        if(!(head&&head->next)) return head;
        
        prev = NULL;
        cur = head;
        tmp = cur->next;
        
        while(cur){
            cur->next = prev;
            prev = cur;
            cur = tmp;
            tmp = tmp?tmp->next:NULL;
        }
        return prev;
        
    }
    
};
