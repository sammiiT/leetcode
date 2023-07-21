//===類似題===
1003. Check If Word Is Valid After Substitutions
More challenges
2460. Apply Operations to an Array
2501. Longest Square Streak in an Array
944. Delete Columns to Make Sorted

//===思路===

//====
vector<string> helper0(vector<string>& words){
    unordered_map<char,int> m;
    priority_queue<char> pq;
    vector<string> res;
    
    for(int i=0;i<words[0].size();i++){//map記錄第一個string有的character
        m[words[0][i]]++;
    }
    for(int i=1; i<words.size(); i++){//從第二個數列開始比對
        for(int j=0; j<words[i].size(); j++){
            //if(m.count(words[i][j])>0){
            if(m[words[i][j]]){
                pq.push(words[i][j]);//有出現的character記錄在priority_queue
                m[words[i][j]]--;
            }
        }
        m.clear();//將map清除
        while(!pq.empty()){
            char t = pq.top();
            pq.pop();
            m[t]++;//從priority_queue再定義map
        }
    }
    for(auto a:m){//最後的map就是解
        for(int i=0;i<a.second;i++){
            string s(1,a.first);    
            res.push_back(s);
        }
    }
    return res;
}

vector<string> commonChars(vector<string>& words) {
        return helper0(words);
}
//===思路2===
1.unordered_map<char,int> ump;//舊的相同的element
2.unordered_map<char,int> m;//紀錄新的string與前一個string相同的element
	
vector<string> commonChars(vector<string>& words) {
    unordered_map<char,int> ump;
    unordered_map<char,int> m;
    vector<string> res;
    
    for(char c:words[0]) ump[c]++;//第一個參考 map
    
    for(int i=1; i<words.size(); ++i){
        for(char c:words[i]){//比較前一個string與新的string相同的element
            if(ump.count(c) && ump[c]>0){//如果新的string的element個數超過舊的element, 則不會進入此判斷式
                ump[c]--;
                m[c]++;
            }
        }
        ump = m;//更新下一個要比較的element
        m.clear();//清除,作為下一個新的string element
    }
    
    for(auto it:ump){
        for(int i=0; i<it.second; ++i){
            res.push_back(string(1,it.first));
        }
    }
    return res;	
}

//===思路3===
vector<string> commonChars(vector<string>& A) {
		vector<string> res;
		unordered_map<char, int> charCnt;
		for (char c : A[0]) ++charCnt[c];
		for (int i = 1; i < A.size(); ++i) {
			unordered_map<char, int> tmpCnt;
			for (char c : A[i]) ++tmpCnt[c];
			for (auto &a : charCnt) {
				if (!tmpCnt.count(a.first)) {
                    a.second = 0;
                    continue;
                }
				a.second = min(a.second, tmpCnt[a.first]);
			}
		}
		for (auto a : charCnt) {
			for (int i = 0; i < a.second; ++i) {
				res.push_back(string(1, a.first));
			}
		}
		return res;
}



