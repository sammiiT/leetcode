//=== more challenge ===
2411. Smallest Subarrays With Maximum Bitwise OR

//=== 思路 ===
(*) 利用priority_queue紀錄每一個listNode
priority_queue<ListNode*,vector<ListNode*>,cmp>
cmp是比較每一個listNode的大小

(*)將priority_queue依序pop()出來,並重新鏈結


struct cmp{
    bool operator()(ListNode* a, ListNode* b ){
        //return ((*a)->val)>((*b)->val);
        return a->val > b->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,cmp> pq;

    for(int i=0;i<lists.size();++i){
        ListNode* cur = lists[i];
        while(cur!=NULL){
            pq.push(cur);
            cur = cur->next;
        }
    }

  ListNode* cur;
    ListNode hdr(-1);
    cur = &hdr;
    while(!pq.empty()){
        ListNode* n = pq.top();pq.pop();
        cur->next = n;
        cur = cur->next;
        cur->next = NULL;
    }
    return hdr.next;
}
