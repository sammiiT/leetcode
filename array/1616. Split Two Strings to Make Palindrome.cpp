//====類似題=====
1617. Count Subtrees With Max Distance Between Cities
541. Reverse String II
752. Open the Lock
2227. Encrypt and Decrypt Strings

bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}

bool helper0(string a, string b){
    int i = 0;
    int j = a.size()-1;
    while(i<j && a[i]==b[j]){//a的前半段, b的後半段; 判斷是否palindrome
        i++;j--;
    }//跳出palindrome狀況
    
    //判斷兩個剩下的字串是否palindrome; 如果有一個是palindrome, 則滿足題目條件
    return isPalindrome(a,i,j)||isPalindrome(b,i,j);
}
bool checkPalindromeFormation(string a, string b) {
        return helper0(a,b)|| helper0(b,a);
}




//===== time limit exceeded=====
bool helper0(string a, string b, int idx){
    string s1 = a.substr(0,idx-0);
    string s2 = b.substr(idx, b.size()-idx+1);
    string s_merge = s1+s2;
    string s_reverse = s_merge;
    reverse(s_reverse.begin(),s_reverse.end());
    return (s_merge==s_reverse);
}
bool checkPalindromeFormation(string a, string b) {
    int n = a.size();
    if(a.size()==1) return true;
    for(int i=1; i<n-1; i++){
       if(helper0(a,b,i)||helper0(b,a,i)) return true;
    }
    return false;    
}
