class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        helper(root,"",res);
        return res;
    }
    
    void helper(TreeNode* root,string s ,int& res){
        if(!root) return;
        
        s+=to_string(root->val);
        if((!root->left)&&(!root->right)){
            res += stoi(s);
        }else{
            helper(root->left,s,res);
            helper(root->right,s,res);
        }
    }
};

Input: [4, 9, 0, 5, 1]
  	 4
	/ \
   9   0
  / \
 5   1
Output: 1026

Explanation :
	The root - to - leaf path 4->9->5 represents the number 495.
	The root - to - leaf path 4->9->1 represents the number 491.
	The root - to - leaf path 4->0 represents the number 40.
	Therefore, sum = 495 + 491 + 40 = 1026.