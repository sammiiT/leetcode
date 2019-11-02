class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *a,*b;
        a=headA;
        b=headB;
        if(a==NULL || b==NULL) return NULL;
        
        while(a!=b){
            a=a?a->next:headB;
            b=b?b->next:headA;
        }
        
        return a;
    }
};