//===類似題===
1023. Camelcase Matching
1600. Throne Inheritance
210. Course Schedule II
1993. Operations on Tree
//===思路===
(*) pre-order算法 (DFS)
(*) 用stack概念
1.每進一層,就將運算元向左位移一位
2.當與到最後一個節點, 就累加
//====
void helper(TreeNode* root, int val, int& res){
    if(!root) return;
    val = val | root->val;
    if(!root->left && !root->right){
        res+=val;
        return;
    }
    helper(root->left,  val<<1, res);//每進一層,就將運算元向左位移一位
    helper(root->right, val<<1, res);
}

void helper(TreeNode* root, int val, int& res){
    if(!root) return;
    val = (val<<1) + root->val;
    if(!root->left && !root->right){
        res+=val;
        return;
    }
    if(root->left) helper(root->left,val,res);
    if(root->right) helper(root->right,val,res);
}

int sumRootToLeaf(TreeNode* root) {
    int res = 0;
    helper(root,0,res);
    return res;    
}

//=========
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<int> bin;
        int res = 0;
        helper(root,0,bin,res);
        return res;
    }
    
    void helper(TreeNode *n, int level, vector<int> &bin, int& res){
        if(!n) { 
            //放在這邊,若為最後一個節點,left, right都為NULL,則會重複算兩次
            // if(level > 1){
            //     for(int i=bin.size(), j=0; i>0; --i,++j){
            //         res = res + (2^j)*bin[i];  
            //     }
            // }
            return;
        }
        
        
                
        bin.push_back(n->val);
        
        if(!n->left && !n->right){//最後一個節點
            if(level>0){//(1) i為vector的index中的值; (2) j為2的次方項
                for(int i=bin.size(), j=0; i>0; --i,++j){
                    res = res + pow(2,j)*bin[i-1];  
                }
            }else{//level ==0
                res =  res + bin[0];
            }
            bin.pop_back();
            return;
        }
        
        helper(n->left, level+1, bin, res);
         // bin.pop_back();
        helper(n->right, level+1, bin, res);
         bin.pop_back();
    }
};


//====failed====
(*)level每次加一層,就會向左位移越多位...不是每次只位移一層
void helper(TreeNode* root, int level, int val, int& res){
    if(!root) return;

    //val = val + (root->val)<<level;
    val = (val<<level) | root->val;
    if(!root->left && !root->right){
        res+=val;
        return;
    }
    helper(root->left, level+1, val, res);//level每次加一層,就會向左位移越多位...不是每次只位移一層
    helper(root->right, level+1, val, res);
}
