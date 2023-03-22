//===類似題===
1415. The k-th Lexicographical String of All Happy Strings of Length n
757. Set Intersection Size At Least Two
1405. Longest Happy String
2197. Replace Non-Coprime Numbers in Array
//===思路===
(*)Greedy概念,每次都取可以讓K趨近於0的數
-有多少,用多少 
-有多大,選多大

1.建立fibonacci數列, 並將每一個(<k)數值推入priority_queue<int>中
2.將priority_queue<int>中的數值依序pop出來
- pq.top() 如果(>0) update 剩下的值,再繼續往下找
- pq.top() 如果(==0) return 解
- pq.top() 如果(<0) continue;


//====
int findMinFibonacciNumbers(int k) {
    priority_queue<int> pq;
    int f2=1,f1=1;
    int cnt=0;

    pq.push(f1);
    pq.push(f2);
    //for(;f2<=k;){}
    do{
        int t = f2;
        f2 = f2 + f1;
        f1 = t;
        if(f2<=k) pq.push(f2);
    }while(f2<=k);

    while(!pq.empty()){
       int r = k-pq.top();
       if(r>0){
           k = r;
           cnt++;
           pq.pop();
       }else if(r<0){
           pq.pop();
       }else{//r==0;
        cnt++;
        pq.pop();
        break;     
       }
    }
    return cnt;
}

//=== fibonacci數列 ===

Fa = Fb + Fc 
F3 = F2 + F1
  \    \__
   \__    \
F4 = F3 + F2
  \    \__
   \__    \
F5 = F4 + F3
  \    \__
   \__    \
F6 = F5 + F4

(*)只有兩個變數, f1,f2 ;  f2 = f2+f1;
(*)先記錄Fb, 因為Fb是下一個Fc
- int t = f2;

(*)Fa是下一個Fb
- f2 = f2 + f1;

(*)指派下一次運算的 Fc
- f1 = t;
- f2在之前有計算過了; f2 = f2+f1;

vector<int> fibonacci(int n){//n從1開始
  vector<int> res(2,1);
  int f1 = 1;
  int f2 = 1;
  for(int i=3; i<=n; i++){
      int t = f2;//先記錄f(n-1), 他會是下一個f(n-2) 
      f2 = f2 + f1;//計算過後的f2是下一個數字的f(n-1)
      res.push_back(f2);
      f1 = t;//下一個數字個f(n-2)
  }
  return res;
}
