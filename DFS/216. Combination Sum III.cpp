//===類似題===
377. Combination Sum IV
989. Add to Array-Form of Integer
253. Meeting Rooms II
1013. Partition Array Into Three Parts With Equal Sum

//===思路=====
(*)DFS
-每一個點都可以當作root節點
-每一個root節點都是上一level的child子節點

(*)因為數字不能重複,所以每進入下一個level, loop遍歷的起始位址都是從下一個位置開始

//=======
void helper2(int k, //k number
            int target, // target = 
            int start,
            vector<int>& out, 
            vector<vector<int>>& res){
    if(target==0 && k==0){//如果相加等於0, 且個數為k個, 則記錄至解中
        res.push_back(out);
        return;
    }
    if(k<0 || target<0) return;//超過k個或 超出target , 則返回
                
    for(int i=start; i<=9; ++i){
        out.push_back(i);
        helper2(k-1, target-i, i+1, out, res);
        out.pop_back();
    }
}

vector<vector<int>> combinationSum3_helper2(int k, int n) {
    vector<int> out;
    vector<vector<int>> res;
    helper2(k,n,1,out,res);
    return res;
}

//===寫法2===
void helper4(int k, int n, int start, vector<int>& out, vector<vector<int>>& res){
	if(out.size()==k && n==0) {
    	res.push_back(out);
        return;
    }
	if(out.size()>k || n<0) return;
	for(int i=start; i<=9; ++i){
		out.push_back(i);
		helper4(k,n-i,i+1,out,res);
		out.pop_back();
	}
}
//===寫法3===
void dfs(int k, 
        int n, 
        int sum, 
        int start, 
        vector<int>& out, 
        vector<vector<int>>& res){
    if(sum==n && k==0){
        res.push_back(out);
        return;
    }

    for(int i=start;i<=9; ++i){
        if((sum+i)>n) continue;
        if((k-1)<0) continue;
    
        out.push_back(i);
        dfs(k-1,n,sum+i,i+1,out,res);
        out.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> out;
    vector<vector<int>> res;
    dfs(k,n,0,1,out,res);
    return res;         
}



