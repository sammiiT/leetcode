//===類似題===
1696. Jump Game VI
1373. Maximum Sum BST in Binary Tree
1380. Lucky Numbers in a Matrix

//===思路====

int getMaxLen(vector<int>& nums) {
  int positive = 0;
  int negative = 0;
  int res =0;

  for(int num:nums){
      if(num==0){
          positive = 0;
          negative = 0;
      }else if(num>0){
          positive+=1;
          negative = (negative==0)?0:negative+1;
      }else{//num<0
          int temp = positive;
          positive = (negative==0)?0:negative+1;
          negative = temp+1;
      }   
      res = max(res,positive);
  }
  return res;

}






//===不好算====
/*
1.紀錄每一個區段的negative index
- 區段:0和0之間的subarray; 紀錄每一個區段的起始,結束位址(不包含0)
- negative數量為偶數, 回傳區段全部個數 
- negative數量為奇數, 比較區段個數, 共三段

    p p p N p p N p p p N p
    |-----------|---------|


            正數第二         倒數第二
    p p p p N p N p p N p p p N p p p p N p
    |-------------------------|-----------|
    |-----------|-------------------------|

*/
