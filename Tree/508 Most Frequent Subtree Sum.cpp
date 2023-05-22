//===類似題===
510. Inorder Successor in BST II
1973. Count Nodes Equal to Sum of Descendants
//===思路===
(*)跟mode那一題很像,只是這一題是算subtree_sum
(*)post-order (DFS)
-計算完下層節點之後, 回傳下層節點的總和,所以會有left的總和,right的總和	
-依照題意,subtree_sum, 所以 當下的節點要加上left和right;得到的總和就是subtree_sum
-將subtree_sum紀錄到unordered_map, 
-subtree_sum計算完之後會回傳給上一層, 再依照上述計算其subtree_sum
-最後遍歷unordered_map, 列出最高頻的subtree_sum
//=====
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
//=====
int helper(TreeNode* root, int& mx ,unordered_map<int,int>& mp){
    if(!root) return 0;
    int ret = root->val + helper(root->left, mp)+helper(root->right,mp);    
    mx = max(mx,++mp[ret]);
    return ret;
}
vector<int> findFrequentTreeSum(TreeNode* root) {
    unordere_map<int,int> mp;//value,count
    vector<int> res;
    int mx = 0;
    helper(root,mx,mp);    
    for(auto a:mp){ if(mx==a.second) res.push_back(a.first); }
    return res;
}


