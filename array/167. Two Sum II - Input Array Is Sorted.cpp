//===類似題===
168. Excel Sheet Column Title
1099. Two Sum Less Than K

//===思路===
(*) two sum 一模一樣解法, 只是換成1-index
//====
vector<int> helper0(vector<int>& numbers, int target){
    unordered_map<int,int> m;
    vector<int> res(2,0);
    for(int i=0;i<numbers.size();i++){
        if(m.count(target-numbers[i])){
            res[0]=m[target-numbers[i]]+1;
            res[1]=i+1;
            break;
        }else{
            m[numbers[i]] = i;
        }
    }
    return res;
}
//===time limit exceeded====
DFS算法會造成time limit exceeded
因為每一種情況都考慮, 所以會超時
void helper11(vector<int>& nums,
            int target,
            int start,
            vector<int>& out, 
            vector<vector<int>>& res){
//if(target==0){    
    if(target==0 && (out.size()==2)){
        res.push_back(out);
        return;
    }
    if(out.size()>2) return;

    for(int i=start;i<nums.size(); i++){
        out.push_back(i+1);
        helper11(nums,target-nums[i],i+1,out,res);
        out.pop_back();
    }
}
vector<int> helper1(vector<int>& numbers, int target){
    vector<int> out;
    vector<vector<int>> res;
    helper11(numbers, target,0,out,res);
    return res.size()?res.back():out;
    //return res[0];//res.size()?res.back():res;
}
