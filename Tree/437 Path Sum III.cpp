class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> out;
        if(root==NULL) return 0;
        helper(root,sum,0,out,res);
        return res;
    }
    
    void helper(TreeNode *root, 
                int sum, 
                int curSum,
                vector<TreeNode*>& out,
                int& res){
        
        if(root==NULL) return;
    
        curSum+=root->val;
        if(curSum==sum) res++;
        
        out.push_back(root);
        int tmp = curSum;
        for(int i=0;i<out.size()-1;++i){
            tmp = tmp-out[i]->val;
            if(tmp==sum) res++;
        }
        
        helper(root->left,sum,curSum,out,res);
        helper(root->right, sum, curSum,out,res);
        
        out.pop_back();
    }
};

//====用減法
void helper(TreeNode* root, long targetSum, int& count){
        if(!root) return;        
        if(targetSum-root->val==0){
            count++;
        //    return;//要拿掉, 因為同一條路徑下會重複答案
        }
        helper(root->left,targetSum-root->val,count);
        helper(root->right,targetSum-root->val,count);
}
void sum(TreeNode* root, long targetSum, int& count){
        if(!root) return;
        helper(root,targetSum, count);
        sum(root->left,targetSum,count);//錯誤, 前面要加上 if(!root)才會正確
        sum(root->right,targetSum,count);
}

//====用加法
void helper(TreeNode* root, int targetSum, long curSum, int&res){
      if(!root) return;
     
      curSum+=root->val;
      if(curSum==targetSum) res++;
      helper(root->left, targetSum, curSum, res);
      helper(root->right, targetSum, curSum, res);
//      if((curSum + root->val)==targetSum){ res++; }      
//      helper(root->left, targetSum, curSum + root->val, res);
//      helper(root->right, targetSum, curSum + root->val, res);      
}
    
void sum(TreeNode* root, int targetSum, int& count){
        if(!root) return;
        helper(root,targetSum, 0, count);
        sum(root->left,targetSum,count);//錯誤, 前面要加上 if(!root)才會正確
        sum(root->right,targetSum,count);
}




