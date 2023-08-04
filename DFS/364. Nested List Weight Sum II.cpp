//===類似題===

//===思路===

//====寫法1===
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
//===寫法2===
void helper(vector<NestedInteger & nestedList, int level, vector<int>& res){
    if(level==res.size()) res.push_back(0);
    
    for(int i=0; i<nestedList.size(); ++i){
        if(nestedList[i].isInteger()) res[level]+=nestedList[i].getInteger();
        else{//
            helper(nestedList[i].getList(),level+1,res);
        }    
    }
}

int depthSumInverse(vector<NestedInteger>& nestedList) {
    vector<int> res;
    int sum=0;
    helper(nestedList,0,res);
    for(int k=1,i=res.size()-1; i>=0; --i,++k){
        sum+=k*res[i];
    }
    return sum;
}



