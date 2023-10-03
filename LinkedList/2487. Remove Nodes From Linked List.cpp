//===類似題===
426. Convert Binary Search Tree to Sorted Doubly Linked List
224. Basic Calculator
379. Design Phone Directory

//===思路===
(*) Stack 概念
1. stack一開始先push一個 大於Node.val最大值的節點 hdr(1000001)
2.開始用 stack概念, 當stk.top()->val <cur->val 
- 將stack.pop();
- 並將stack.top()->next 連接新的 node

3.依此步驟遍歷 list, 則可以得到滿足條件的list
ˋ回傳hdr.next;

ListNode* removeNodes(ListNode* head) {
    stack<ListNode*> stk;
    ListNode hdr(1000001);
    ListNode* cur;

    cur = head;
    stk.push(&hdr);
    while(cur){
//      while(!stk.empty() && stk.top()->val<cur->val)
        while(stk.top()->val < cur->val){
            stk.pop();        
        }
        stk.top()->next = cur;
        stk.push(cur);
        cur = cur->next;        
    }
    return hdr.next;
}
