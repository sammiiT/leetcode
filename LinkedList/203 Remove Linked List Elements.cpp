//===類似題===
204. Count Primes
369. Plus One Linked List
894. All Possible Full Binary Trees
705. Design HashSet
//===思路====

//=====
ListNode* removeElements(ListNode* head, int val) {
    ListNode hdr(-1);
    ListNode* cur;
    hdr.next = head;
    cur = &hdr;
    while(cur->next){//如果下一個節點存在, 則繼續
        if(cur->next->val==val)
            cur->next = cur->next->next;
        else cur=cur->next;
    }
    return hdr.next;
}

//===
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur=new ListNode(-1),*dummy;
        if(head==NULL) return head;
        
        cur->next = head;
        dummy = cur;
        
        // while(cur && cur->next){
        while(cur->next){
            if(cur->next->val==val){
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }else
               cur=cur->next;
        }
        
        return dummy->next;
    }
};
Input:  1->2->6->3->4->5->6, val = 6
Output : 1->2->3->4->5
