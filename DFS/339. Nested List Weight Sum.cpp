//===類似題===


//===思路===
(*)DFS算法
1.遇到觸發條件成立,就會往下一層做運算
觸發條件: 如果遇到不是integer, 而是list,則往下一層做運算

//======
int helper(vector<NestedInteger> ni, int level){
  int res = 0;
  if(ni.isInteger()) return level*ni.getInteger();
  for(auto a:ni){
      res+=helper(a,level+1);
  }
  return res;
}
int depthSum(vector<NestedInteger>& nestedList){
  int res = 0;
  for(auto a:nestedList){
      res+= helper(a,1);
  }
  return res;
}
//===寫法2===
int helper0(vector<NestedLinteger>& nestedList, int level){
  int sum =0;
  for(auto a:nestedList){
    if(a.isInteger()) sum+=a.getInteger()*level;
    else sum+=helper0(a.getList(),level+1);
  }
  return sum;
}
int depthSum(vector<NestedInteger>& nestedList){
  int helper0(nestedList,1);
}

//===思路2===
(*)思路1優化
//======
int helper(vector<NestedInteger> ni, int level){
    int res = 0;
    for(auto a : ni)
      res += ni.isInteger()?level*ni.getInteger(): helper(a.getList(),level+1);
    return res;
}

//===思路3===
void helper(NestedInteger& nestInteger, int level, int& res){        
    if(nestInteger.isInteger()) {
        res+=(level * nestInteger.getIntger());
        return;
    }   
    for(int i=0;i<nestInteger.getList().size(); ++i){
        helper(nestInteger.getList()[i],level+1,res);
    }
}
int depthSum(vector<NestedInteger>& nestedList) {
    int res = 0;
    for(int i=0; i<nestedList.size(); ++i){
        helper(nestedList[i],1,res);
    }
    return res;
}





/*
class NestedInteger {
    public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
};*/
