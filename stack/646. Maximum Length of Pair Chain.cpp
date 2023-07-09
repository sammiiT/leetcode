//===類似題====
647. Palindromic Substrings
491. Non-decreasing Subsequences
//===思路====
(*) 題目被列為greedy, 但用到stack資料結構做運算
1.先將鏈表作排列, 依據尾端的數值作排列,從小到大
[1,9] [3,5] [7,8] => [3,5] [7,8] [1,9]

2.遍歷pairs鏈表, 並依據下列條件,將對鏈push至stack中
- 如果遍歷到對鏈的[0]大於stack.top的[1];則將此對鏈push到stack
- 若否, 則不push

[3,5] [7,8]                       [7,8] [1,9]            
  |      \                          |     \
  \       遍歷的對鏈[0] =7           \      遍歷的對鏈[0] =1
   stack.top()[1]= 5                 stack.top()[1]= 8
 =>[7,8]push到stack中              => [1,9]捨棄 
  
  
3.在stack中的對鏈即為解

(*)如果用[0]作排列, 則錯誤, 因為[1]有可能非常大, 大於接下來數列的每一個[0]
[[-6,9],[1,6],[8,10],[-1,4],[-6,-2],[-9,8],[-5,3],[0,3]]
=> [-9,8],[-6,9],[-6,-2],[-5,3],[-1,4],[0,3],[1,6],[8,10]
[0]=-9最小, 但[1]=8 會大於接下來的每一個[0]

所以用[1]作為排列依據  
  
//=====
int findLongestChain(vector<vector<int>>& pairs) {
    stack<vector<int>> stk;
    sort(pairs.begin(),pairs.end(),[](vector<int> a, vector<int> b){return a[1]<b[1];});
    for(vector<int> x: pairs){
        if(stk.empty()){
            stk.push(x);
        }else{
            vector<int> t =stk.top();
            if(t[1]<x[0]) stk.push(x);
        }
    }
    return stk.size();
}
