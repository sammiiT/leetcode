//===類似題===
142. Linked List Cycle II
251. Flatten 2D Vector
1813. Sentence Similarity III
2488. Count Subarrays With Median K
//===思路===

//====
bool hasCycle(ListNode *head) {
    bool cycle=false;
    ListNode *s1, *s2;
    s1=s2=head;
    while(s2&&s2->next){
        s1=s1->next;
        s2=s2->next->next;
        if(s1==s2){
            cycle=1;
            break;
        }
    }
    return cycle;
}

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
