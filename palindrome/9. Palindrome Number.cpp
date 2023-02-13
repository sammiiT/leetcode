//====類似題=====
10. Regular Expression Matching
2217. Find Palindrome With Fixed Length
2396. Strictly Palindromic Number
//===思路===
(*) 計算此數是10的幾次方.
while(x/div>=10) div=div*10;
最後的div就是x的 次方數.

//===
bool helper2(int x){
        long count = x;
        long y = 0;
        if(x<0) return false;
        while(count>0){
            y = y*10 + count%10;//將每一次最低位的數,往前推;最後palindrome
            count/=10;        
        }
        return (y==x)?true:false;
}


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
            int left =  x/div;//最大位的數
            int right = x%10;//最小位的數
            if(left!=right) return false;//如果兩個不相等,回傳false
            x = x%div;//移除最高位
            x = x/10;//移除最低位
            div = div/100;//移除兩位,所以要除100
        }
        return true;
    }
    
    
bool isPalindrome(int x) {
        return helper0(x);
//        return helper1(x);
}
