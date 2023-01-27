//====類似題===
2119. A Number After a Double Reversal
336. Palindrome Pairs

int helper0(vector<string>& words){
        vector<vector<int>> m(26,vector<int>(26));
        int res = 0;
        for(string& a:words){
            int i=a[0]-'a';
            int j=a[1]-'a';
            if(m[i][j]){//發生i=j的情況也可以記錄, 但i=j的情況要發生兩次,才能在這邊做運算;不然就是在下一個描述中做運算
                --m[i][j];
                res+=4;        
            }else{
                ++m[j][i];
            }
        }
        for(int i=0;i<26;i++){
            if(m[i][i]) {
                res+=2;
                break;
            }
        }
        return res;
}

int longestPalindrome(vector<string>& words) {
        return helper0(words);
}      
