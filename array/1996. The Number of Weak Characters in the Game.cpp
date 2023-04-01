//===類似題===
1997. First Day Where You Have Been in All the Rooms
354. Russian Doll Envelopes
1691. Maximum Height by Stacking Cuboids
//===思路===
1.排序數列
- a[0]: attack以descending模式(attack優先做考慮), 若attack數值相等,再以defense作排列
- a[1]: defense以acending模式

2.遍歷數列,比較a[1] defense, 如果a[i][1]<mx, 則代表 weak
技巧, i=0開始,建立初始值
if([i]<mx){//一開始的maximum絕對不會大於陣列中的每一個數值
  
}else{
    mx=max(mx,[i]);// i==0時, 建立maximum初始值, 以[i]為初始值
}


(*)不能用stack. 因為stack方法會比較所有過去的情況, 且會之前的情況排除
沒辦法做跳躍式比較;如
(1,1)  (1,2)  (2,1)  (2,2) (3,4)
如果比較a[1], 且條件為top()<=a[1], (2,2)會把(1,1),(1,2),(2,1)全部排除
top()<a[1]; 則(2,2)無法與(1,1)相比

//======
int numberOfWeakCharacters(vector<vector<int>>& properties) {
  int maxdefense = 0;
  int res = 0;
  
  //sort(properties.begin(),properties.end(),[](vector<int> a, vector<int> b){//如果不是傳"參考",會造成time limited exceeded 
  sort(properties.begin(),properties.end(),[](vector<int>& a, vector<int>& b){
      if(a[0]!=b[0]) return a[0]<=b[0];
      return a[1]>=b[1];
  });
  
  for(int i=0;i<properties.size();++i){
      if(properties[i][1]<maxdefense){
          ++res;
      }else{//properties[i][1]>=maxdefense
          maxdefense = max(maxdefense,properties[i][1]);
      }
  }
  return res;
}


//====failed
int numberOfWeakCharacters(vector<vector<int>>& properties) {
    stack<int> stk;//index
    int res = 0;
    
    sort(properties.begin(),properties.end(),[](vector<int> a,vector<int> b){
        return a[0]<b[0];    
    });
    
    for(int i=0; i<properties.size(); ++i){
        while(!stk.empty() && properties[stk.top()][1]<properties[i][1]) {
            stk.pop();
            ++res;
        }
        stk.push(i);
    }
    return res;        
}
