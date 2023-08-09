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
