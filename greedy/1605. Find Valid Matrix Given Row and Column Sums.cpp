//===類似題===
1570. Dot Product of Two Sparse Vectors
1253. Reconstruct a 2-Row Binary Matrix

//===思路====
(*) Greedy
- 但此題是要取兩數中最小的那一個 min

1.建立vector<vector<int>>二維陣列
2.遍歷rowSum和colSum
-取rowSum[i]或colSum[j]最小的那一個

rowSum = [5,7,10], colSum = [8,6,8]

    /--grid[0][0],                             /--決定grid[0][0]=5
   /  比較rowSum[0]和colSum[0],取min=5;        /  rowSum[0]-=min; colSum[0]-=min
  O   O   O  5                                5   O   O   0                            
  O   O   O  7                                O   O   O   7
  O   O   O  10                               O   O   O   10 
  8   6   8                                   3   6   8
    
    
        /--grid[0][1]                              /--grid[0][1]=0
       / 比較rowSum[0]和colSum[1],取min=0          / rowSum[0]-=min; colSum[0]-=min
  5   O   O  0                                5   0   O  0
  O   O   O  7                                O   O   O  7
  O   O   O  10                               O   O   O  10 
  3   6   8                                   3   6   8
    
=> 5 0 0   
   3 4 0 
   0 2 8  
 
    
//=====
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size(), n = colSum.size();
    vector<vector<int>> res(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int a = min(rowSum[i],colSum[j]);        
            res[i][j] = a;
            rowSum[i]-=a;
            colSum[j]-=a;
        }
    }
    return res;
}

//======================


vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
  int m = rowSum.size(), n = colSum.size();
  vector<vector<int>> res(m,vector<int>(n));
  int i=0;j=0;
//while(i<m || j<n){
  while(i<m && j<n){
      res[i][j]=min(rowSum[i],colSum[j]);
      if(rowSum[i]<colSum[j]){
          colSum[j]-=rowSum[i];
          i+=1;
      }else if(rowSum[i]>colSum[j]){
          rowSum[i]-=colSum[j];
          j+=1;
      }else{//rowSum[i]==colSum[j]
          i+=1;
          j+=1;
      }
  }
  return res;
}








