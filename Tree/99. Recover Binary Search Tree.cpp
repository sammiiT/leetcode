//===類似題===
100. Same Tree
1740. Find Distance in a Binary Tree
2467. Most Profitable Path in a Tree
261. Graph Valid Tree

//===思路===
1.Tree中只有兩個數值造成不能滿足BST, 所以可以將其展開為一個陣列, 將這兩數值互換
2.利用inorder 遍歷所有節點, 並記錄到陣列中
3.for loop一次得到nums[i]<nums[i-1]的兩個位址
3.1如果兩數相鄰, 則會記錄一筆資料; (index資料)
3.2如果兩數不相鄰, 則會記錄到兩筆資料
4.利用index資料, 將兩點互換

(*) 不能用 minValue和 maxValue思維,  
因為此思路是每一個節點都去跟子節點做比對
那種題型會發生不只一個順序對調的節點, 某一child tree的節點會全部大於root,或 全不小於root
//=====================================
void vectorExpand(TreeNode* root,vector<TreeNode*>& nums){//將tree展開為陣列
        if(!root) return;
        vectorExpand(root->left, nums);
        nums.push_back(root);
        vectorExpand(root->right, nums);
}
void helper0(TreeNode* root){
        vector<TreeNode*> nums;
        vector<vector<int>> v;
        vectorExpand(root,nums);
        
        for(int i=1; i<nums.size(); i++){//紀錄降序的位置
            if(nums[i]->val<nums[i-1]->val) v.push_back({i-1,i});
        }
        if(v.size()==1){//如果兩點相鄰, 僅一筆資料
            int tmp = nums[v[0][0]]->val;
            nums[v[0][0]]->val=nums[v[0][1]]->val;
            nums[v[0][1]]->val=tmp;
        }else if(v.size()==2){//如果兩點不相鄰, 會有兩筆資料
            int tmp = nums[v[0][0]]->val;
            nums[v[0][0]]->val = nums[v[1][1]]->val;
            nums[v[1][1]]->val = tmp;    
        }
}
void recoverTree(TreeNode* root) {
        helper0(root);
}
//===思路2=====
1.宣告vector<int>, vector<TreeNode*>
2.用inorder遍歷,紀錄每一個node和node->val到對應的vector中
3.先sort vector<int>
4.for 迴圈將按照順序的vector<int>數值寫入vector<TreeNode*>數值中

void inorder(TreeNode* root, vector<int>& o,vector<TreeNode*>& t){
    if(!root) return;
    inorder(root->left,o,t);
    o.push_back(root->val);
    t.push_back(root);
    inorder(root->right,o,t);
}
void helper1(TreeNode* root){
    vector<int> o;
    vector<TreeNode*> t;
    inorder(root,o,t);
    sort(o.begin(),o.end());
    for(int i=0;i<o.size();++i){
        t[i]->val=o[i];
    }
}
    void recoverTree(TreeNode* root) {
//        helper0(root);
        helper1(root);
    }

