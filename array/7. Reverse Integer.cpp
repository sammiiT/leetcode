    int helper0(int x){
        
        long i = x, j = 0;
        long div = 1;
        
        while(abs(x/div) >=10) div = div*10;
        
        while(div>0){
           
            j = j + (i%10)*div;//(i%10) 得到 + or -
            i = i/10;
            div = div/10;
        }
    
        return (j > INT_MAX || j < INT_MIN) ? 0 : j;//沒有此行會錯誤
//        return j;
    }
    
    int reverse(int x) {
        return helper0(x);
    }
