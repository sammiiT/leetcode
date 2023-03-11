//===類似題===
446. Arithmetic Slices II - Subsequence
1634. Add Two Polynomials Represented as Linked Lists
//===思路====
(*)從後面開始算, 所以需要兩個stack
(*)每次pop出的數值做相加,同時計算進位 
(*)直到兩個stack為empty()
(*)最後再判斷是否有進位, 如果有進位再加一個node.
//=========
    ListNode* helper0(ListNode* l1, ListNode* l2) {
        stack<int> stk1;
        stack<int> stk2;
        ListNode *h1,*h2;
        int carry = 0;
        ListNode hdr(-1);
        ListNode* cur=&hdr;
        h1 = l1;
        h2 = l2;

        while(h1){
            stk1.push(h1->val);
            h1 = h1->next;
        }
        while(h2){
            stk2.push(h2->val);
            h2 = h2->next;
        }

        while(!stk1.empty()||!stk2.empty()){
            int val1 = 0; 
            int val2 = 0;
            int sum = 0;
            if(!stk1.empty()){
                val1 = stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()){
                val2 = stk2.top();
                stk2.pop();
            }            
            sum = carry + val1+val2;
            carry = sum/10;
            ListNode *t = new ListNode(sum%10);
            t->next = cur->next;
            cur->next = t;
        }
        if(carry) {
            ListNode* t = new ListNode(1);
            t->next = cur->next;
            cur->next = t;
        }
        return hdr.next;
    }

//======
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     stack<int> s1;
     stack<int> s2;

     while(l1){
         s1.push(l1->val);
         l1=l1->next;
     }

     while(l2){
         s2.push(l2->val);
         l2=l2->next;
     }

     int sum = 0;
     int carry = 0;
     ListNode *head = NULL;

     while(!s1.empty()||!s2.empty()){
         if(!s1.empty()){
             sum = sum + s1.top();
             s1.pop();
         }
         if(!s2.empty()){
             sum=sum+s2.top();
             s2.pop();
         }
         sum = sum+carry;
         if(head){
             ListNode* tmp = new ListNode(sum%10);
             tmp->next = head;
             head = tmp;
         }else{//head==NULL
             head =new ListNode(sum%10);
         }
         carry = sum/10;
         sum = 0;
     }
        
     if(carry) {
         ListNode *tmp = new ListNode(1);
         tmp->next = head;
         head = tmp;
     }
        return head;
  
    }
    ListNode* addTwoNumbers_OK(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        int sum = 0;
        ListNode *res = new ListNode(0);
        
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        
        while(!s1.empty()||!s2.empty()){
            if(!s1.empty()){
                sum = sum + s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum = sum +s2.top();
                s2.pop();
            }
            
            res->val = sum%10;
            ListNode* head = new ListNode(sum/10);
            head->next = res;
            res = head;
            sum = sum/10;
        }
        return res->val==0 ? res->next:res; 
    }
    
ListNode* reverse_helper(ListNode* head){
        ListNode *prev,*cur;
        prev = NULL;
        cur = head;
        for(;cur!=NULL;){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
}
ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2) {
        ListNode *l_1,*l_2,*ret;
        ListNode vnode(-1);
        ListNode *cur;
        int carry = 0;
        int sum = 0;
        l_1 =reverse_helper(l1);
        l_2 = reverse_helper(l2);
        cur = &vnode;
        while(l_1||l_2){
            int val1=l_1?l_1->val:0;
            int val2=l_2?l_2->val:0;
            
            sum = val1 + val2 + carry;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum/10;
            
            if(l_1) l_1 = l_1->next;
            if(l_2) l_2 = l_2->next;
        }
        if(carry){
            cur->next = new ListNode(carry);
        }
        ret = reverse_helper(vnode.next);
        return ret;
}   
    
};

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output : 7 -> 8 -> 0 -> 7
