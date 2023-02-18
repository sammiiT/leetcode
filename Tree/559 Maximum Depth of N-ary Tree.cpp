//===類似題===
589. N-ary Tree Preorder Traversal
2039. The Time When the Network Becomes Idle
//===思路===
(*)post-order算法
1.BT的left和right換成Node;Node底下有多個節點 vector<Node*> children

2.BT的比較是,比較左右兩邊,看哪一邊的節點最多
l = helper(root->left);
r = helper(root->right);
res = max(l,r);
return res+1;//加1是當層節點,回傳給上一層
=> 上述可以寫成 res = max(helper(root->left),helper(root->right));
=> 或 res = max(res,helper(root->left));
      res = max(res,helper(root->right));
=>用上述想法用在多節點條件

3.用上述想法用在多節點條件
for(Node* a:root->children){
    mx = max(mx,helper(a));
}  


//=====
int maxDepth(Node* root) {
    if(!root) return 0;
    int mx = 0;
    for(Node* a:root->children){
        mx = max(mx,maxDepth(a));
    }
    return 1+mx;
}
//===思路2===
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
