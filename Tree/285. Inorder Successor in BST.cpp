//===類似題===
(*)求解inoder遍歷的時 target節點的下一節點
173. Binary Search Tree Iterator.cpp

//===思路 ref 173=====
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* cur = root;
    stack<TreeNode*> stk;//stk紀錄left 路徑上的所有節點
    while(cur){
        stk.push(cur);
        cur = cur->next;
    }
    cur = NULL;
    while(!stk.empty()){
        cur = stk.top();stk.pop();
        if(cur==p) break;
        if(cur->right){//判斷是否有right節點
            TreeNode* r = cur->right;
            while(r){//將right路徑上的 left節點都記錄在stack中
                stk.push(r);
                r=r->left;
            }
        }
    }
    if(cur){
        if(cur->right){//要先判斷是否有right節點(不能先判斷stk.empty); 先判斷right路徑是inorder的定義; 
            TreeNode* r = cur->right;
            while(r->left){ r = r->left; }
            return r;
        }
        if(!stk.empty()) return stk.top();//right路徑, 判斷完之後才能判斷left-route
    }
/*    if(cur){//找到p, 判斷有沒有successor
        if(!stk.empty()) return stk.top();//先判斷left-route會有錯誤    
        if(cur->right) return cur->right;
    }*/
    return NULL;//沒有找到p,或有找到p但沒有下一個節點(successor)
}
//===思路===

//====
void helper(TreeNode* root, TreeNode* p, vector<TreeNode*>& res){
    if(!root) return;
    helper(root->left, p, res);
    if(root==p|| (res.size()==1)){ 
        res.push_back(root); 
    }
    helper(root->right,p,res);
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    vector<TreeNode*> res;
    helper(root,p,res);
    return (res.size()==2)? res.back():NULL;
} 

//===思路2==
(*)直接利用 inorder-trasversal概念
(*)
    ...(描述) 截斷下一層...
    helper(root->left);
    ...(描述) 運算的內容會回傳給上層 ...
    helper(root->right);

//======
//這樣傳遞參數是錯誤的, 因為pre和suc是上層指標的副本,所以回到上層時,pre和suc的指標內容是不會改變的
//必須用global變數來取代local的pre和suc
void helper(TreeNode* root, TreeNode* p, TreeNode* pre, TreeNode* suc){
  if(!root) return NULL;
  helper(root->left,p,pre,suc);
  if(pre==p) suc=root;
  pre=root;
  helper(root->right,p,pre,suc);
}
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
  TreeNode *pre=NULL,*suc=NULL;
  helper(root,p,pre,suc);
  return suc?suc:NULL;
}
=>>>>>>>>>>>>>修正>>>>>>>>>>>>>>>>>>>
TreeNode* pre=NULL; TreeNode* suc=NULL;
void helper(TreeNode* root, TreeNode* p){
  if(!root) return NULL;
  helper(root->left,p);
  if(pre==p) suc=root;
  pre=root;
  helper(root->right,p);
}
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
  helper(root,p);
  return suc?suc:NULL;
}


