//=== more challenge ===
2008. Maximum Earnings From Taxi
2054. Two Best Non-Overlapping Events
//===思路===
(*) treemap + dynamic programing
(*)
1.TreeMap:建立結束工作時間和所獲得的利潤 關係(映射)
初始化將{0,0}映射加入 <endTime, profit>; 按照工作的結束時間做排序, 原因是因為結束時間才可以領到profit

2.建立一個二維matrix, 每一個維度的定義為{endTime, startTime,profit}
並對此二維matrix做排列, 以endTime大小做排列

3.遍歷此二維陣列,找尋每一個element的startTime對應前一個endTime的profit是多少
找到前一個profit值, 並加上當下的profit值; 若總和大於當下工作endTime的profit; 則更新dp

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<vector<int>> jobs;//{endTime,startTime,profit}     
    map<int,int> dp({0,0});
  
    for(int i=0; i<startTime.size(); ++i){//(2)
        jobs.push_back({endTime[i],startTime[i],profit[i]});
    } 
    sort(jobs.begin(),jobs.end());
    
    //job[0]=endTime , job[1]=startTime, job[2]=profit
    for(auto& job: jobs){
        int cur = prev(dp.upper_bound(job[1]))->second + job[2];//(3)開始時間的前一個dp,就是前一個工作的結束時間
        if(cur > dp.rbegin()->second) dp[job[0]] = cur;
    }
    return dp.rbegin()->second;
}  

#=== 寫法2 會time limited exceeded ===
(*)dfs +mem
這邊的mem用的是1-d 陣列紀錄 => 導致 time limited exceeded
應該用2-d陣列紀錄, 會比較好 => 

int dfs(vector<vector<int>>& jobs, int start, vector<int>& mem){
    if(start>=jobs.size()) return 0;
    if(mem[start]!=-1) return mem[start];
    
    int profit = 0;
    for(int i=start; i<jobs.size(); ++i){
        if(start>0) if(jobs[start-1][1]>jobs[i][0]) continue; #如果前一個的endTime超過現在的startTime, 就不執行
        profit = max(profit, jobs[i][2] + dfs(jobs,i+1,mem));
    }
    mem[start] = profit;
    return profit;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int m = startTime.size();
    vector<vector<int>> jobs;
    vector<int> mem(m,-1);
    
    for(int i=0; i<m; ++i){
        jobs.push_back({});
        jobs.back().push_back(startTime[i]);
        jobs.back().push_back(endTime[i]);
        jobs.back().push_back(profit[i]);
    }

    sort(jobs.begin(),jobs.end(),[](vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    });

    return dfs(jobs,0,mem);
}





