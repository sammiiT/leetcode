//=====類似題=====
132. Palindrome Partitioning II
1745. Palindrome Partitioning IV
2472. Maximum Number of Non-overlapping Palindrome Substrings

bool isPalindrome(string& s, int left, int right){
    while(left<right){
        if(s[left]!=s[right]) return false;
        left++;right--;
    }
    return true;
}


void helper0(string& s, int start, vector<string>& out, vector<vector<string>>& res){    
    if(start>=s.size()){
        res.push_back(out);
        return;
    }
    for(int i=start; i<s.size(); i++){
        if(isPalindrome(s,start,i)){
            out.push_back(s.substr(start,i-start+1));//進往下一階的,就是被選擇的element
            helper0(s,i+1,out,res);
            out.pop_back();
        }
    }    
}

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        helper0(s,0,out,res);
        return res;
    }
};
