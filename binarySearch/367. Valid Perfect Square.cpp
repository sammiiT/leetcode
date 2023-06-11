//===類似題===
368. Largest Divisible Subset
1250. Check If It Is a Good Array
1716. Calculate Money in Leetcode Bank
651. 4 Keys Keyboard
//===思路===
(*)binary search

(*)左極限=1到右極限num, 遞增數列
(*) 判斷範圍  while(l<r) =>最後若回傳右極限 r=num
(*)取中間值並求對應的平方數
- 如果平方數小於num , 則選擇的數值太小, 需往遞增的方向增加 l = m+1
- 如果平方數大於等於num , 則選擇的數值太大, 需往遞減的方向 r = m;
- 如果最後得到的數值再算一次平方, 判斷是否為num, 如果是, 則true, 否 回傳false

//======
bool isPerfectSquare(int num) {
    long l=1,r=num;
    while(l<r){
        long m = l+(r-l)/2;
        if(m*m<num) l=m+1;
        else//m*m>=target
            r = m;
    }
    return (r*r==num);
}

//========
bool isPerfectSquare(int num) {
        long l = 1, r = num;
        while(l<=r){//target是num  
            long m = l+(r-l)/2;
            if(m*m < num){
                l = m+1;
            
            }else if(m*m > num){
                r = m-1;//用l<=r必須在 r做運算時, r=m-1;
            
            }else {//m*m == num;有找到
                return true;
            }   
        }
        return false;
}
//==================================
bool isPerfectSquare(int num){
        for(int i=1; i<=num/i; i++){
                if(i*i==num) return true;
        }
        return false;
}
//==================================
bool isPerfectSquare(int num){
        if(num==1) return true;
        long x = num/2, t= x*x;
        while(t>num){
                x/=2;
                t = x*x;
        }
        for(int i=x; i<=2*x; ++i){
           if(i*i==num) return true;                
        }
       return false;
}














