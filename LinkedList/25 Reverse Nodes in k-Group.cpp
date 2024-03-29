//===類似題===
2074. Reverse Nodes in Even Length Groups
//===思路====
(*) 
reverse k, 所以執行次數 (k-1)

      +--------------------------+
      |                          |
      |		_________        |
      |		|         \      |
      |		|          |     /
pre   |		|  cur	  tmp   /
hdr --+		+-> O	   O<--+   O	O	X
           	     \	  	   ^ 
            	      \____________|


//===寫法1===
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode hdr(-1);
        ListNode* pre;
        ListNode* cur;
        int total = 0;
        int cnt = 0;

        hdr.next = head;
        pre = &hdr;
        cur = head;

        while(cur){
            total+=1;
            cur=cur->next;
        }
        if(total<k) return head;

        cnt = total;
        cur = head;
        while(cnt>=k){
            for(int i=0;i<(k-1);++i) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = cur;
            cur = pre->next;
            cnt-=k;
        }
        return hdr.next;
    }
//===寫法2===
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {//swap k node, not reverse list
	if (head==NULL||head->next==NULL) return head;
		
	ListNode *pre,*cur;
        ListNode hdr(-1);
        int n = 0;
        for(ListNode *t = head;t; t=t->next) ++n;//計算node數
        
        pre = &hdr;
        cur = head;
        pre->next = cur;
        
        int count = n;
        
        //while(count>k){}會出錯, 當count = k時,會出錯
        while(count>=k){
            for(int i=1;i<k;++i){
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            count-=k;
            pre = cur;
            cur =cur->next;
        }
        return hdr.next;
    }
};


ListNode* reverseKGroup(ListNode* head, int k){
    
    ListNode *tmp,*prev,*cur;
    ListNode vnode(-1);
    int i,j;
    
    vnode.next = head;
    prev = tmp = &vnode;
    cur = head;
    
    for(;cur!=NULL;) {
    
        for(i=k; i>0; i--){//是否可以滿足 k-group
            tmp = tmp?tmp->next:NULL;
            if(!tmp) break;
        }
        
        if(i==0) {//如果滿足 k-group, 則開始做轉換
            for(j=0; j<k-1; j++) { 
                ListNode *t= cur->next;
                cur->next = t->next;
                t->next = prev->next;
                prev->next = t;
            }
        } else {//不滿足k-group,則跳出第一級迴圈
          break;  
        }
        
        // 跳到新的group 
        prev = tmp =cur; //prev = cur;此描述會出錯, 因為前面tmp已經被轉移到其他地方, 不會按照前面計算,tmp還在原來地方.
        cur = cur->next;
    }
    return vnode.next;
}



