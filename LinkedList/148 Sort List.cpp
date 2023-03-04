//===類似題===
149. Max Points on a Line
2046. Sort Linked List Already Sorted Using Absolute Values
//===思路===
(*) merge sort概念
1.利用快慢指標找到list中點
2.將右半部,和左半部分別再帶入spilt函式, 一直到分割最小狀態
3.split函式回傳左半邊,右半邊以排序的數列
4.最後入combine函式,做排列
//=====
ListNode* merge(ListNode* l, ListNode* r){//combine函式
    ListNode hdr(-1);
    ListNode* cur=&hdr;
    while(l||r){
        int vall = l?l->val:INT_MAX;
        int valr = r?r->val:INT_MAX;
        if(vall<valr){
            cur->next = l;
            cur=cur->next;
            l=l?l->next:NULL;
        }else{//vall>=valr
            cur->next = r;
            cur=cur->next;
            r = r?r->next:NULL;
        }
    }
    return hdr.next;
}
ListNode* split(ListNode* head){
    if(!head||!head->next) return head;   
    ListNode hdr(-1);
    ListNode *l,*r,*t;
    l=r=&hdr;
    hdr.next = head;
    while(r&&r->next){
        l=l->next;
        r=r->next->next;
    }
    t = l->next;
    l->next = NULL;
    ListNode* left = split(hdr.next);//left
    ListNode* right =split(t);//right
    return merge(left,right);
}

//=====
ListNode* combine(ListNode* l, ListNode* r){
    ListNode vnd(-1);
    ListNode* t = &vnd;
    while(l||r){
        if(!l){//l==NULL,只排列r
            t->next = r;
            t=t->next;
            r=r->next;
            continue;
        }
        if(!r){//r==NULL,只排列l
            t->next =l;
            t=t->next;
            l=l->next;
            continue;
        }
        if(l->val<=r->val){//l和r都存在, 對數值做比對
            t->next = l;
            t=t->next;
            l=l->next;
        }else{//l->val>r->val
            t->next=r;
            t=t->next;
            r=r->next;
        }
    }
    return vnd.next;
}

ListNode* sort(ListNode* head){
    if(!head||!head->next) return head;//如果"沒有節點"或"只有一個節點"
    ListNode vnd(-1);
    ListNode *f,*r,*left,*right;

    vnd.next = head;
    f=r=&vnd;
    while(r&&r->next){//找到list中點
        f=f->next;
        r=r->next->next;
    }
    
    //設定右半部,左半部list的邊界
    r=f->next;
    f->next = NULL;
    
    //將右半部,左半部分別再帶入split函式,繼續做分割
    left=sort(vnd.next);
    right=sort(r);
    
    //開始對split的list做排列
    return combine(left,right);
}

ListNode* sortList(ListNode* head) {
        return sort(head);    
}
//===思路


//=====
class Solution {
public:
ListNode* merge(ListNode* l1,ListNode* l2){
    if(!l1) return l2;
    if(!l2) return l1;
        
    if(l1->val<l2->val){
        l1->next = merge(l1->next,l2);
        return l1;
    }else{//l1->val >= l2->val
        l2->next = merge(l1,l2->next);
        return l2;
    }
}

	//跟merge sort做比較
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
        // ListNode hdr(-1);
        ListNode *f,*s,*pre;
        f=s=pre=head;//這種找到的中點,是second
        
        //有錯誤,剩下兩個節點的代入皆會變成 l1=s,l2=s; li=l2=s=head;
        // f=s=pre=&hdr;
        // hdr.next = head;
        
        while(f&&f->next){
            pre=s;
            s=s->next;
            f=f->next->next;
        }
        
        pre->next = NULL;
        ListNode *l1 = head;
        ListNode *l2 = s;
        return merge(sortList(l1),sortList(l2));
        // return merge(sortList(head),sortList(s));
    }

	ListNode* sortList_OK(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		// ListNode hdr(-1);
		ListNode *f, *s, *pre;
		f = s = pre = head;//這種找到的中點,是second

		//有錯誤,剩下兩個節點的代入皆會變成 l1=s,l2=s; li=l2=s=head;
		// f=s=pre=&hdr;
		// hdr.next = head;

		while (f&&f->next) {
			pre = s;
			s = s->next;
			f = f->next->next;
		}

		pre->next = NULL;
		ListNode *l1 = sortList(l1);
		ListNode *l2 = sortList(l2);
		return merge(sortList(l1), sortList(l2));
		// return merge(sortList(head),sortList(s));
	}   
};
