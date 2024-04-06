//=====類似題=====
6. Zigzag Conversion
336. Palindrome Pairs
266. Palindrome Permutation
214. Shortest Palindrome

//===思路1===
(*)遍歷所有解;雙迴圈;用往內縮的方式做比較
i         <-j   => 比對i~j是否為palindrome
o  o  o  o  o   => (i,j);(i,j-1);(i,j-2)... 

   i      <-j
o  o  o  o  o   => 比對i~j是否為palindrome      
//====
bool check_palindrome(string& s,int left, int right){
    while(left<right){
        if(s[left]!=s[right]) return false;
        left++;right--;
    }
    return true;
}
string helper2(string s){
    int mx = 0;
    string res;
    for(int i=0; i<s.size(); i++){//i從0開始,到
        for(int j=s.size()-1; j>=i; j--){
            if(check_palindrome(s,i,j)){
                if(mx<(j-i+1)){
                    mx = (j-i+1);
                    res = s.substr(i,mx);
                }
            }
        }
    }
    return res;
}
//===思路2===
void isPalindrome(string s, int left, int right, string& res){
    int n = s.size();
    while(left>=0 && right<=(n-1)){
//        if(s[left]!=s[right]) return;//wrong;不可以用return不然會記錄不到中間的palindrome
                                       //"cbbd"   有bb,但遇到cd, return了, 就沒辦法紀錄bb
        if(s[left]!=s[right]) break;
        left--; right++;
    }
    if((right-left-1)>res.size()){
        res=s.substr(left+1,(right-left-1));
    }    
}
string helper3(string s){
    string res;
    if(s.size()<=1) return s;
    for(int i=0;i<s.size()-1;i++){
        isPalindrome(s,i,i,res);
        isPalindrome(s,i,i+1,res);
    }
    return res;
}
//======
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

//===寫法3 ====
(*)判斷palindrome長度, 由中心點往外部擴散, 找出最大長度
(*)判斷是否為palindrome, 從兩端點往內移動判斷每一對應點是否相等
(*) 此題方式為第一種, 由中心往外擴
   
string ispPalindrome(string& s, int l, int r){//left start from "l", right start from "r"
    int len =0;
    string ret;
    while(l>=0 && r<s.size()){
        if(s[l]!=s[r]) break;
        len = r-l+1;
        l--;
        r++;
    }
    return len?s.substr(++l,len):ret;
}
string longestPalindrome(string s) {
        string res;
        if(s.size()==1) return s;
        for(int i=0; i<s.size()-1; ++i){
            string str_a = ispPalindrome(s,i,i);//輸出palindrome
            string str_b = ispPalindrome(s,i,i+1);//輸出palindrome
           
            if(str_a.size()>str_b.size()) {//比較palindrome長度
                res = (str_a.size()>res.size())? str_a:res;
            } else {
                res = (str_b.size()>res.size())? str_b:res;
            }   
        }
        return res;
}
