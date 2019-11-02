class Solution {
public:
    int maxDepth(Node* root) {
        // int res = 0;
        // helper(root,1,res);
        // return res;
        if(!root) return 0;
        int res=1;
        for(Node *child: root->children){
            res=max(res,maxDepth(child)+1);
        }
        return res;
    }
    
    void helper(Node* root, int cur, int& res){
        if(!root) return;
        
        if(root->children.empty()) res = max(res,cur);
        for(Node* n:root->children){
            helper(n,cur+1,res);    
        }
    }
};
