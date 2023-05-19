//====類似題===
117. Populating Next Right Pointers in Each Node II
118. Pascal's Triangle
1091. Shortest Path in Binary Matrix
146. LRU Cache
1740. Find Distance in a Binary Tree

//===思路===
1. 記錄每一level的所有node; 此資料會形成一個vector<vector<Node*>>的陣列
2. 遍歷每一階層的陣列, 並將陣列中的每一個Node的next指向下一個節點

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
//===思路2====
void helper1(Node* root, int level, vector<vector<Node*>>& res){
    if(!root) return;
    if(res.size()==level) res.push_back({});
    if(res[level].size()>0){
        res[level].back()->next = root;
    }
    res[level].push_back(root);
    root->next = NULL;
    helper1(root->left,level+1,res);
    helper1(root->right,level+1,res);
}




