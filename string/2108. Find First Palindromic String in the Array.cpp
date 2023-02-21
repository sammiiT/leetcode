//===類似題===
2109. Adding Spaces to a String
1765. Map of Highest Peak
1977. Number of Ways to Separate Numbers
794. Valid Tic-Tac-Toe State
//===思路===

//======
bool isPalindrome(string s){
    int left =0, right=s.size()-1;
    while(left<right){
        if(s[left]!=s[right]) return false;
        left++; right--;
    }
    return true;
}
string firstPalindrome(vector<string>& words) {
    string res;
    for(string& a:words){
        if(isPalindrome(a)){
            res = a;
            break;
        }        
    }
    return res;
}
