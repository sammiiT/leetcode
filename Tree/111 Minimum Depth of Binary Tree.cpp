class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        
        
    int res = min(minDepth(root->left),minDepth(root->right));
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
	return 1 + min(minDepth(root->left, root->right));
}


};
