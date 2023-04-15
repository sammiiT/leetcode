//===類似題====
1298. Maximum Candies You Can Get from Boxes
1770. Maximum Score from Performing Multiplication Operations
2091. Removing Minimum and Maximum From Array
//===思路====
(*)prefix sum
-先算好從第"0"數字到第"j"數字的和
-可以利用此prefix_sum計算i~j的總和
 0  1 2 3 4  
[12,3,4,5,6] => 0~3和 => 12,15,19,24  => 24 

1~3和 =>(24-12)   
2~3和 =>(24-15)
  
  
(*)  
               V 
數列: a, b, c, d, e, d, g
1.先計算 a~d總和

2.從d開始減, 變成選取的數列為 a,b,c, ...  g
3.刪除c, 變成選取的數列為 a,b, ...  d,g
4.依照此操作, 算出每次的maximum ,最後的maximum即為解

//=====
int helper(vector<int>& cardPoints, int k){
    int n = cardPoints.size();
    int sum = accumulate(begin(cardPoints),begin(cardPoints)+k,0);
    int res = sum;

    for(int i=0; i<k; ++i){
        sum = sum - cardPoints[k-1-i]+cardPoints[n-1-i];
        res = max(res,sum);
    }
    return res;
}

    int maxScore(vector<int>& cardPoints, int k) {
        return helper(cardPoints,k);
    }
