//====類似題=====
2109. Adding Spaces to a String
539. Minimum Time Difference
353. Design Snake Game
1425. Constrained Subsequence Sum


bool isPalindrome(string s){
        int left =0, right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++; right--;
        }
        return true;
    }

    string helper0(vector<string>& words){
        string res;
        for(string& a:words){
            if(isPalindrome(a)){
                res = a;
                break;
            }        
        }
        return res;
    }

    string firstPalindrome(vector<string>& words) {
        return helper0(words);
    }
