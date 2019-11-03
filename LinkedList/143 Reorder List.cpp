class Solution {
public:
    void reorderList(ListNode* head){
       if(head==NULL||head->next==NULL) return;

    ListNode hdr(-1);
    ListNode *f,*s;
    f=s=&hdr;
    hdr.next=head;

    while(f&&f->next){
        f=f->next->next;
        s=s->next;
    }

    ListNode *cur,*pre;
    pre = NULL;
    cur = s->next;
    while(cur!=NULL){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
    }
    s->next = NULL;

    cur = hdr.next;
    while(cur&&pre){
        ListNode* tmp = pre->next;
        pre->next=cur->next;
        cur->next = pre;
        cur=pre->next;
        pre=tmp;
    }

    }
    
    void reorderList_OK(ListNode* head) {
        if(head==NULL||head->next==NULL) return;
        ListNode hdr(-1);
        ListNode *f,*s;
        hdr.next = head;
        f = s = &hdr;
        
        while(f && f->next){
            f = f->next->next;
            s = s->next;
        }
        ListNode *prev,*cur,*last;
        
        last = prev = s;
        cur = s->next;
        
        while(cur!=NULL){
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur=tmp;
        }
        last->next = NULL;
        
        cur = head;
        while(cur && prev){
            ListNode *next = cur->next;
            cur->next = prev;
            prev = prev->next;
            cur->next->next = next;
            cur = next;
        }
        
    }
};