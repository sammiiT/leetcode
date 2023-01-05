/===類似題===
329. Longest Increasing Path in a Matrix
426. Convert Binary Search Tree to Sorted Doubly Linked List
706. Design HashMap
1171. Remove Zero Sum Consecutive Nodes from Linked List   
    
//===思路===
(*)第一種解法:
1.遍歷list, 每一次紀錄遍歷的index,如果index為奇數, 就加到奇數的新list; 同理,偶數inddex加到偶數list
2.將奇數,偶數list做合併    

(*)第二種解法:
1.用reserve linked list II的解法
2.每一次執行完要多加一次pre->next和cur->next

p  c
|  |
1->2->3->4->5->x

p     c                  p     c
|     |                  |     |
1->3->2->4->5->x  =>  1->3->2->4->5->x  多update一次pre和cur, 因為才能到下一個  奇數,偶數位置

   p        c
   |        |  
1->3->5->2->4->x       
       
//====    
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
     
ListNode* oddEvenList(ListNode* head) {
        ListNode *prev,*cur;
        ListNode vnode(-1);
        
        if(!(head&&head->next)) return head;
        
        vnode.next = head;
        prev = head;
        cur = head->next;

        while(cur&&cur->next){//pre,cur,tmp
    //  while(cur){//會運算NULL pointer,錯誤
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = prev->next;
            prev->next = tmp;

            prev = prev->next;
            cur = cur->next;
        }
        return vnode.next;
}     
     
};
//====================================================
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

Input: 1->2->3->4->5->NULL
Output : 1->3->5->2->4->NULL

Input : 2->1->3->5->6->4->7->NULL
Output : 2->3->6->7->1->5->4->NULL
