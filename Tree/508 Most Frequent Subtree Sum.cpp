class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> m;
        int cnt = 0;
        vector<int> res;
        helper(root,cnt,m);
        
        if(cnt <= 1){//如果每個數值只出現過一次,列出所有的數值
            for(auto a: m){
                res.push_back(a.first);
            }
        }else{//cnt >1//如果出現超過1, 則列出現做多的數值
            for(auto a:m){
                if(a.second == cnt){
                    res.push_back(a.first);
                }
            }
        }
        return res;
        
    }
    
    
    
    int helper(TreeNode* root, 
		int& cnt,//紀錄 出現最多的次數 
		unordered_map<int,int>& m){//記錄每一個數值出現的次數
        if(!root) return 0;
        
        int l=0,r=0;
        if(root->left) l= helper(root->left, cnt, m);
        if(root->right) r = helper(root->right, cnt, m);
        
        int total = root->val + l + r;
        m[total]++;
        
        cnt = max(m[total],cnt);
        
        return total;
    }
};