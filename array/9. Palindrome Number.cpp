    bool helper0(int x){
        
        long i = x, j=0;//int會出錯,要用long
        int div = 1;//計算order
        if(x<0) return false;
        
        //calculate order
        while(x/div >= 10) div = div*10;
  
        while(div>0){
            j = j + (i%10)*div;//最低位數是j的最高位數.    
            i = i/10;
            div = div/10;
        }
        
        if(j==x) return true;
        return false;
    }

    bool helper1(int x){
        int div = 1;
        if(x<0) return false;        
        
        //calculate order
        while(x/div >= 10) div = div*10;
        
        while(div>0){//loop {
            int left =  x/div;
            int right = x%10;
            if(left!=right) return false;
            x = x%div;//移除最高位
            x = x/10;//移除最低位
            div = div/100;
        }
        return true;
    }
    
    
    bool isPalindrome(int x) {
        return helper0(x);
//        return helper1(x);
    }
