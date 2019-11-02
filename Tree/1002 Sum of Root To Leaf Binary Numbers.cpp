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