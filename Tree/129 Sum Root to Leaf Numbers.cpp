//===類似題===
130. Surrounded Regions
988. Smallest String Starting From Leaf
//===思路===
(*) pre-odrder (DFS)
1.每進入一層,就將當下的節點 轉換為string模式,並與上一層的string做疊加
2.如果當下層是最後一層, 則將string用stoi轉換成真正的integer形態, 累加
3.最後遍歷完所有節點, 累加值就是解
//======
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
