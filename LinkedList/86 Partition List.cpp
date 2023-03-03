//===類似題===
87. Scramble String
2161. Partition Array According to Given Pivot
//===思路====

//===
ListNode* helper1(ListNode* head, int x) {
    ListNode *l,*r,*cur;
    ListNode hdl(-1),hdr(-1);
    l = &hdl;
    r = &hdr;
    cur = head;
    while(cur){
        if(cur->val<x){
            l->next = cur;
            l = l->next;
        }else{
            r->next = cur;
            r = r->next;
        }
        cur=cur->next;
    }
    l->next = hdr.next;
    r->next = NULL;
    return hdl.next;
}
//===
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode hdr1(-1);
        ListNode hdr2(-1);
        
        ListNode *prev1 = &hdr1;
        ListNode* prev2 = &hdr2;
        ListNode* cur = head;
        
        while(cur!=NULL){
            if(cur->val<x){
                prev1->next = cur;
                prev1=prev1->next;
            }else{//cur->val>=x
                prev2->next=cur;
                prev2=prev2->next;
            }
            cur=cur->next;
        }
        prev1->next = hdr2.next;
        prev2->next=NULL;
        
        return hdr1.next;
    }
    
    ListNode* partition_OK(ListNode* head, int x) {
        if(head==NULL||head->next==NULL) return head;
        ListNode hdr1(-1);//less
        ListNode hdr2(-1);//greater
        
        ListNode *cur,*prev1,*prev2;
        
        hdr1.next = head;
        prev1 = &hdr1;
        prev2 = &hdr2;
        cur = head;
        
        while(cur!=NULL){
            if(cur->val < x){
                prev1 = cur;
                cur= cur->next;
            }else{//cur->val >= x
                prev1->next = cur->next;
                prev2->next = cur;
                prev2->next->next = NULL;
                prev2=prev2->next;
                cur=prev1->next;
            }            
        }
        
        prev1->next = hdr2.next;
        // if(prev1->next == NULL){
        //     prev1->next = hdr2.next;
        // }
//         else if(prev1->next->next==NULL){
//             ListNode *tmp = prev1->next;
//             tmp->next = hdr2.next;
//         }
        
        return hdr1.next;
        
    }
};

Input: head = 1->4->3->2->5->2, x = 3
Output : 1->2->2->4->3->5
