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
};

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output : 7 -> 8 -> 0 -> 7