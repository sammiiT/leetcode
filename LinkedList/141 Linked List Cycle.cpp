class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return false;
        ListNode *f,*s;
        f=s=head;
        
         while(f&&f->next){
             s=s->next;
             f=f->next->next;
             if(f==s) return true;//當f==s的時候,不見得是cycle begin.
         }
         return false;
    }
};
