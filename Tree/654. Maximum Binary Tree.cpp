//====類似題=====
655. Print Binary Tree
998. Maximum Binary Tree II
//===思路===
(*)pre-order概念 (DFS)
1.找到最大值之後, 建立左右兩邊的陣列    
2.兩邊的陣列所建立的subtree分別是當下節點的left和right 
3.遞迴帶入函式,將回傳值指派給left和right

(*)vector<int> 概念:
vector<int> l(nums.begin(),nums.begin()); 
l.size()會等於"0"
//=======
int maxSearch(vector<int>& nums){
    int mx = nums[0];
    int ret = 0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]>mx) {
            mx = nums[i];
            ret = i;
        }
    }
    return ret;
}

TreeNode* helper0(vector<int>& nums){
    if(nums.size()==0) return NULL;
    
    int mxIdx = maxSearch(nums);
    TreeNode* ret = new TreeNode(nums[mxIdx]);
    
    vector<int> left(nums.begin(), nums.begin()+mxIdx);   
    vector<int> right(nums.begin()+mxIdx+1, nums.end());

    ret->left = helper0(left);
    ret->right = helper0(right);
    return ret;
}
TreeNode* helper1(vector<int>& nums){
    TreeNode *l=NULL,*r=NULL;
    int mxIdx = maxSearch(nums);
    TreeNode* ret = new TreeNode(nums[mxIdx]);
       
    vector<int> left(nums.begin(), nums.begin()+mxIdx);   
    vector<int> right(nums.begin()+mxIdx+1, nums.end());

    if(left.size()) l= helper0(left);
    if(right.size()) r= helper0(right);

    ret->left = l;
    ret->right = r;
    return ret;
}

 TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper1(nums);
//        return helper0(nums);
 }
//====思路====
[3,2,1,6,0,5]

                  mx                mx 
                    \                \ 
mx   6               6                6        
  \ /               / \              /   \
   3               3   0            3     5
    \               \                \    /
     2               2                2  0  
      \               \                \
       1               1                1 

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    vector<TreeNode*> s{new TreeNode(INT_MAX)};
                      
    for(int i=0;i<nums.size();++i){
        TreeNode* node = new TreeNode(nums[i]);
        int temp = nums[i];
        while(s.back()->val<temp){
            node->left = s.back();
            s.pop_back();
        }
        s.back()->right = node;
        s.push_back(node);        
    }
    return s[1];
}
