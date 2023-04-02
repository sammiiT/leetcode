//===類似題===
1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
340. Longest Substring with At Most K Distinct Characters
2195. Append K Integers With Minimal Sum
2430. Maximum Deletions on a String

//===思路===

(*) 變數 left, 單獨的'('個數

int minInsertions(string s) {
  int left = 0;
  int res = 0;
  for(int i=0;i<s.size();++i){
      char c = s[i];
      if(c=='(') left++;
      else{//c==')'
          if((i+1)<s.size() && s[i+1]==')'){
              if(left) --left;//刪減一個'('來滿足balance
              else{
                  ++res;//新增一個'('來滿足balance
              }
              ++i;//因為考慮 s[i+1], 所以要跳一個index
          }else{
              if(left){
                  --left;//刪減一個'('來滿足balance
                  ++res;//新增一個')'來滿足balance
              }else{
                  res+=2;//新增一個'(',新增一個')'來滿足balance
              }
          }
      }
  }
  res = res + 2*left;//剩下單獨的left必須用2個')'來滿足balance;
  return res;
}






//===思路2===
(*)用stack來做, 但有bug., 待解
string s6 = "))())())()())()))()))))(()))())))))(()()())()())((()())))()";  

int check(vector<char>& arr){
    vector<char> stk;
    int res =0;
    int cntl = 0;//(
    int cntr = 0;//)
    for(int i=0; i<arr.size(); ++i){
        int flag=0;
        while(!stk.empty() && (stk.back()=='('&&arr[i]==')')){  
            res+=1;
            --cntl;
            stk.pop_back();
            flag = 1;
            break;
        }
        if(!flag) {
            stk.push_back(arr[i]);
            if(arr[i]=='(') cntl++;
            else if(arr[i]==')') cntr++;
        }
    }
    res += 2*cntl;
    res += cntr/2;
    res += (cntr%2)*2;
    return res;    
}
int helper(string s) {
    int ready = 0;    
    int n = s.size();
    vector<char> stk;
    
    for(int i=0;i<n; ++i){
        if(ready && s[i]==')'){
            stk.pop_back();
            stk.pop_back();
            ready =0;
            continue;
        }else{
            ready = 0;
        }
        while(!stk.empty() && (stk.back()=='(' && s[i]==')')){
            ready = 1;//ready代表有()存在
            break;
        }
        stk.push_back(s[i]);
    }
    return check(stk);
/*    printArray(stk);
    cout<<"insert = "<<check(stk)<<endl;
    return stk.size()==0?true:false;*/
}
