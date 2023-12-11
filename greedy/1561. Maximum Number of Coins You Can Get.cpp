//===類似題===
1562. Find Latest Group of Size M
1551. Minimum Operations to Make Array Equal
473. Matchsticks to Square
507. Perfect Number

//===思路===
(*)Alice最先取(max), 我第二取(max), Bob取最小的(min)
(*) Greedy算法,有多少拿多少
1.陣列排序, 從pile的coin數少到coin數多
2. 根據題意: 一次取三個, 後面取兩個, 前面取一個

第一次:
                       我取
Bob取                   |    /--Alice取
 |                     /   / 
 1  2  3  4  5  6  7  8  9
    
      Alice 我    Bob                   
第一次[9,    8,    1]
第二次[7,    6,    2]
第三次[5,    4,    3]
=> 我取總數 18

//====
 int maxCoins(vector<int>& piles) {
    sort(piles.begin(),piles.end());
    int i=0, j=piles.size()-1;//i往右->, j往左<-
    int res = 0;
    while(i<=j-2){//j和i的的關係須滿足
        res+=piles[j-1]; //j-1是"我"取的位置       
        j=j-2;//每次j update
        i=i+1;//每次i update
    }
    return res;
}                        
//==============                         
int maxCoins(vector<int>& piles) {
    int res = 0;
    int n = piles.size();
    int l = 0, r = n-1;
    sort(piles.begin(),piles.end());
    r--;
    while(l<r){
        res+=piles[r];
        ++l;
        r-=2;
    }
    return res;
}

//===寫法2====
int maxCoins(vector<int>& piles) {
    int a, b, m;//index
    int res = 0;
    int remain = piles.size();
    sort(piles.begin(),piles.end());
    
    a = piles.size()-1;//一開始alice的index
    b = 0;//一開始bob的index
    
    while(remain){
        m = a-1;//me 取的index
        a = m-1;//下一次 alice的index
        b +=1; //bob 下一次的index
        remain-=3;
        res += piles[m];
    }
    return res;        
}





