//===類似題===
125. Valid Palindrome
666. Path Sum IV
687. Longest Univalue Path
1376. Time Needed to Inform All Employees
//===思路===
(*)post-order概念解題
(*)each pair of adjacent nodes in the sequence has an edge connecting them
- 有子節點, 一定是兩個; 不會只有一個
- 如果沒有子節點, 則兩邊都沒有, left和right都沒有

(*)post-order, 由下往上計算,當遇到left_path為負值或right_path為負值, 則不考慮走"-"的路徑 (捨棄之前的之前的路徑), 所以要用max(helpper(root->left,res),0)來做判斷
max(helper(root->left,res),0);
max(helper(root->right,res),0);
	
                  11
                 /  \   
	        3    41
              /  \     \
            20	 7     -87
           /  
        -100   
	/  \
      3     7 

[-100,3,7] 上傳給20節點, 會負值, 所以不考慮 [-100,3,7], 指派0
max(helper(root->left,res),0);

[null,-87] 上傳節點41, 會負值, 所以不考慮[null,-87], 指派0
max(helper(root->right,res),0);

/*******
錯誤思路
*******/
res = max(max(max(max(res,l+r+root->val),l+root->val),r+root->val),root->val)
                      1.左右總和+當下節點
                                      2.左總和+當下節點 
                                                    3.右總和+當下節點
                                                                  4.當下節點 

錯誤邏輯:	
右總和 <0 且 當下節點<0  ==> 比較哪一個靠近0 並回傳 => 回傳負值 => 錯誤
左總和 <0 且 當下節點<0  ==> 比較哪一個靠近0 並回傳 => 回傳負值 => 錯誤 

(*)如果一直都是負值, 就要回傳0
	
max(helper(root->left,res),0)//比較左邊的最大的總和, 0
	                     //每往上一個節點, 若都是負值, 則 左總和會越來越小.
//=====
int helper(TreeNode* root, int& res){
    if(!root) return 0;
    int l=0,r=0;

    l = max(helper(root->left,res),0);
    r = max(helper(root->right,res),0);

    res = max(res,root->val+l+r);//計算某個subtree的maximum, 所以要當下節點+左路徑+右路徑
    return root->val+max(l,r);//左路徑,右路徑, 取sum最大的回傳.
}
int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root,res);
        return res;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root,res);
        return res;
    }
    
    int helper(TreeNode *root, int& res){
        if(!root) return 0;
        
        int l=0,r=0;//沒設定初始值, 以下的描述會出現錯誤
        if(root->left) l = max(helper(root->left,res), 0);//如果left為負值,則用0來計算,截斷
        if(root->right) r= max(helper(root->right,res), 0);//如果right為負值,則用0來計算截斷
    
        res = max(res,l+r+root->val);	//res是討論雙邊,l加r邊
        return max(l,r)+root->val;		//return是討論單邊,l或r邊
    }
		
   int helper(TreeNode* root, int& vmax){//從底部開始往上找,才會與到交叉點.=> 交叉點就是parent節點 
        if(!root) return 0;      
        int l=0,r=0;
//        if(root->left) l = helper(root->left,vmax);//如果有負數, 會有錯誤
//        if(root->right) r = helper(root->right,vmax);//如果有負數, 會有錯誤
        
        if(root->left) l = max(helper(root->left,vmax),0);
        if(root->right) r = max(helper(root->right,vmax),0);
        
        vmax = max(vmax, l + r + root->val);
        return root->val + max(l,r);
    }
	
};

Input: [1, 2, 3]
	 1
	/ \
       2   3
Output: 6


Input : [-10, 9, 20, null, null, 15, 7]

	-10
	/ \
       9  20
	  / \
	 15  7

Output: 42

// if(!root) return INT_MIN;   
//         int l=0,r=0;
//         if(root->left)  l = helper(root->left, res);
//         if(root->right) r = helper(root->right,res);
//         if(l>=0 && r >=0 && root->val >=0){
//             res = max(res,root->val+l+r);
//         }else if(l>=0 && r<0){
//             res = 
//         }
//         res = max(res, root->val+l+r);
//         res = max(res, root->val);
//         return (l>=r)? (l+root->val) : (r+root->val); 
