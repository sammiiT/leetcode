//===類似題===
264. Ugly Number II
204. Count Primes
//===思路===
(*) 計算一個數是否可以整除 n ; 則
(x%n==0) , 對n取餘數等於零, 代表x有n的因數
//=======
bool helper0(int n){
     while(n>1){
        if(n%2==0){
            n/=2;
        }else if(n%3==0){
            n/=3;
        }else if(n%5==0){
            n/=5;
        }else {
            break;        
        }
    }
    return (n==1)? true: false; 
}
bool isUgly(int n) {
    return helper0(n);
}

//===寫法2===
bool isUgly(int n) {
        int tmp = n;
        int flag=0;
        if(tmp==1) return true;
        if(tmp==0) return false;
        for(;;){//while(tmp){
            flag = 0;
            if(tmp%2==0) {tmp/=2; flag=1;}
            if(tmp%3==0) {tmp/=3; flag=1;}
            if(tmp%5==0) {tmp/=5; flag=1;}
            
            if(flag==0) return false;
            if(tmp==1) return true;
            else if(tmp==-1) return false;
        }
        return false;
}

//===寫法2優化===
bool isUgly(int n) {
    int flag = 0;
     
    while(n>1){
        flag = 0;
        if(n%2==0) {
            n/=2;  flag=1; }
        if(n%3==0){
            n/=3; flag=1; }
        if(n%5==0){
            n/=5; flag=1; }
        
        if(flag==0) break; 
    }
    return (n==1)?true:false;
}
