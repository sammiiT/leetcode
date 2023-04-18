//===類似題===
139. Word Break
472. Concatenated Words

//=== 思路====
(*) DFS算法
- 陣列中的每一個節點都可以當作root節點, 每一個節點都是上一層的child節點
- 此題的陣列是vector<string> wordDict
- 因為陣列元素可以reused,所以每進入下一層, loop迴圈都從i=0開始

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

//=====
void helper(string s ,vector<string>& wordDict, string& out, vector<string>& res){
    if(s.size()==0){
        out.pop_back();
        res.push_back(out);
        return;
    }

    for(int i=0; i<wordDict.size(); ++i){
        int len = wordDict[i].size();
        if(s.substr(0,len)!=wordDict[i]) continue;
        
        string tmp = s.substr(len,s.size()-len);
        int size = out.size();
        
        out.append(wordDict[i]+" ");
        helper(tmp,wordDict,out,res);
        out = out.substr(0,size);
    }
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string out;
        helper(s,wordDict,out,res);
        return res;
}
