class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int mid = nums.size()/2;//middle node in linked list
        TreeNode* cur = new TreeNode(nums[mid]);
    
        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1,nums.end());
        
        cur->left = sortedArrayToBST(left); 
        cur->right= sortedArrayToBST(right);
        return cur;
    }
    
    TreeNode* sortedArrayToBST_OK(vector<int>& nums) {
        if(nums.empty()) return NULL;
        
        int s=0,e=nums.size()-1;
        int mid = s+(e-s)/2;
        TreeNode* cur =new TreeNode(nums[mid]);
        
        vector<int> l(nums.begin(),nums.begin()+mid);//不包含mid
        vector<int> r(nums.begin()+mid+1,nums.end());
        
        cur->left = sortedArrayToBST(l);
        cur->right= sortedArrayToBST(r);
        
        return cur;
        
    }
};