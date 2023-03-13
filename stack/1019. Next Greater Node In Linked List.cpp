//===類似題===
1020. Number of Enclaves
2506. Count Pairs Of Similar Strings
2328. Number of Increasing Paths in a Grid
963. Minimum Area Rectangle II
//===思路====
(*)將linked list轉換為array來計算
要回朔, 用stack紀錄每一個節點ndex, 每一個top()所指向的位置, 都是local maximum的位置
array_size會比stk.top()多"1"

(*)
建立一個vector<int> nums;紀錄遍歷的每一個節點
---此陣列是用來轉換linked_list

建立一個stack<int> stk; 紀錄每一個陣列中的index, 且可以回朔陣列之前的值
--比較"當下的節點的值"head->val  與 "之前的值"  nums[stk.top()]

建立一個變數cnt,可更改過程中的"解"array, 


(*)
vector.resize()==> 將陣列size()更改.多的element會自動填"0"
//=====

vector<int> nextLargerNodes(ListNode* head) {
  vector<int> res, nums;
  stack<int> stk;
  int cnt = 0;
  
  while(head){
      nums.push_back(head->val);
      while(!stk.empty() && head->val > nums[stk.top()]){//
        res[stk.top()] = head->val;
        stk.pop();
      }
      stk.push(cnt);
      res.resize(++cnt);
      head = head->next;
  }
  return res;
}
