//=====類似題=====
6. Zigzag Conversion
336. Palindrome Pairs
266. Palindrome Permutation
214. Shortest Palindrome


void checkPalindrome(string&s ,int left, int right, int& mx, int& start){
        int l = left,r = right;
        while(left<right){
            if(s[left]!=s[right]) return; 
            left++;right--;
        }
        if(mx<r-l+1){
            start = l;
            mx = r-l+1;
        }
/* 用計算過的left和right; 所以一定錯        
if(mx < right-left+1){
            mx = right-left+1;
            start = left; 
}*/
/*不用if區隔, 後面的palindrome 會覆蓋到前面的palindrome*/        
//        mx = max(right-left+1, mx);
//        start = left;
    }

    string helper0(string s){
        int n = s.size();
        int mx=1,start=0;
        for(int i=0; i<n; i++){//i = left
            for(int j=i+1; j<n; j++){//j = right
                checkPalindrome(s, i, j, mx, start);       
            }
        }
        return s.substr(start,mx);
    }
    string longestPalindrome(string s) {
        
        return helper0(s);
    }
