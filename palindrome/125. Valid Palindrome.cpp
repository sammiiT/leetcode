//===相似題===
126. Word Ladder II
2002. Maximum Product of the Length of Two Palindromic Subsequences
2330. Valid Palindrome IV

//====思路===
(*)座標轉換取餘數
+32   => 往上平移到'a'的基準, 
-'a'  => 相對於'a', 是第幾個. 互相對應數值
%32   => 目的是為了從0開始定義

//===
bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        
        while(left<right){
            if(!isAlphaNum(s[left])) left++;
            else if(!isAlphaNum(s[right])) right--;
            else if((s[left]+32-'a')%32!=(s[right]+32-'a')%32) return false;
/*//座標轉換取餘數,
+32 是因為A的數值是65, 如果減去'a'=97會變成負值
'A'-'a' = 65-97=(-32)
加上32之後 'A'-'a'= 0; 大寫減去'a',就不會變成負數
*/
            else {
                left++; right--;//遇到非字母的character
            }
        }
        return true;
    }
    
    bool isAlphaNum(char &ch){
        if(ch>='a' && ch<='z') return true;
        if(ch>='A' && ch<='Z') return true;
        if(ch>='0' && ch<='9') return true;
        return false;
    }
