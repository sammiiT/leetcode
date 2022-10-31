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
