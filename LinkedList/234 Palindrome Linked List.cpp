class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return true;
        ListNode *f,*s;
        f=s=head;
        
        
        // while(f&&(f->next)){//找cycle運算法, 差異??
        //     f=f->next->next;
        //     s=s->next;
        // }
        
        //(1)search the middle element
        while(f->next && f->next->next){//找中間值,差異??
            f=f->next->next;
            s=s->next;
        }//s為中間值
        
        //(2)reverse the second partition
        ListNode *mid=s,*pre=NULL;
        ListNode *last = mid->next;
        
        for(;last!=NULL;){
            ListNode* tmp = last->next;
            last->next=pre;
            pre=last;
            last=tmp;
        }//pre反轉的head
            
        // for(;head!=NULL && pre!=NULL;){
        for(;pre!=NULL;){
            if(head->val==pre->val){
                head=head->next;
                pre=pre->next;
            }else{
                return false;
            }
        }
        return true;
        
    }
};