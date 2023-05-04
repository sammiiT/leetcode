//===類似題===

//===思路===

//====
void helper(NestedInteger& nestInteger, int level, vector<int>& res){
    if(res.size()==level) res.push_back(0);
    if(nestInteger.isInteger()) { 
        res[level]+=nestInteger.getIneger();
        return;
    }
    
    for(int i=0; i<nestInteger.getList().size(); ++i){
        helper(nestInteger.getList()[i],level+1,res);
    }
}
int depthSumInverse(vector<NestedInteger>& nestedList) {
    
    vector<int> res;
    int sum = 0;
    for(NestInteger a: nestedList){
        helper(a,0,res);
    }
    
    for(int j=1,i=res.size()-1; i>=0; --i, ++j){
        sum = res[i]*j;
    }
    return sum;
}
