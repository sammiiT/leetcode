//===類似題===
109. Convert Sorted List to Binary Search Tree
2295. Replace Elements in an Array
2419. Longest Subarray With Maximum Bitwise AND
1198. Find Smallest Common Element in All Rows
//===思路===
(*) binary search tree, 取2nd-middle作為parent節點,才會滿足height-balance
(*) 考vector<int>的constructor	
vector<int> v(nums.begin(),nums.end());//建立一vector v, 內容為vector nums的begin到end

(*)用post-order + pre-order概念來求解
-先建立parent節點
-將parent節點的left和right分別指向另外兩半所建立的sub-tree
-最後回傳parent
//=========
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;

		//need second middle: mid = size()/2 +1;   
		//					index mid = size()/2+1-1;
		//					index mide = size()/2;

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
