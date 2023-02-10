//===類似題===

//===思路===
(*)pre-order(DFS)
 1.初始化mi數值, 設定default為IN_MAX
 2.比較每一個節點與target的差異;如果比mi還要小,則記錄
 
//====
void helper(TreeNode* root, int& val, double& mi, double target){
    if(!root) return;
    if(abs((double)root->val - target) <= mi){
        mi = abs(root->val-target);
        val = root->val;
    }
    helper(root->left, val, mi, target);
    helper(root->right,val,mi, target);
}

int closestValue(TreeNode* root, double target){
    int val = root->val;
    double mi = INT_MAX;
    
    helper(root,val,mi,target);
    return val;
}
