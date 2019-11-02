class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     
        if(head==NULL || head->next==NULL) return NULL;
        int cycle=0;
        ListNode *ret = NULL;
        ListNode *f,*s;
        f=s=head;
        
        while(f && f->next){
            f=f->next->next;
            s=s->next;
            if(f==s) { 
                cycle = 1;
                break;
            }    
        }
        
        s = head;
        if(cycle){
            while(f!=s){
                f=f->next;
                s=s->next;
            }
            ret = s;
        }
        
        return ret;
    }
};