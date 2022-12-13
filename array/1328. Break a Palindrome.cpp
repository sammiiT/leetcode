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
