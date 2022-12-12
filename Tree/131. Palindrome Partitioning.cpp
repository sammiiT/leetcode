//===類似題=====
132. Palindrome Partitioning II
1745. Palindrome Partitioning IV
2472. Maximum Number of Non-overlapping Palindrome Substrings

bool isPalindrome(string& s, int start, int end){
        while(start<end){
            if(s[start]==s[end]){
                start++;end--;
            } else {
                return false;
            } 
        }
        return true;
} 

void helper0(string&s , int start, vector<string>currentList, vector<vector<string>>& res){
        if(start>=s.size()){
            res.push_back(currentList);
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(isPalindrome(s,start,i)){//固定start
                currentList.push_back(s.substr(start,i-start+1));
                helper0(s, i+1,currentList,res);
                currentList.pop_back();
            }
/*            else{
                break;//"efe"=> 不能break
                在固定e時, f出現, 發生break, 則不會再往下一個e執行=> 發生錯誤
            }*/
        }
}

vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currentList;
        helper0(s, 0, currentList, res);
        return res;        
}
