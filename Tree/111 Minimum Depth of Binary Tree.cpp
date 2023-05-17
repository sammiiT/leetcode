//===類似題===
112. Path Sum
2196. Create Binary Tree From Descriptions
1602. Find Nearest Right Node in Binary Tree
2479. Maximum XOR of Two Non-Overlapping Subtrees
//===思路====
(*) post-order概念,但需要修改一下思路
-從root算起,如果只有單邊有subtree, 用maxdepth的算法, 會回傳,就是root那一個節點;所以須修改算法
-在判斷是否有左右節點時, 如果沒有左節點,就計算右節點的min_depth
-如果沒有右節點,就計算左節點的min_depth
-如果兩邊都有節點,則兩邊節點帶入函式遞迴做min比較

(*)
-minimum depth= 不能將"0"subtree做紀錄
-只能比較有長度的"最小深度"
--所以遇到左子樹是"0",就要計算右子樹
--所以遇到右子樹是"0",就要計算左子樹
//=======
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        if(!root->left) return 1+minDepth(root->right);//計算有節點的一邊
        if(!root->right) return 1+minDepth(root->left);//計算有節點的一邊
        
        
    int res = min(minDepth(root->left),minDepth(root->right));////兩邊都有節點
        return 1+ res;
    }

int minDepth_OK(TreeNode* root){
	if (!root) return 0;

	if (!root->left) return 1 + minDepth(root->right);//+1是當下層的節點
	if (!root->right) return 1 + minDepth(root->left);

	/*以下描述就是: return 1 + min(minDepth(root->left, root->right));
		if(root->left) l = minDepth(root->left);
		if(root->right) r = minDepth(root->>right);
		return 1+min(l,r);
	*/
	return 1 + min(minDepth(root->left), minDepth(root->right));
}


};
