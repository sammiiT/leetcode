//====類似題====
653. Two Sum IV - Input is a BST
297. Serialize and Deserialize Binary Tree
449. Serialize and Deserialize BST
1948. Delete Duplicate Folders in System

//====思路====
1. post-order來記錄每一個子樹, 並將子樹轉換為一string, 並加入map中
2. 從map查找是否有重複的string
3. 如果重複string, 將node存入vector<TreeNode*>中

//===
string helper0(TreeNode* root, unordered_map<string,int>& m, vector<TreeNode*>& res){
        if(!root) return "@";
        string sl= helper0(root->left,m,res);
        string sr= helper0(root->right,m,res);
        
//        string s = to_string(root->val)+sl+sr;//錯誤,需隔開
/* 以下描述,若沒有隔開, 則(1,11), (11,1)會視為相同的subtree; 所以每一個需要用符號隔開   
   	     2
      1    11
   11  x  1   
*/
        string s = to_string(root->val)+","+sl+","+sr;
        
        if(m[s]==1) res.push_back(root);//之前已經出現過一次,就push_back,這次出現是第二次
        m[s]++;//下一次再出現 m[s]!=1, 出現兩次之後,下次就不會push_back
/*        if(m.count(s)) {//會有重複計算的情形出現, 因為出現過的string, m.count一定存在
            res.push_back(root);
        }else{
            m[s]++;
        }*/
        return s;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> m;
        vector<TreeNode*> res;
        helper0(root,m,res);
        return res;
}
