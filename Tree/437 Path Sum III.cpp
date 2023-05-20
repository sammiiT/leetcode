//===類似題===
438. Find All Anagrams in a String
666. Path Sum IV
687. Longest Univalue Path
//===思路===
(*)pre-order (DFS)
1.(減法), 每進入下一層,就對targetSum-root->val; 如果等於0,代表滿足題意,解加1
2.因為不用從root開始算起,所以每次遍歷一次tree之後,就往下一階層,將其節點當成新的root節點做運算

   O <--從這一點遍歷                             O
  / \                     第二次計算            / \
 L   R                     =======>           L   R   <---從L,R節點當作root做運算,遍歷所有tree node
    / \                                          / \
   P   Q                                        P   Q 
//=======
void helper(TreeNode* root,long targetSum, int& res){
    if(!root) return;
    targetSum-=root->val;
    if(targetSum==0) res++;  //繼續運算下去, 因為有可能接下來的節點也會滿足題意  

    if(root->left) helper(root->left,targetSum,res);
    if(root->right) helper(root->right,targetSum,res);
}

void each(TreeNode* root, long targetSum,int& res){
    if(!root) return;
    helper(root,targetSum,res);
    each(root->left,targetSum,res);
    each(root->right,targetSum,res);        
}

    int pathSum(TreeNode* root, int targetSum) {
        int res = 0;
        each(root,targetSum,res);
        return res;
    }
    

//===================
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




