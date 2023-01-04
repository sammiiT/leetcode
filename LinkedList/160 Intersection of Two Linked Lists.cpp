//===類似題===
161. One Edit Distance
599. Minimum Index Sum of Two Lists
//===思路===
(*)當作封閉list跑兩輪, 第一輪若沒有相等, 則第二輪從另外一個head開始
(*)在兩輪之內一定可以找到答案, 不可能跑第三輪
//====
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a,*b;
    a= headA;
    b= headB;
    
    while(a!=b){//最後一定相等, 兩者等於NULL或 兩者在同一節點上
        if(!a) {
            a = headB;  //不會超過第二輪, 第三輪之後, a會永遠從head開始  
        }else{
            a = a->next;    
        }
        if(!b){
            b = headA; //不會超過第二輪 , 第三輪之後, b會永遠從head開始
        }else{
            b = b->next;    
        }
    }
    return a;
}


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *a,*b;
        a=headA;
        b=headB;
        if(a==NULL || b==NULL) return NULL;
        
        while(a!=b){
            a=a?a->next:headB;
            b=b?b->next:headA;
        }
        
        return a;
    }
};
