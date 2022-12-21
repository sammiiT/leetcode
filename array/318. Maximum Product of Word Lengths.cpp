//===類似題===
319. Bulb Switcher
2037. Minimum Number of Moves to Seat Everyone
2282. Number of People That Can Be Seen in a Grid
721. Accounts Merge

//====思路===
1.因為有26個英文字母, 每一個string都可以用一個32 bit integer來代表; 每一個bit位址都可以代表一個出現的小寫字母 
2.每一個string 轉換為integer之後, 跟所有的string做比較, 求出length相乘的最大值
3.如果兩個intger 做"&"為0, 代表沒有重複的字母.

//========
int helper0(vector<string>& words){
        int res = 0;
        vector<int> mask(words.size(),0);
        for(int i=0; i<words.size(); i++){
            for(auto x:words[i]){
                mask[i] = mask[i] | (1<<(x-'a'));//每一個string都可以用一個32 bit integer來代表
            }
            for(int j=0; j<i; j++){//brute force比較
                if(!(mask[i]&mask[j])){//如果兩個intger 做"&"為0, 代表沒有重複的字母.
                    res = max((int)(words[i].size()*words[j].size()),res);
                }        
            }
        }
        return res;
}

int maxProduct(vector<string>& words) {
        return helper0(words);
}
