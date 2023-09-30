//===類似題===
1768. Merge Strings Alternately
1474. Delete N Nodes After M Nodes of a Linked List
253. Meeting Rooms II

//===思路===
(*)first middle 和 second middle 問題
- 此題為second middle 問題
//====
ListNode* deleteMiddle(ListNode* head) {
        if(!head||!head->next) return NULL;//只有一個節點, 回傳NULL

        ListNode* f;
        ListNode* r;
        ListNode* pre;
        f=r=pre=head;
        
        while(r&&r->next){//計算second middle節點
            pre = f;
            f=f->next;
            r=r->next->next;
        } 
        pre->next = f->next; //跳開second middle節點 做連結
        return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *prev,*cur,*tmp;
        ListNode vnode1(-1);
        ListNode vnode2(-1);

        if(!(head&&head->next)) return NULL;
    
        vnode1.next = head;
        vnode2.next = &vnode1;//for previous
    
        prev = cur = &vnode1;
        tmp = &vnode2;//tmp是middle的前一個節點
    
//找出中間(middle)節點    
        while(cur&&cur->next){
            cur=cur->next->next;
            prev = prev->next;
            tmp = tmp->next;
        }
        if(cur){
            cur = cur->next;
            prev = prev->next;
            tmp = tmp->next;
        }
//----移除中間節點    
        tmp->next = prev->next;
        delete prev;
        return vnode1.next;    
    }
};
