//====類似題=====
1329. Sort the Matrix Diagonally
248. Strobogrammatic Number III
1784. Check if Binary String Has at Most One Segment of Ones
2412. Minimum Money Required Before Transactions

void helper0(string& s){
//	int m = (s.size()-1)/2;//first middle會錯誤;出現aba轉換成aaa; 不滿足題目條件,換成second middle
/*
      V
o  o  o  o  o  second middle (odd)
  
      V
o  o  o   o   second middle (even)
*/  
  
  int m = s.size()/2;
	int flag=1;	
	for(int i=0; i<m; i++){
		if(s[i]!='a'){ 
		    s[i]='a';
		    flag=0;
            break;
		}
	}
	if(flag){//找不到,最後一個才置換成b
	   s[s.size()-1]='b';	
	}
}

    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1) return "";
        helper0(palindrome);
        return palindrome;
    }
};

//========================================
helper0修改
string breakPalindrome(string palindrome) {
    const int n = palindrome.length();
    if (n == 1) return "";
    for (int i = 0; i < n / 2; ++i) {
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;//如果出現不為a的數, 修改後直接返回
      }
    }
    palindrome.back() = 'b';
    return palindrome;
}
//========================
void helper1(string& s){
    int m = s.size()/2;//second-middle計算, 可以運算到前半段
    int i;
    for(i=0; i<m; ++i){
    	if(s[i]!='a') { 
	    s[i]='a';
	    break;
	}
    }
    if(i==m) s[s.size()-1] = 'b';
}
