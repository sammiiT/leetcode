//===類似題===
2488. Count Subarrays With Median K
739. Daily Temperatures
706. Design HashMap
1474. Delete N Nodes After M Nodes of a Linked List

//===思路====
(*)利用stack, 要找出最大的數值,最大數值的右方都必須為遞減;如下圖
          
 +--+                                            +--+    
 |  |  +--+                                      |  |---+
 |  |--+  |       => B比需POP(),因為C比較大  =>   |  |   |
 |A | B| C|--+                                   |A | C |---+
 |  |  |  |D |                                   |  |   | D |
-+--+--+--+--+--                               --+--+---+---+---
1.當(stack.top()<nums[i]); 則將stack.top()做pop(),直到stack.top()>=nums[i]
2.最後將每一個元素 pop出來, 並將pop與top做連接
stack.top()->next = val;//val是前一個top
此動作是將listnode做連接

3.最後回傳stk.top

//======
ListNode* helper0(ListNode* head){
    stack<ListNode*> stk;
    ListNode* cur;
    if(!head) return head;
    
    cur = head;
    
    while(cur){
        while(!stk.empty() && stk.top()->val < cur->val){
            stk.pop();
        }
        stk.push(cur);
        cur=cur->next;
    }
    stk.top()->next = NULL;
    while(stk.size()>1){
        cur = stk.top();
        stk.pop();
        stk.top()->next = cur;
    }
    return stk.top();
}

//===思路2==== check again
(*)思路同上,只是將NodeList連接的動作在"比較過程中"執行
(*)用vector<ListNode*>來模擬 stack行為, 才可以在return的時候回傳第0個數值


ListNode* helper1(ListNode* head){
    vector<ListNode*> stk;
    ListNode* cur;
    if(!head) return head;
    
    cur = head;
    
    while(cur){
        ListNode* tmp;
        while(!stk.empty() && (stk.back()->val < cur->val)){
            stk.pop_back();
        }
        if(!stk.empty()) stk.back()->next = cur;//將新list中的最後一個與當下判斷後的節點做連結
        stk.push_back(cur);
        cur=cur->next;
/*        if(!stk.empty()) {
            tmp = stk.back();
            tmp->next = cur;
        }
        stk.push_back(cur);
        stk.back()->next = NULL;
        cur=cur->next;*/
    }
    stk.back()->next = NULL;//最後一個節點的next要設定為NULL
    return stk[0];
}
