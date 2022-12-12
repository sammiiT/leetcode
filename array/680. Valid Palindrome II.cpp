//=======類似題 =====
681. Next Closest Time
2330. Valid Palindrome IV
1216. Valid Palindrome III

bool checkPalindrome(string& s, int start, int end){
    while(start<end){
        if(s[start]!=s[end]) return false;
        start++;end--;
    }
    return true;
}

bool helper0(string& s){
    int start = 0, end = s.size()-1;//從最外面往內開始找答案
    while(start<end){
        if(s[start]!=s[end]){//第一次發生錯誤
                    //左邊跳一格,繼續找                //右邊跳一格,繼續找 ===> 如果只出錯一次, 就回傳true
            return checkPalindrome(s,start+1,end) || checkPalindrome(s,start,end-1);    
        }else{
            start++;end--;
        }
    }
    return true;
}


bool validPalindrome(string s) {
        return helper0(s);
}
