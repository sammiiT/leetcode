//===類似題===
1964. Find the Longest Valid Obstacle Course at Each Position
301. Remove Invalid Parentheses
1541. Minimum Insertions to Balance a Parentheses String

//===思路===
(*)用stack 資料結構解題
(*)只要證明, 有多少組不能配對, (組數+1)/2就是解
]]][[[ , 有3組不能配對, (3+1)/2就是解  

//=====
int minSwaps(string s) {
  stack<char> stk;
  int count = 0;
  for(char c:s){
      if(c=='['){
          stk.push(c);
      }else{
          if(!stk.empty() && c==']'){
              stk.pop();;
          }else{
              count++;
          }
      }
  }
  return count+1
}

int minSwaps(string s) {
    stack<char> stk;
    
    int count = 0;
    for(char c:s){
        int flag = 0;
        while(!stk.empty()&& (stk.top()=='[' && c==']')) {
            stk.pop();
            flag=1;
            break;//只刪除一個就好, 
        }
        if(!flag) stk.push(c);
    }
    return (stk.size()/2+1)/2;
}
