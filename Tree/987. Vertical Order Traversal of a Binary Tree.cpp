//===類似題===
988. Smallest String Starting From Leaf
449. Serialize and Deserialize BST
1448. Count Good Nodes in Binary Tree
140. Word Break II
//===思路===
(*)定義map<int,map<int,vector<int>>>
-位於(x,y)位置的節點
-第一個int是x, 第二個int是y
-最後一個vector<int>是在相同(x,y)位置的節點值
-此map是存每一個TreeNode的相對位置,和對應值

(*)定義queue<pair<vector<int>,TreeNode*>>
-每一個節點的位置(x,y)
-每一個節點位置最後都會被放到map中
//=====
vector<vector<int>> helper1(TreeNode* root){
    vector<vector<int>> res;
    map<int,map<int,vector<int>>> m;//x,map<y,vector<int>>
    queue<pair<vector<int>,TreeNode*>> q;

    q.push({{0,0},root});

    while(!q.empty()){
        auto a = q.front(); q.pop();
        int x = a.first[0],y = a.first[1];
        TreeNode* node = a.second;
        m[x][y].push_back(node->val);//節點位置會重疊, 所以同一位址,要push_back
        if(a.second->left) q.push({{x-1,y+1},a.second->left});
        if(a.second->right) q.push({{x+1,y+1},a.second->right});
    }

    for(auto a:m){
        vector<int> r;
        for(auto b:a.second){
            /* b.first=y       b.second=vector<int>   */
            sort(b.second.begin(),b.second.end());
            //不可以用push_back(b.second),因為push_back是帶入element,不是代入陣列
            //要用insert的方式把一個陣列加入, 如下
            r.insert(r.end(),b.second.begin(),b.second.end());
        }
        res.push_back(r);
    }
/*
for(auto a:m){//概念同上,但是一個一個加入res.back()中
    res.push_back({});
    for(auto b:a.second){
        int leve = b.first;
        vector<int>& v = b.second;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();++i){
            res.back().push_back(v[i]);
        }
    }
}
*/    

    return res;
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
    return helper1(root);    
}

//=== 思路 寫法2 ====

void bfs(TreeNode* root,vector<vector<int>>& res){
    map<int,map<int,vector<int>>> mp;
    queue<pair<vector<int>,TreeNode*>> q;//x-coord, node
    q.push({{0,0},root});

    while(!q.empty()){
        for(int i=0;i<q.size();++i){
            pair<vector<int>,TreeNode*> p = q.front();q.pop();
            mp[p.first[0]][p.first[1]].push_back(p.second->val);
            if(p.second->left!=NULL) {
                q.push({{p.first[0]-1,p.first[1]+1},p.second->left});
            }
            if(p.second->right!=NULL) {
                q.push({{p.first[0]+1,p.first[1]+1},p.second->right});
            }
        }
    }

    for(auto x:mp){//< x.first = x-coord  , x.second = <y-coord,vector> >
        res.push_back({});
        for(auto it: x.second){//x.second=map   //< it.first=y-coord , it.second=vector > 
            sort(it.second.begin(),it.second.end());
            for(int i=0;i<it.second.size();++i){
                res.back().push_back(it.second[i]);
            }
        }
    }
}

