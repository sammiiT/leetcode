class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        vector<pair<int,double>> res;
        
        helper(root,0,res);
        
        for(int i=0; i<res.size(); ++i){
            double val = res[i].second/res[i].first;
            ret.push_back(val);
        }
        return ret;
    }
    
    void helper(TreeNode *root,int level,vector<pair<int,double>> &res){
        if(!root) return;
        
        if(res.size()==level) res.push_back({0,0});

        res[level].first += 1; //coumt
        res[level].second += root->val;//sum
    
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
    }
};

//================
void helper(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root) return;
        
        if(level==res.size()) res.push_back({});
        res[level].push_back(root->val);
        
        helper(root->left,level+1,res);
        helper(root->right,level+1,res);
}
    
vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> res;
        vector<double> ret;
        double sum = 0;

        helper(root, 0, res);
       
        for(int i=0;i<res.size();i++){
            sum = 0;
            for(int j = 0; j<res[i].size(); j++){
                sum+=res[i].at(j);
            }
            ret.push_back(sum/res[i].size());
        }
        return ret;
}
