//===類似題===
1190. Reverse Substrings Between Each Pair of Parentheses
2027. Minimum Moves to Convert String
387. First Unique Character in a String
1636. Sort Array by Increasing Frequency

//===思路===

//====
string s = "balloon";
int helper0(string text){
        int valid = 1,res = 0;
        unordered_map<char,int> bmp;//紀錄balloon每一個字元出現的次數
        unordered_map<char,int> tmp;//紀錄text出現balloon的每一個字元的次數
        
        for(int i=0;i<s.size();i++) bmp[s[i]]++;//紀錄balloon每一個字元出現的次數
        for(int i=0;i<text.size();i++){//紀錄text出現balloon的每一個字元的次數
            if(bmp.count(text[i]))
                tmp[text[i]]++;    
        }

        while(valid){//比對balloon出現的次數
            for(auto a:bmp){//balloon是否可以完整拼出
                tmp[a.first]-=a.second;
                if(tmp[a.first]<0){//如果有一個字元無法完成
                    valid=0;//flag跳出迴圈    
                    break;
                } 
            }
            if(valid==1) res++;//可以完全比對balloon, 紀錄一次
        }
        return res;
}
int maxNumberOfBalloons(string text) {
        return helper0(text);
}
//======
 int maxNumberOfBalloons(string text) {
        int res = INT_MAX;
        string balloon = "balloon";
        unordered_map<char, int> charCnt;
        for (char c : text) ++charCnt[c];//紀錄每一個字元,不用管是不是balon其中之一, 因為最後比較只會比balon這幾個
        
        for (char c : balloon) {//只遍歷一次, 每一個字元出現的次數都取最小值
            if (c == 'l' || c == 'o') res = min(res, charCnt[c] / 2);
            else res = min(res, charCnt[c]);
        }
        return res;
}

