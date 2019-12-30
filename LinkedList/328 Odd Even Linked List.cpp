class Solution {
public:
//    O(1) space:不能malloc, new
//奇數node 偶數node 分開  
    ListNode* oddEvenList_OK(ListNode* head) {
        ListNode *g;
        ListNode *o;
        ListNode hdrg(-1);
        ListNode hdro(-1);
        ListNode* cur = head;
        int idx=0;
        g=&hdrg;
        o=&hdro;
        
        while(cur!=NULL){
            idx = (idx+1)%2;
            if(idx){//g
                g->next = cur;
                g=g->next;
            }else{//o
                o->next=cur;
                o=o->next;
            }
            cur=cur->next;
        }
        g->next = hdro.next;
        o->next =NULL;
        return hdrg.next;
    }
    
//往前長,往後長    
    ListNode* oddEvenList_OK2(ListNode* head) {
               if(!head||!head->next) return head;
        
        ListNode *cur,*pre;
        cur = head->next;
        pre = head;
        
        while(cur && cur->next){
            ListNode* tmp = pre->next;
            pre->next = cur->next;
            cur->next =cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }
        
        return head;
    }
    
    ListNode* oddEvenList(ListNode* head){
        if(head==NULL||head->next==NULL) return head;
        ListNode *g,*o,*cur,*hdrg,*hdro;
        
        hdrg = g = head;
        hdro= o = head->next;
        cur = o->next;
        int idx = 0;
        
        while(cur!=NULL){
            idx=(idx+1)%2;
            
            if(idx%2){
                g->next = cur;
                g=g->next;
            }else{
                o->next = cur;
                o=o->next;
            }
            cur = cur->next;
        }
        g->next = hdro;
        o->next = NULL;
        return hdrg;
    }
    
};

Input: 1->2->3->4->5->NULL
Output : 1->3->5->2->4->NULL

Input : 2->1->3->5->6->4->7->NULL
Output : 2->3->6->7->1->5->4->NULL