//===類似題===
1111. Maximum Nesting Depth of Two Valid Parentheses Strings
2049. Count Nodes With the Highest Score

//===思路====
(*)Tree post-order算法
1. TreeNode節點是distinct,所以數值不會重複,可以建立一個unordered_map<int,int>記錄to_delete
2. 建立vector<TreeNode*>& ,在每一次遇到to_delete數值時, 將此TreeNode的 left和right分別push至vector<TreeNode*>中
-遇到to_delete數值, 要回傳NULL給上一層銜接;讓上一層的root->left或root->right有截斷點
-如果root->left==NULL代表, "下一個節點是NULL", 或 "下一個是to_delete節點"

-兩描述差異:
root->left = helper(root->left, mp, res);//如果下層回傳NULL,則root->left可以真的被截斷
TreeNode* l = helper(root->left, mp, res);//如果下層回傳NULL, root->left還是會連結原來left節點


3. 因為是post-order算法, 所以當tree遍歷到root節點時, 是最上層的 return數值
-所以要多宣告一個TreeNode變數, 來"銜接"最上層的根節點 return

  
//====
TreeNode* helper(TreeNode* root, unordered_map<int,int>& mp,vector<TreeNode*>& res){
    if(!root) return root;
    root->left = helper(root->left, mp, res); //root->left=NULL
    root->right = helper(root->right, mp, res);

    if(mp.count(root->val)){
        if(root->left) res.push_back(root->left);
        if(root->right) res.push_back(root->right);
        
        return NULL;
    }
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> res;
    TreeNode* top = NULL;
    unordered_map<int,int> mp;
    
    for(int i:to_delete) mp[i]=1;
    top=helper(root,mp,res);
    if(top) res.insert(res.begin(),top);
  //if(top) res.push_back(top);//此描述也可以  
    return res;
}

//===思路2===
(*)用set<int>紀錄 vector<int>的數值

TreeNode* helper1(TreeNode* root, 
                    set<int>& to_delete, 
                    vector<TreeNode*>& res){
    if(!root) return root;             
                
    root->left = helper1(root->left,to_delete,res);
    root->right = helper1(root->right,to_delete,res);                     
    if(to_delete.count(root->val)){
        if(root->left) res.push_back(root->left);
        if(root->right) res.push_back(root->right);
        return NULL;
    }
    return root;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    set<int> st(to_delete.begin(),to_delete.end());
    vector<TreeNode*> res;
    TreeNode* node = helper1(root,st,res);
    if(node) res.push_back(node);
    return res;
}


  
