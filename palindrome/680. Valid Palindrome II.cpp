//=======類似題 =====
681. Next Closest Time
2330. Valid Palindrome IV
1216. Valid Palindrome III

//===思路===
1.左(start)比右(right), 如果相等則
start++; right--; 左往後移一步,右往前移一步

2.如果不相等,依據題意,只可以忽略一次,可以忽略左邊,或忽略右邊=>忽略哪一邊可以滿足palindromic不知道,所以兩個都計算
(s,start+1,end)//忽略左邊,繼續比較
(s,start,end-1)//忽略右邊,繼續比較

while(start<end)=> 往內縮做比較
//==========
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
    
//===寫法2===
bool isPalindrome(string&s ,int l, int r){
    while(l<r){
        if(s[l]!=s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

bool validPalindrome(string s) {
    while(l<r){
        if(s[l]!=s[r]){
            if(isPalindrome(s,l+1,r)||isPaliindrome(s,l,r-1)) return true;
            else return false;
        }
    }
    return true;
}


    
