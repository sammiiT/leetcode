//===類似題===
1055. Shortest Way to Form String
130. Surrounded Regions
2540. Minimum Common Value
1746. Maximum Subarray Sum After One Operation
//===思路===
(*)陣列的第一個節點肯定是跟節點
(*)第一個大於跟節點的數,就是右子節點
(*)第一個小於跟節點的數,就是左子節點

8,5,1,7, 10,12
| \       \
|  left   right
root 


5,1,    7              10,  12
| \      \              |    \
|  left   right         |    right
root                   root


1.找到root之後, 搜尋第一個比root大的值就是此right, 第一個比root小的就是left
2.left帶入下一個遞迴,作為下一個level的root; right帶入下一個遞迴,作為下一個level的root; 重複步驟(1)

(*)搜尋left和right節點的順序, 必須先搜尋right, 才能知道left child的邊界    
(*)postorder概念,連接整個樹, 最後將root回傳
//=====
TreeNode* helper(vector<int>& arr, int i, int j){
    int p=i, q=j;
    TreeNode *left=NULL,*right=NULL;
    TreeNode* node= new TreeNode(arr[i]);

    while(p<=q){//先搜尋右邊子樹
        if(arr[i]<arr[p]) {
            right = helper(arr,p,q);
            break;
        }
        p++;
    }//最後的p是left子樹的邊界

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
