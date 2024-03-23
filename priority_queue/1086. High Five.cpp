//===類似題====

//===思路====
1.宣告: 
map<int,priority_queue<int,vector<int>,cmp>>
= <學生index, 每一次score>

map的key會排列

2.針對每一個index計算其top 5 average, 並將運算後的結果記錄到res中

  
struct cmp{
  bool operator()(int& a,int& b){
      return a<b;
  }};

vector<vector<int>> highFive(vector<vector<int>>& items){
    vector<vector<int>> res;
    map<int,priority_queue<int,vector<int>,cmp>> mp;
    int k;
    
    for(vector<int>& it:items){ mp[it[0]].push(it[1]); }

    for(auto it:mp){
        int average = 0;
        k=5;
        while(!it.second.empty() && k){
            average+=it.second.top();
            it.second.pop();
            --k;
        }
        res.push_back({it.first,average/5});
    }
    return res;
}
