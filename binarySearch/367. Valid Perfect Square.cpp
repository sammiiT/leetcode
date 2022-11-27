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














