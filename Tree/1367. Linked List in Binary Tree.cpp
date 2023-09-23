//===類似題===
1970. Last Day Where You Can Still Cross
1026. Maximum Difference Between Node and Ancestor
298. Binary Tree Longest Consecutive Sequence

//===思路=====
參考 is_same_tre
參考 is_sub_tree

bool helper(ListNode* head,TreeNode* root){
    if(!head) return true;
    if(!root) return false;
    ListNode* nxt = head;
    if(head->val==root->val){ nxt = head->next;
    } else { return false; }
    return helper(nxt,root->left)||helper(nxt,root->right);
}


bool helper1(ListNode* head,TreeNode* root){
    if(!root) return false;
    ListNode* nxt = head;
    if(head->val==root->val){ nxt = head->next;
    } else { return false; }
    if(nxt==NULL) return true;
    return helper(nxt,root->left)||helper(nxt,root->right);
}

bool isSubPath(ListNode* head, TreeNode* root) {
    if(!root) return false;
    if(helper(head,root)) return true;
   return isSubPath(head, root->left) || isSubPath(head, root->right); 
}
