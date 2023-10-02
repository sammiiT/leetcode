//===類似題===
1634. Add Two Polynomials Represented as Linked Lists
2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
706. Design HashMap
//===寫法1===

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode hdr(-1);
        ListNode* pre;
        ListNode* pre2;
        hdr.next = list1;
        
        pre = &hdr;
        for(int i=0; i<a; ++i) pre = pre->next;//找到要連接list2的header 的起始點
        
        pre2 = pre;
        for(int i=0; i<(b-a+1); ++i) pre2 = pre2->next;//找到要連接list2的tail 的末端點

        pre->next = list2;//list1連結 list2的header
        while(pre && pre->next) pre = pre->next;//找到list2的tail
        pre->next = pre2->next;//list1連結list2的tail
        
        return hdr.next;
}

//===寫法2===
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *n1,*n2,*tmp;
        ListNode vnode(-1);
        
        vnode.next = list1;
        tmp = &vnode;
        
        //find (a-1) node (b-1) node
        for(int i=0;i<b;i++){
            tmp = tmp->next;
            if(i==a-1){
                n1 = tmp;   
            }
/*            if(i==b-1){
                n2 = tmp;
            }*/
        }//i=b
        n2 = tmp->next;
        
        /*find end node of list2*/
        tmp = list2;
        for(;tmp&&tmp->next;){
            tmp = tmp->next;
        }
        
        n1->next = list2;
        tmp->next = n2->next;
        
        return vnode.next;         
    }
