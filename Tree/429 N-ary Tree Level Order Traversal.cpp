//==類似題====
428. Serialize and Deserialize N-ary Tree
2039. The Time When the Network Becomes Idle
//===思路===

//=====
void helper(Node* root, int level, vector<vector<int>>& res){
    if(!root) return;
    if(level==res.size()) res.push_back({});
    res[level].push_back(root->val);

    for(int i=0; i<root->children.size(); i++){
        helper(root->children[i],level+1,res);
    }
}
vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        helper(root,0,res);
        return res;   
}
//====
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        helper(root, 0,res);
        return res;
    }
    
    void helper(Node* root, int level, vector<vector<int>>& res){
        if(!root) return;
    
        if(res.size()==level) res.push_back({});
        res[level].push_back(root->val);
    
        for(Node* n : root->children){
            helper(n,level+1,res);
        }
    }
};
