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



//-4,-1,-1,0,1,1,3;