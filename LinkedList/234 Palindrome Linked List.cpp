//=====類似題======
235. Lowest Common Ancestor of a Binary Search Tree
2130. Maximum Twin Sum of a Linked List

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		//(*)需要找到first middle, 用first middle找到第二部分的start node 
		//(*)從head開始, 則會找到second middle
        if(head==NULL || head->next==NULL) return true;
        ListNode *f,*s;
        f=s=head;
        
        //(*)需要找到first middle, 用first middle找到第二部分的start node
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


	bool isPalindrome_(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;
		ListNode hdr(-1);//直接定位first middle
		ListNode *f, *s, *pre;

//定位到 first middle(偶數個)/middle(奇數個),需要多一個hdr節點串到頭
		hdr.next = head;
		s = f = &hdr;
		while (f && f->next) {
			s = s->next;
			f = f->next->next;
		}

/*
	直接定位到first middle(偶數個)/middle(奇數個)
	f=s=head;
	while(f->next && f->next->next){
		f = f->next->next;
		s = s->next;
	}
*/

		//設定第二個partition的頭
		f = s->next;
		s->next = NULL;
		pre = NULL;
		while (f) {
			ListNode *tmp = f->next;
			f->next = pre;
			pre = f;
			f = tmp;
		}

		while (pre) {
			if (head->val == pre->val) {
				head = head->next;
				pre = pre->next;
			}
			else {
				return false;
			}
		}
		return true;
	}
};
//===============================================================
    bool helper0(ListNode* head){
        stack<struct ListNode*> stk;
        ListNode hdr(-1);
        ListNode *f,*r;
        f=r=&hdr;
        hdr.next = head;
        while(r&&r->next){
            f=f->next;
            r=r->next->next;
        }
        ListNode* tmp = f->next;
        while(tmp){
            stk.push(tmp);
            tmp=tmp->next;
        }
        f = hdr.next;
        while(!stk.empty()){//將後半部放入stack就不用考慮前半部的last node
            ListNode* t = stk.top();
            if(t->val!=f->val) return false;
            stk.pop();
            f=f->next;
        }
        return true;
    }

