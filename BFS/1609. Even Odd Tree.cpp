//===類似題===
1020. Number of Enclaves
2101. Detonate the Maximum Bombs
1096. Brace Expansion II
//===思路===
(*)用tree的trasversal計算, 不好寫, 用BFS會比較好
- 變數 boundary 用來記錄前一個節點的數值, 用來做increase或decrease的比較
//====
bool isEvenOddTree(TreeNode* root) {
        int level = 0;//even => increase, node = odd, 
                      //odd => decrease, node = even
        int boundary;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            boundary = (level%2)?INT_MAX:INT_MIN;
          
            for(int i=size; i>0; --i){
                TreeNode* p = q.front();q.pop();
                if(level%2==0){//even_level=>increase, node = odd
                    if(p->val<=boundary || (p->val%2)==0) {
                        cout<<"val="<<p->val<<"; boundary="<<boundary<<"; even_level, node=odd"<<endl;
                        return false;
                    }
                }else{//odd_leve=>decrease, node = even
                    if(p->val>=boundary || (p->val%2)==1) {
                        cout<<"val="<<p->val<<"; boundary="<<boundary<<"; odd_level, node=even"<<endl;
                        return false;        
                    }
                }
                boundary = p->val;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            level+=1;
        }
        return true;

    }
