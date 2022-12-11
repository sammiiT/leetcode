//====類似題=====
266. Palindrome Permutation
2131. Longest Palindrome by Concatenating Two Letter Words
2384. Largest Palindromic Number
410. Split Array Largest Sum

int helper(string s){
        unordered_map<char,int> m;
        int res = 0;
        int add1 = 0;
        for(int i=0;i<s.size();i++) m[s[i]]++;//紀錄每一個letter出現的數目
        for(auto a:m){
            res += a.second;
            if(a.second%2==1){//如果是奇數,將多餘的1減掉,中間的那一個最後再加回去
                res--;
                add1 = 1;
            }
        }
        return (add1)?(res+1):res;        
}
    
int longestPalindrome(string s) {
        return helper(s);
}
