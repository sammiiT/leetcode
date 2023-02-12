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
