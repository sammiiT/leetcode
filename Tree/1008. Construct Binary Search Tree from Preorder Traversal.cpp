//===類似題===
1055. Shortest Way to Form String
130. Surrounded Regions
2540. Minimum Common Value
1746. Maximum Subarray Sum After One Operation
//===思路===

//=====
TreeNode* helper(vector<int>& arr, int i, int j){
    int p=i, q=j;
    TreeNode *left=NULL,*right=NULL;
    TreeNode* node= new TreeNode(arr[i]);

    while(p<=q){
        if(arr[i]<arr[p]) {
            right = helper(arr,p,q);
            break;
        }
        p++;
    }

    if(i<j && arr[i]>arr[i+1]){
        left = helper(arr,i+1,p-1);
        //left = helper(arr,i+1,j);
    }
    node->left = left;
    node->right = right;
    return node;
}


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
