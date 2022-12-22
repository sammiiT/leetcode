//===類似題===
454. 4Sum II
462. Minimum Moves to Equal Array Elements II
2141. Maximum Running Time of N Computers
2137. Pour Water Between Buckets to Make Water Levels Equal

//===思路===
(*)如果用(n-1)去+1的次數來思考, 需選擇最小的(n-1)個數值(排除最大的那一個); 所以
1.(n-1)個數字+1 ,表示剩下那一個數字-1之後, 數列的差值不變

2.找出數列中最小的那一個, 將其餘每一個數的差值 相加, 就是minimum moves 

//=======
int helper0(vector<int>& nums){
       int res = 0, mn = INT_MAX;     
       for(int& num:nums) mn = min(mn,num);
       for(int& num:nums) res+=(num-mn);
       return res; 
}

int minMoves(vector<int>& nums) {
        return helper0(nums);
}
