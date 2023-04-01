//===類似題===
1674. Minimum Moves to Make Array Complementary
2566. Maximum Difference by Remapping a Digit
2589. Minimum Time to Complete All Tasks
2432. The Employee That Worked on the Longest Task

//===思路===
(*) 用stack資料結構求解
(*) 遍歷數列, 當[i]>[i+1], 則將[i] 從stack pop出來
(*) 因為題目說至少要有k個, 所以第一次遍歷要留下k個陣列數值
1.宣告stack變數作為運算,宣告陣列 vector變數作為解
2.因至少要有K個, 所以先遍歷至 i<(n-k),  n是原陣列個數
3.第一次遍歷會得到一stack, 由小至大作排列

4.第二次遍歷是從第(n-k)到(n-1); 共k個, 
-同樣也是按照 stack操作; 當[i]>[i+1], 則將[i] 從stack pop出來
-每次stack操作完,要將stack的bottom移除, 並將值記錄在vector中
-操作完即為解

(*) subsequence: 代表不是subarray, 數值與數值之間可以不連續, 但"順序必須滿足原來排列"

//======
vector<int> helper1(vector<int>& nums, int k) {
    deque<int> stk;
    vector<int> res;
    int n = nums.size(),i=0;

    for(i=0; i<n-k; ++i){
        while(!stk.empty()&& stk.back()>nums[i]){ stk.pop_back(); }
        stk.push_back(nums[i]);
    }

    for(int j=i; j<n; ++j){
        while(!stk.empty() && stk.back()>nums[j]){ stk.pop_back(); }
        stk.push_back(nums[j]);
        res.push_back(stk.front());
        stk.pop_front();
    }
    return res;

}


//====用vector 會 time limited exceeded====
vector<int> helper0(vector<int>& nums, int k) {
    int n = nums.size(),i;
    vector<int> stk;
    vector<int> res;
    
//   for( i=0; i<n && (n-(i+1))>k; ++i){
    for( i=0;i<n-k ; ++i){    
        while(!stk.empty()&& stk.back()>nums[i]) stk.pop_back();
        stk.push_back(nums[i]);
    }//start from i

    for(int j=i; j<n; ++j){
        while(!stk.empty() && stk.back()>nums[j]){
            stk.pop_back();
        }
        stk.push_back(nums[j]);
        res.push_back(stk[0]);
        stk.erase(stk.begin());
    }
    return res;

}
