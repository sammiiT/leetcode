//===類似題===
174. Dungeon Game
251. Flatten 2D Vector
281. Zigzag Iterator
284. Peeking Iterator


//===思路====
(*)提供inorder 的iterator
(*)nex是提取下一個inorder的數值
(*)hasNext()判斷有沒有下一個數值

1.利用Stack,先將每一個節點的left(包括root節點)依序push到stack中
2.next()呼叫就是從stack中pop出一個TreeNode,
-同時也判斷此node是否有right節點,如果有right節點,則以此right節點為root,再次遍歷其left節點,並將這些節點push到stack中
-push到stack中的top, 就是下一個next節點

//======
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root){
            stk.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* n =stk.top();
        stk.pop();
        int ret = n->val;
        if(n->right){
            n = n->right;
            while(n){
                stk.push(n);
                n=n->left;
            }
        }
        return ret;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
private:
stack<TreeNode*> stk;
    
};
