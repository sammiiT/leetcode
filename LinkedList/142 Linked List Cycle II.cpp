//====類似題====
143. Reorder List
432. All O`one Data Structure
1442. Count Triplets That Can Form Two Arrays of Equal XOR
1124. Longest Well-Performing Interval

//===思路====
(*)先判斷list有沒有cycle
(*)有cycle之後,判斷交點
1. 用快慢指標來判斷; 快指標,一次走二步;慢指標,一次走一步
2. 如果有cycle, 則快指標==慢指標 代表有cycle; 此時f==r並不是交點
3.一個指標重新指向head, 和另外一個指標一次走一步, 最後相等的才是交點

//====
ListNode* helper(ListNode* head){
    ListNode *f,*r;
    int intersection =0;
    f=r=head;
    while(r&&r->next){
        f=f->next;
        r=r->next->next;
        if(f==r){
            intersection = 1;
            break;
        }
    }
        
    f=head;
    if(intersection){
        while(f!=r){
            f=f->next;
            r=r->next;
        }
    }
    return intersection?f:NULL;        
}
ListNode *detectCycle(ListNode *head) {
        return helper(head);
}

//========
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
