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
