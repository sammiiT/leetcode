//===類似題===
139. Word Break
472. Concatenated Words

//=== 思路====
(*) DFS算法
- 陣列中的每一個節點都可以當作root節點, 每一個節點都是上一層的child節點
- 此題的陣列是vector<string> wordDict
- 因為陣列元素可以reused,所以每進入下一層, loop迴圈都從i=0開始

0. segment 是要連續,不能中間斷掉, 左半部和右半部連接

1.宣告 string& out, 紀錄每一個滿足條件的string
2.宣告 vector<string>& res, 紀錄滿足最後條件的string
3.每一次substring都要從string[0]開始,
- 取從0開始的substr, 判斷此substr是否等於wordDict[i]
--不等於就continue

4.每一次都要記錄(append)新的string; out.append(wordDict[i]+" ") 
跳回上一層要把append刪除; out = out.substr(0,size);//size維之前out的長度

5.最回傳res


(*)
 cout<<str.substr(pos, str.size()-pos)<<endl;
   //str.size()是1-index, pos是0-index    相減?????? 

(*)思路重構
1.以wordDict為依據, 遍歷wordDict並與string做比較
2.wordDict[i]不同的排列方式, 可以滿足string的segmentation => 所以用DFS
for(int i=0; i<wordDict.size(); ++i){...} 

3.每一次判斷string segement, 都把此segment從string中刪除, 並將剩下的string放到下一層DFS中做運算


//=====
void helper(string s ,vector<string>& wordDict, string& out, vector<string>& res){
    if(s.size()==0){
        out.pop_back();//將space 字元移除
        res.push_back(out);
        return;
    }

    for(int i=0; i<wordDict.size(); ++i){
        int len = wordDict[i].size();
        if(s.substr(0,len)!=wordDict[i]) continue;//不同排列順序
        
        string tmp = s.substr(len,s.size()-len);//剩下的String
        int size = out.size();
        
        out.append(wordDict[i]+" ");
        helper(tmp,wordDict,out,res);
        out = out.substr(0,size);//沒有辦法pop_back() string,所以用之前紀錄的substriing size
    }
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string out;
        helper(s,wordDict,out,res);
        return res;
}

//=== 寫法2 ===
(*)一樣用DFS
(*) 將wordDict用unordered_set<string> 儲存
(*) 不用memory紀錄出現過的路徑:與word break不同
- 當wordDict中包含 {cat , cats}, 且 cat和 cats皆可滿足題意
- 若採用memory紀錄來避免重複計算, 則計算完cat之後, 就不會再往cats紀錄下去 

(*)word break題目需要用到memory, 來避免重複計算.
- word break,只判斷是否存在(true or false), 所以用一個 memory來記錄"先前已走過的路徑"
- 當wordDict中包含 {cat , cats}, 且 cat和 cats皆可滿足題意
  若判斷到"cat"時,就可滿足題意; 則不會往"cats"繼續運算.

- 先前已走過的路徑: 先走到的路徑是最深Depth的路徑, 這些先走到的路徑會先存放到memory中
- 先記錄到memory中的結果,目的是用來避免重複計算

void dfs(string& s,
        unordered_set<string>& ust,
        int start,
        string str,
        vector<string>& res){
    if(start==s.size()){
        str.pop_back();
        res.push_back(str);
        return;
    }

    for(int i=start;i<s.size();++i){
        string tmp = s.substr(start,i-start+1);
        if(ust.count(tmp))
            dfs(s,ust,i+1,str+tmp+" ",res);
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> ust(wordDict.begin(),wordDict.end());
    vector<string> res;
    dfs(s,ust,0,"",res);
    return res;
}




