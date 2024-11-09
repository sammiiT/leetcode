//===類似題===
342. Power of Four
251. Flatten 2D Vector
281. Zigzag Iterator
385. Mini Parser

//===思路===
(*)用stack來做
1.每次判斷是否有下一個數值前,都要判斷boot hasNext()
-這時候要從stack中取出NestedInteger; 此類別中可以是一個數字,或一個陣列
-如果是數字,直接回傳true
-如果是陣列,則必須將其展開為"數字的NestedInteger型態"再push至stack中
-如果stack中沒有NestedInteger物件,則回傳false

NestedInteger 
-可以是單一個數值 [1] => vector<NestedInteger>
-可以是一個數值陣列 [1,2,3,4,5] =>vector<NestedInteger>: 用到5個NestedInteger, 用 getInteger(), isInteger()就可以判斷
-可以是一個nested數值陣列 [[1,2],[3,4]]=>vector<NestedInteger>:用到2個NestedInteger,用isInteger判斷為false,接著用getList
-可以是一個nested數值陣列 + 數值 [[1,2],3,[4,5]]=>vector<NestedInteger>:
                                 |    |   \
                                 |    |    \--->NestedInteger:用isInteger判斷為false,接著用getList
                                 |    |
                                 |     \---> NestedInteger:用isInteger判斷為true, 接著用getInteger
                                  \--->NestedInteger: 用isInteger判斷為false,接著用getList


(*)
1.將vector<NestedInteger>所有的NestedInteger元素,從後到前 push至stack中
[[1,2],3,[4,5]] => [4,5] | 3 | [1,2] 
                  
2.hasNext從stack.top()取出一個NestedInteger元素,如果此元素是一個vector<NestedInteger>,則重複1動作,將其轉換成NestedInteger再push回stack中
[4,5] | 3 | [1,2] => [4,5] | 3 | 2 | 1
                                                                            
3.hasNext就是把vector<NestedInteger>轉換成 isIngeter()==true的NestedInteger元素
[4,5] | 3 | [1,2] => 5| 4| 3| 2| 1
[4,5]的轉換,必須先將1,2,3 pop出來才會做到運算                   
                                      
                                      
4.next是用來讀取stack中的數值,並將其做pop動作
                                      
//=====
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1; i>=0; i--)
            ni.push(nestedList[i]);
    }
    
    int next() {
      NestedInteger t = ni.top();
      ni.pop();
      return t.getInteger();
    }
    
    bool hasNext() {
//      if(!ni.empty()){//必須用while,將nest中的陣列全部展開為止
        while(!ni.empty()){
            NestedInteger t = ni.top();
            if(t.isInteger()) return true;
            ni.pop();
            for(int i=t.getList().size()-1; i>=0; i--)
                ni.push(t.getList()[i]);  
        }
        return false;
    }
private:
    stack<NestedInteger> ni;
};

//-- hasNext 寫法2---
  bool hasNext() {
        while(!stk.empty()){
            if(stk.top().isInteger()) return true;
            if(stk.top().getList().size()<=0) {// [[],[3]] 如此情況, 將第一個空的排除
                stk.pop();
                continue;
            }
            NestedInteger tmp = stk.top();
            stk.pop();
            for(int i=tmp.getList().size()-1; i>=0; --i){//將integer做stack排列
                stk.push(tmp.getList()[i]);        
            }
        }
        return false;
//====錯誤寫法
沒考慮到[[],[3],[],[4,3,2]]情況

bool hasNext() {
  if(stk.empty()) return false;
  NestedInteger t = stk.top();
  if(!t.isInteger()){//當[];空集合; 也是not integer ,也不是List
      stk.pop();
      if(t.getList().size()<=0) return false;
      for(int i=t.getList().size()-1;i>=0;--i){
        stk.push(t.getList()[i]);
      }
  }
  return true;
}

//=== 思路3 ===
(*)利用queue + dfs
(*)宣告queue<NestedInteger>紀錄輸入的nestedList每一個NestedInteger元素
   宣告queue<int> 紀錄每一個nesetdList[i]所產生的iterator

(*)
hasNext(): 用來判斷是否有下一個數值
-先判斷queue<int> 是否有數值, 如果有, 則回傳true ; 如果沒有數值則執行下一個判斷
-再判斷queue<NestedInteger> 是否有 NestedInteger元素, 並對此NestedInteger做flatten iterator動作; 就是將NestedInteger中的元素都加入到queue<int>中, 可以經由next()獲取

(*)每次分析一個NestedInteger,都用dfs算法來做flatten iterator
  
(*)  
如果(1)是 if(!qn.emty())則會錯誤,當輸入為[[],[3]]時,不會遍歷到[3]
所以用 while(!qn.empty())描述
(2)是用來判斷, 如果在[[],[3]]情況時, 遍歷到[3]; 會至少有一個element在queue<int>中

public:
NestedIterator(vector<NestedInteger> &nestedList) {
    for(int i=0; i<nestedList.size(); ++i){
        qn.push(nestedList[i]);
    }
}
    
int next() {
    int ret = qi.front();qi.pop();
    return ret;
}
    
bool hasNext() {
    if(!qi.empty()) return true;
    while(!qn.empty()){//.....(1)
        NestedInteger nest = qn.front();qn.pop();

        dfs(nest,qi);
        if(qi.size()<=0) continue;//....(2)
    }  
    return (!qi.empty()); 
}

private:

void dfs(NestedInteger& nest,queue<int>& qi){
    if(nest.isInteger()){
        qi.push(nest.getInteger());
    } else {
        for(int i=0; i<nest.getList().size(); ++i){
            dfs(nest.getList()[i],qi);
        }
    }
}
queue<NestedInteger> qn;
queue<int> qi;

};



  
