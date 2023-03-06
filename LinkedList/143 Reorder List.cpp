//===類似題===
144. Binary Tree Preorder Traversal
2516. Take K of Each Character From Left and Right
//===思路====
(*)利用stack紀錄後半段
1.
   left  |  right
 a  b  c | d  e  g

2.
 f  r
 a  b  c  x

+---+---+---+- 
| d | e | g | <---push
+---+---+---+- 

3.	
+---+---+---+- 
| d | e |  --> pop "g"
+---+---+---+- 
	
f     r                   f  r
a->g->b->c->x   =>  a->g->b->c->x 	
	
4.
+---+---+---+- 
| d |      --> pop "e"
+---+---+---+- 

      f     r                      f  r 
a->g->b->e->c->x  =>   a->g->b->e->c->x
	
5.
+---+---+---+- 
|          --> pop "d"
+---+---+---+- 

	    f  r                          f (r不存在)
a->g->b->e->c->x  =>	a->g->b->e->c->e->x	
	
//=====
void reorderList(ListNode* head) {
    stack<ListNode*> stk;
    ListNode hdr(-1);
    ListNode *f,*r;
    hdr.next=head;
    f=r=&hdr;

    while(r&&r->next){
        f=f->next;
        r=r->next->next;
    }//f = first_middle
    
    ListNode *t = f->next;//右半邊
    f->next=NULL;//左半邊截斷
    while(t){//右半邊放入stack
        stk.push(t);
        t=t->next;
    }
    
    f = head;
    r = f->next;
    while(!stk.empty()){
        ListNode* p = stk.top();
        stk.pop();
        f->next = p;
        p->next = r;
        f=r;
        r=f?f->next:NULL;
    }
}

//=====
class Solution {
public:
    void reorderList(ListNode* head){
       if(head==NULL||head->next==NULL) return;

    ListNode hdr(-1);
    ListNode *f,*s;
    f=s=&hdr;
    hdr.next=head;//用first middle,不用second middle
				  //比較 sortedListToBST題目, 用到的是second middle
    while(f&&f->next){
        f=f->next->next;
        s=s->next;
    }

    ListNode *cur,*pre;
    pre = NULL;
    cur = s->next;
    while(cur!=NULL){
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
    }
    s->next = NULL;

    cur = hdr.next;
    while(cur&&pre){
        ListNode* tmp = pre->next;
        pre->next=cur->next;
        cur->next = pre;
        cur=pre->next;
        pre=tmp;
    }
    }
    
    void reorderList_OK(ListNode* head) {
        if(head==NULL||head->next==NULL) return;
        ListNode hdr(-1);
        ListNode *f,*s;
        hdr.next = head;
        f = s = &hdr;
        
        while(f && f->next){
            f = f->next->next;
            s = s->next;
        }
        ListNode *prev,*cur,*last;
        
        last = prev = s;
        cur = s->next;
        
        while(cur!=NULL){
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur=tmp;
        }
        last->next = NULL;
        
        cur = head;
        while(cur && prev){
            ListNode *next = cur->next;
            cur->next = prev;
            prev = prev->next;
            cur->next->next = next;
            cur = next;
        }
        
    }
	 

void reorderList(ListNode* head) {
        ListNode *prev,*cur;
        ListNode *tmp=NULL, *top=NULL;
        ListNode vnode(-1),ln(-1);
        ListNode *l1tmp,*l2tmp;
        
        vnode.next = head;
        prev = cur = &vnode;
        
        while(cur&&cur->next){//find the first-middle
            prev = prev->next;
            cur = cur->next->next;
        }
        
        //define list boundary
        tmp = prev->next;//l2 start
        prev->next = NULL;//reset l1 end;
        
        //stacking list2 for question request.
        while(tmp){
            ListNode* stacking = tmp;
            tmp = tmp->next;
            stacking->next = top;
            top = stacking;
        }
        
        //zig-zag concatenance
        tmp = &ln;
        l1tmp = vnode.next;
        l2tmp = top;
        while(l1tmp||l2tmp){
            if(l1tmp){
                tmp->next = l1tmp;
                l1tmp = l1tmp->next;
                tmp = tmp->next;
            }
            if(l2tmp){
                tmp->next = l2tmp;
                l2tmp = l2tmp->next;
                tmp = tmp->next;
            }
        }
        head = ln.next;
}	    	 
	 
};

Given 1->2->3->4, reorder it to 1->4->2->3.
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
