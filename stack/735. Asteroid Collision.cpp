//====類似題====
736. Parse Lisp Expression
2126. Destroying Asteroids
2211. Count Collisions on a Road

//===思路===
(*)stack求解
1.(+)往右, (-)往左 所以 -1,-1,2,2 不會有 刪除發生
  [2,2,-1,-1] 會有刪除發生

2.如果asteroid存在, 最後會push到stack中; 等待下一個element跟stack中的top做比較

3.比較條件: 
!stack.empty() ; 要先判斷
top和asteroids[i]是異號; 少了此判斷會發生[-2,-2,-1,-5]=>[-2,-2,-5]; 1被刪除
stack.top要大於asteroids[i]  

4. 加上一exist的flag來判斷asteroid最後是否可以被push到stack中
exist = 0表示被collision
exist = 1表示存在

5.最後回傳stack中的數值即是解
//=======
vector<int> helper0(vector<int>& asteroids) {
    vector<int> stk;
//    stk.push_back(asteroids[0]);
    for(int i=0; i<asteroids.size(); i++){
        int exist = 1;
        while(!stk.empty() && stk.back()>asteroids[i] && ((stk.back()^asteroids[i])>>31)){//少了判斷符號相同,相異; 在[-2,-2,-1,-5]輸入, 會出錯
            if(stk.back()==abs(asteroids[i])){
                exist = 0;
                stk.pop_back(); //=> cause stack = 0
                break;
            } else if(stk.back()<abs(asteroids[i])){
                exist = 1;
                stk.pop_back(); //=> cause stack = 0

            } else if(stk.back()>abs(asteroids[i])){
                exist = 0;
                break;
            } 
        }
        if(exist) stk.push_back(asteroids[i]);
    }
    return stk;
}
vector<int> asteroidCollision(vector<int>& asteroids) {
    return helper0(asteroids);
}
