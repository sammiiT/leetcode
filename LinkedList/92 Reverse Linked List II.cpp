//===類似題===
93. Restore IP Addresses
708. Insert into a Sorted Circular Linked List
1290. Convert Binary Number in a Linked List to Integer
1171. Remove Zero Sum Consecutive Nodes from Linked List
//===思路===
   p  c=left      right 
   |  |  t        | 
h->o->@->#->$->&->*->o->x

   p     c        right
   |  |  |  t     | 
h->o->#->@->$->&->*->o->x

   p        c     right 
   |  |     |  t  |               
h->o->$->#->@->&->*->o->x

   p           c  right
   |  |        |  |t 
h->o->&->$->#->@->*->o->x

   p              c
   |  |           | 
h->o->*->&->$->#->@->o->x
//====思路===
             left   right 
              V     V  
           f  r  t 
      hdr  1  2  3  4  5  6  x

 NO1       f  t  r  
===>  hdr  1  3  2  4  5  6  x
  
update     f     r  t  
===>  hdr  1  3  2  4  5  6  x
  
 NO2       f  t     r
===>  hdr  1  4  3  2  5  6  x

(*)先聯r,再連t,再連f

//====
ListNode* helper0(ListNode* head, int left, int right){
    ListNode *pre,*cur;
    ListNode hdr(-1);
    hdr.next = head;
    pre = &hdr;
    
    for(int i=0; i<left-1; i++) pre = pre->next;
    cur =pre->next;

    for(int i=0;i<(right-left);i++){
        ListNode* t = cur->next;
        cur->next = t->next;
//        t->next = cur;//此描述會出錯
        t->next = pre->next;//這一段要記得
        pre->next =t;
    }
    return hdr.next;
}

//===寫法1===
ListNode* helper0(ListNode* head, int left, int right) {
    if(!head || !head->next) return head; 
    ListNode hdr(-1);
    ListNode* pre;
    ListNode* f;

    hdr.next = head;
    pre = &hdr;
    f = head;
    
    right = right-left;//
    left = left-1;//position, find the previous position

    while(left){
        pre = pre->next;
        f = f->next;
        left-=1;
    }
    while(right){//move count; if 3 nodes, move 2 times; n nodes, move (n-1) times
        ListNode* tmp = f->next;
        f->next = tmp->next;
        tmp->next = pre->next;
        pre->next = tmp;
        right-=1;
    }
    return hdr.next;
}

//=====寫法2===
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre,*cur;
        ListNode hdr(-1);
        pre = &hdr;
        cur = head;
        hdr.next = head;
        for(int i=0; i<m-1; ++i){//cur為第m個的前一個
            cur = cur->next;
            pre = pre->next;
        }
        for(int i=m; i<n; ++i){
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return hdr.next;
    }
     
ListNode* create_list(int n){
    ListNode *tmp;
    ListNode vnode(-1);

    if(!n) return NULL;
    
    tmp = &vnode;
    
    for(int i=0; i<n; i++){
        tmp->next = new ListNode(rand()%23);
        tmp = tmp->next;
    }
    return vnode.next;
}

void free_list(ListNode* head){
    ListNode *cur,*tmp;
    if(head==NULL) return;
    
    cur = tmp=head;
    
    for(;tmp!=NULL;){
        cur = tmp;
        tmp = cur->next;
        delete cur;
    }
}

void print_list(ListNode* head){
    ListNode* vnode;
    if(head==NULL) {
        cout<<"printlist fail: invalid list head.";
    }
    
    vnode = head;
    while(vnode!=NULL){
        cout<<vnode->val<<" ";
        vnode = vnode->next;
    }
    cout<<endl;
}

ListNode* get_node(ListNode* head, int n){
    ListNode *tmp;
    ListNode vnode(-1);
    
    vnode.next = head;
    tmp = &vnode;
    
    for(int i=0; i<n; i++){
        tmp=tmp->next;
        if(tmp==NULL) return NULL;
    }
    return tmp;
}

ListNode* reverse_helper(ListNode *head, ListNode *end){
    ListNode *cur, *prev;
    cur = head;
    prev = NULL;
    
    for(;prev!=end;){
        ListNode* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}



ListNode* reverseBetween_2(ListNode* head, int left, int right){
    ListNode *prev,*cur;
    ListNode *p_start,*start,*end,*a_end;
    ListNode *rev;
    ListNode vnode(-1);
    
    vnode.next = head;
    p_start = prev = &vnode;
    cur = head;
    
//(1,2) = (left=1, right=2)   
    for(int i=0; i<right; i++){
        prev = prev->next;
        cur = cur->next;
        if(i<left-1){//p_start沒有初始化,left=1時會進不來
            p_start = prev;
        }
    }//prev就是right節點, cur就是right下一個節點
    start = p_start->next;
    end = prev;
    a_end = cur;
    
    rev = reverse_helper(start, end);
    p_start->next = rev;
    start->next = a_end;
    
    return vnode.next;
    
}

     
     
};
