//===類似題===
207. Course Schedule
841. Keys and Rooms
1367. Linked List in Binary Tree
//===思路===
(*)BFS 算法
push進queue中的順序都一樣, 只有在pop時, 依據level來判斷排序的先後順序
//===
vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        res.push_back({});
        for(int i=q.size(); i>0; --i){
            TreeNode* p=q.front();q.pop();
            if(res.size()%2) res.back().push_back(p->val);
            else res.back().insert(res.back().begin(),p->val);
            
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }
    return res;
}

===寫法2===
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> ret;
    if(root!=NULL) q.push(root);
    
    int zigzag=0;
    while(!q.empty()){
        int size=q.size();
        vector<int> nums;
        
        for(int i=size; i>0; --i){
            TreeNode* p=q.front();q.pop();
            if(zigzag%2==1) nums.insert(nums.begin(),p->val);
            else nums.push_back(p->val);

            if(p->left!=NULL) q.push(p->left);
            if(p->right!=NULL) q.push(p->right);
        }
        zigzag++;
        ret.push_back(nums);
    }
    return ret;

}
