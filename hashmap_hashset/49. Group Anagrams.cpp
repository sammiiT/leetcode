//===類似題===
50. Pow(x, n)
249. Group Shifted Strings
2273. Find Resultant Array After Removing Anagrams
2514. Count Anagrams

//===思路===
(*)用unordered_map的方式
1. 定義 unordered_map<string,vector<int>>
string是函式輸入的每一個元素(且經過排列), vector<int> 是紀錄每一個有相同anagrams的位址
2.遍歷陣列, 每一個string經排列後,滿足anagrams的條件則加入map中
3.遍歷map, 將每個相同anagram的位址組合成一個vector<string>; 再push到解中

//=========
vector<vector<string>> helper1(vector<string>& strs){
    vector<vector<string>> res;
    unordered_map<string,vector<int>> m;
    
    for(int i=0; i<strs.size(); i++){
        string s = strs[i];
        sort(s.begin(),s.end());
        m[s].push_back(i);
    }
    for(auto a: m){
        vector<int> t = a.second;
        vector<string> s;
        for(int i=0;i<t.size();i++)
            s.push_back(strs[t[i]]);
        res.push_back(s);
    }
    return res;
}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return helper1(strs);
//        return helper0(strs);        
    }

