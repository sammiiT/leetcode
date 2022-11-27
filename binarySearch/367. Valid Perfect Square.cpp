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
