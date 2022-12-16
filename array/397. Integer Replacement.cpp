//===類似題===
398. Random Pick Index
2328. Number of Increasing Paths in a Grid
1563. Stone Game V
1373. Maximum Sum BST in Binary Tree

//===思路=====
1.找出對應關係, 將關係公式實作
2.遍歷陣列, 每一個數除以4; 
整除: 代表可以一次移動兩個位置
餘1: 下一動作 -1 => 下一個數值就是4的倍數
餘2: 下一動作 /2 
餘3: 下一動作 +1 => 下一個數值就是4的倍數

如果陣列遇到3,上述公式會造成多一次計算:
3->4->2->1
所以, 遇到3要直接-1; 變成:
3->2->1
//====
int helper0(int m){
    int res =0;
    long n = m;
    while(n>1){
       if(n%4==3){//餘3
            if(n>4) n+=1;//數值大於4, n+1為4的倍數
            else n-=1;//當遇到數值等於3, 直接-1        
        }else if(n%4==1){//餘1
            n-=1;//-1後變成4的倍數    
        }else{
            n/=2;
        }
        res++;
    }
    return res;
}

int integerReplacement(int n) {
    return helper0(n);        
}

//====思路===

//====
int integerReplacement(long long n) {
  if(n==1){
    return 0;
  }else{
    if(n%2==0){
      return 1 + integerReplacement(n/2);
    }else{
      return 1 + min(integerReplacement(n-1),integerReplacement(n+1));
    }
  }
}



