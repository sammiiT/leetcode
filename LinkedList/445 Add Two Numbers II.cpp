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
