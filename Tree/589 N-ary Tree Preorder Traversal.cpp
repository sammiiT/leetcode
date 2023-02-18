//===類似題===
590. N-ary Tree Postorder Traversal
1361. Validate Binary Tree Nodes
2313. Minimum Flips in Binary Tree to Get Result
302. Smallest Rectangle Enclosing Black Pixels
//===思路===
(*)概念跟pre-order BST方法一致
-BST是root->left, root->right
-Node是 for(Node* a :root->children)//遍歷每一個子節點
//====
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preOrder(root,res);
        return res;
    }
    
    void preOrder(Node* root, vector<int>& res){
        if(!root) return;
        
        res.push_back(root->val);
        for(Node* n: root->children){
            preOrder(n,res);
        }
    }
    
};
