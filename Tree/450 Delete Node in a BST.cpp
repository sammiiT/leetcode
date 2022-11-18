class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key){
        if(!root) return NULL;
        
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else{//(root->val == key)
            if(!root->left || !root->right){
                TreeNode *tmp; 
                if(!root->left){
                    tmp = root->right;
                }else{//!root->right
                    tmp = root->left;
                }
                delete root;//將node delete
                return tmp;
                // return root->left?root->left:root->right; 
                
            }else{//root->left && root->right
                TreeNode *cur = root->right;
                while(cur->left) cur=cur->left;
                root->val = cur->val;
                //delete cur node,最後會跳到 (!root->left || !root->right)
                root->right = deleteNode(root->right,cur->val);
                
/*                
//錯誤                
        TreeNode * cur = root->right;
        while(cur->left) cur=cur->left;
        root->val = cur->val;
        delete cur;
        cur = NULL;
                
     o
    / \            
   o   o  cur = root->right           
      /         
     o    cur = minimum, 如果直接delete節點, 則right會不見      
      \   
       o  
        \ 
         o
*/         
            }
        }
        return root;
    }
    
    TreeNode *minNode(TreeNode *root){
        if(root && root->left) return minNode(root->left);
        else return root;
    }
    TreeNode *maxNode(TreeNode *root){
        if(root && root->right) return maxNode(root->right);
        else return root;
    }
    
    
    
    
    
    
    
    //橫跨3個節點, 用中間的節點來作運算,比較容易
    TreeNode* deleteNode_ok(TreeNode* root, int key) {
        if(!root)  return NULL;
        
        if(root->val < key){
            root->right = deleteNode(root->right,key);    
        }else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }else{//root->val == key
            if(root->left==NULL || root->right==NULL){
                return root->left?root->left:root->right;
            }else{
                //(root->left && root->right)        
                TreeNode *cur = root->right;
                while(cur->left) cur=cur->left;
                root->val = cur->val;
                
                root->right = deleteNode(root->right,cur->val);
            }
            
        }
        return root;
    }
};

//用return的方式回傳下一個節點, 可以知道指定節點的前一個節點
TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
    
        if(root->val==key){//移除節點, 重新建構
            TreeNode *l=root->left;
            TreeNode *r=root->right;
            TreeNode *tmp;
            tmp = r;
            while(tmp&&tmp->left){
                tmp=tmp->left;
            }
            if(tmp){
                tmp->left = l;
                return r;
            }else{
                return l;
            }
        }
        //用return的方式回傳下一個節點, 可以知道指定節點的前一個節點
        if(root->left) root->left = deleteNode(root->left, key);
        if(root->right) root->right = deleteNode(root->right, key);
        
        return root;    
}

