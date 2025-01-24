//===類似題===
740. Delete and Earn
2059. Minimum Operations to Convert Number
1574. Shortest Subarray to be Removed to Make Array Sorted
2446. Determine if Two Events Have Conflict
//===思路==
(*)利用stack資料結構
(*)stack的元素為(日期, 氣溫)
1.宣告一陣列, 此陣列為每一日期要等待的天數  
2.當天氣溫比前一天小, 則將"日期"和"氣溫"push至 stack中
3.當天氣溫比前一天大, 則將stack top移出, 並計算天數的差值紀錄至陣列中
//====

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n,0);
    vector<pair<int,int>> stk;//index, temp

    for(int i=0;i<n; ++i){
        while(!stk.empty() && stk.back().second < temperatures[i]){
            res[stk.back().first] = i-stk.back().first;//差值, 代表要等待的天數 
            stk.pop_back();
        }
        stk.push_back(make_pair(i,temperatures[i]));
    }
    return res;
}
//===寫法2===
(*)直接用vector<int>表示
    
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n,0);
    vector<int> stk;//index, temp

    for(int i=0;i<n; ++i){
        while(!stk.empty() && temperatures[stk.back()] < temperatures[i]){
            res[stk.back()] = i-stk.back();//差值, 代表要等待的天數 
            stk.pop_back();
        }
        stk.push_back(i);
    }
    return res;
}
//=== 寫法3===
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(),0);
    stack<int> stk;

    for(int i=0; i<temperatures.size(); ++i){
        while(!stk.empty()&& temperatures[stk.top()]<temperatures[i]){
            int id = stk.top();
            if(res[id]==0) res[id]=i-id;// 有 if(res[id]==0) 可降低運算時間
            stk.pop();
        }
        stk.push(i);
    }     
    return res;   
}

