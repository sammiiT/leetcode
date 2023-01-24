//===類似題===
17. Letter Combinations of a Phone Number
259. 3Sum Smaller
//===思路====
(*)固定一個點, 動態判斷其餘兩個點
(*)之前是用"0"來做判斷, 這一題是用target做判斷
(*)同樣的,也會有以下三種情況,並對應的處理 
sum<target  
sum>target
sum==target

(*)
判斷每次的差值是不是小於前一個, 如果是,
-紀錄最新的最小差值
-紀錄最新的總和, 因為要回傳的解答是總和
//=======
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int size = nums.size();
		int res = INT_MAX;
		int ret = 0;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < size - 2; ++i) {
			if (i == 0 || nums[i] != nums[i - 1]) {
				for (int j = i + 1, k = size - 1; j < k;) {
					if (j - 1 > i&& nums[j] == nums[j - 1]) {//跟前一個數值相等
						j++;
					}
					else if (k + 1 < size && nums[k] == nums[k + 1]) {//跟前一個數值相等
						k--;
					}
					else {
						int sum = nums[i] + nums[j] + nums[k];
						if (sum < target) {
							j++;
						}
						else if (sum > target) {
							k--;
						}
						else {//sum ==target: diff ==0
							return target;
						}
						int diff = abs(target - sum);

						if (diff < res) {
							ret = sum;
						}
						res = min(diff, res);

					}
				}
			}
		}
		return ret;

	}

	int threeSumClosest_OK(vector<int>& nums, int target) {
		int size = nums.size();
		int diff = INT_MAX;
		int res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < size - 2; ++i) {
			if (i == 0 || nums[i] != nums[i - 1]) {
				for (int j = i + 1, k = size - 1; j < k;) {
					if (j - 1 > i&& nums[j] == nums[j - 1]) {
						++j;
					}
					else if (k + 1 < size && nums[k] == nums[k + 1]) {
						--k;
					}
					else {
						int sum = nums[i] + nums[j] + nums[k];
						if (sum < target) {
							++j;
						}
						else if (sum > target) {
							--k;
						}
						else {
							return target;
						}
						if (abs(target - sum) < diff) {
							diff = abs(target - sum);
							res = sum;
						}
					}//-4,-1,2,1
				}

			}
		}
		return res;
	}
};
//======同思路===
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ret = 0;
        int res = INT_MAX;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;//duplicate i
            for(int j=i+1,k=n-1;j<k;){
                if(j-1>i && nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                if(k+1<n && nums[k]==nums[k+1]){
                    k--;
                    continue;
                }

		int sum = nums[i]+nums[j]+nums[k];    
                if(res>=abs(sum-target)){//放在最後面也可以 
                    res = abs(sum-target);
                    ret = sum;
                }

		    
		if(sum>target){
                    k--;    
                }else if(sum<target){
                    j++;
                }else{//sum==target
                    return target;
                }
            }        
        }
        return ret;
    }



//-4,-1,-1,0,1,1,3;
