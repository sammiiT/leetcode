class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==NULL||head->next==NULL) return NULL;
    ListNode hdr(-1);
    ListNode *f,*s;
    f=s=&hdr;
    hdr.next=head;

    for(int i=0; i<n; ++i){
        f = f->next;
    }
    if(f->next==NULL) return head->next;

    while(f&&f->next){
        f=f->next;
        s=s->next;
    }
    ListNode *tmp = s->next;
    s->next = tmp->next;
    delete tmp;
    return hdr.next;
        
    }
    
    
    ListNode* removeNthFromEnd_3(ListNode* head, int n) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode hdr(-1);
        ListNode *cur,*prev;
        hdr.next=head;
        cur=prev=&hdr;
        for(int i=0;i<n;++i){
            cur = cur->next;
        }
        if(cur&&cur->next==NULL) return head->next;
        while(cur->next!=NULL){
            cur=cur->next;
            prev=prev->next;
        }
        prev->next=prev->next->next;
        return head;
        
    }
    
    ListNode *removeNthFromEnd_2(ListNode *head,int n){
        if(head==NULL||head->next==NULL) return NULL;
        ListNode *cur,*prev;
        
        cur=prev=head;
        
        for(int i=0; i<n; ++i){
            cur=cur->next;
        }
        if(cur==NULL) return head->next;//最後一個節點被remove
        
        while(cur->next!=NULL){
            cur=cur->next;
            prev=prev->next;
        }
        prev->next = prev->next->next;
        return head;
        
        
        
    }
    
};