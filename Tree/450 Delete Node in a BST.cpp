//===類似題===
451. Sort Characters By Frequency
776. Split BST
//===思路===
(*)post-order (DFS)
1.每次回傳child節點給上層
2.上層做連接,連接到的是下層回傳的child
- 如果沒有遇到key,則連接到的是原child

3.遇到的節點是key
-如果right是NULL,則直接回傳 left
-如果right存在,就遍歷其left節點
-right的最後一個left節點連接原來的left節點
-回傳right節點位址給上層

(*)post-order遍歷算法,會遍歷所有節點,所以會比較耗時
//=====
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
//...    
    TreeNode* l = root->left;
    TreeNode* r = root->right;
    TreeNode* tmp = r;
    if(root->val==key){
        if(!tmp) return l;//如果right是NULL,則直接回傳 left
        
        while(tmp->left) tmp = tmp->left;//如果right存在,就遍歷其left節點
        tmp->left = l;//right的最後一個left節點連接原來的left節點
        return r;//回傳right節點位址給上層
    }
    return root;        
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    if(root->val==key){
        TreeNode* r = root->right;
        while(r&&r->left) r=r->left;
        if(r){
            r->left = root->left;
            return root->right;
        }else{
            return root->left;
        }
    }
    return root;
}


//===思路2===
(*) pre-order算法
(*)pre-order算法會比較節省時間, 因為不必像post-order一樣遍歷所有節點
-pre-order遇到刪除的節點, 就直接運算, 不會遍歷到刪除節點以下的節點
//===
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

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return　NULL;
    if(root->val==key){
        TreeNode* r = root->right;
        while(r&&r->left) r = r->left;//如果有right節點, 遍歷right節點的left
        if(r){ 
            r->left = root->left;//連接right的left-leaf 和root->left
            return root->right;  //回傳root->right給上層
        } else return root->left;//如果沒有right節點, left節點直接回傳
    }
    root->left = deleteNode(root->left,key);
    root->right = deleteNode(root->right,key);
    return root;
}

//=====
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



