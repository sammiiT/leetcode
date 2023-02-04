//===類似題===
118. Pascal's Triangle
211. Design Add and Search Words Data Structure
1597. Build Binary Expression Tree From Infix Expression
1810. Minimum Path Cost in a Hidden Grid
116. Populating Next Right Pointers in Each Node
//===思路===
(*)同 populating Next Right pointers in each node
(*)level-order
-將相同level中的每一個節點,以陣列的形式記錄在 vector<vector<TreeNode*>>中
-最後每一個認列做遍歷, 將next指向同陣列的下一個節點

//=====
void helper0(Node* root, int level, vector<vector<Node*>>& res){
    if(!root) return;
    if(level==res.size()) res.push_back({});
    res[level].push_back(root);
    helper0(root->left, level+1, res);
    helper0(root->right, level+1,res);    
}
    Node* connect(Node* root) {
        vector<vector<Node*>> res;
        helper0(root,0,res);
        for(int i=0; i<res.size(); i++){
            for(int j=0; j<res[i].size(); j++){
                if(j==res[i].size()-1) res[i][j]->next=NULL;
                else res[i][j]->next=res[i][j+1];
            }
        }    
        return root; 
    }
