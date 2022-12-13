//====類似題=====
655. Print Binary Tree
998. Maximum Binary Tree II

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
