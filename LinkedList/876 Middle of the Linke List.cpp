class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *f,*s;
        f=s=head;//最後指向 second middle
        
        while(f&&f->next)//至少有兩個節點
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    
    ListNode* middleNode_OK2(ListNode* head) {
        
        if(head==NULL||head->next==NULL) return head;
        ListNode hdr(-1);
        ListNode* f,*s;
        f=s=&hdr;
        hdr.next = head;
        
        while(f&&f->next){
            f=f->next->next;
            s=s->next;
        }
        
        if(f){
            return s->next;
        }else{
            return s;
        }
        
        
    }
    
    
    
    ListNode* middleNode_OK(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
        ListNode *f,*s;
        f=s=head;
        
        while(f->next && f->next->next){
            f=f->next->next;
            s=s->next;
        }
        
        if(f->next!=NULL){
            return s->next;
        }else{//f->next==NULL
            return s;
        }
    }
};