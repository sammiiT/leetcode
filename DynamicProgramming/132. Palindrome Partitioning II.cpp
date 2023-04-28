//===類似題===

//===思路====
(*)Dynamic programming


//=====


//===用DFS會Time Limited Exceeded ===
bool isPalindrome(string& s, int left, int right){
    while(left<right){
        if(s[left]!=s[right]) return false;
        left++;right--;
    }
    return true;
}
void helper(string& s,int start, vector<string>& out, int& res){
    if(start>=s.size()){
        res = min(res, (int)out.size()-1);
    }

    for(int i=start; i<s.size(); ++i){
        if(isPalindrome(s,start,i)){
            out.push_back(s.substr(start,i-start+1));
            helper(s,i+1,out,res);
            out.pop_back();
        }
    }
}

    int minCut(string s) {
        int res = s.size()-1;
        vector<string> out;
        helper(s,0,out,res);
        return res;    
    }
