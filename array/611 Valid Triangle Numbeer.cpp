//===類似題===
1. Two Sum
259. 3Sum Smaller
//===思路===
(*) 兩邊和大於第三邊
(*) i>=2: index=2時, 左邊有2個元素
(*)從最大邊開始計算

	[l]           [r=i-1]  [i]
	a   b  c  d    e        f      [l] + [r] > [i]  => 可以有 ae, be, ce, de  共4種

	[l]       [r=r--]      [i]     [l] + [r] > [i]  => 可以有 ad, bd, cd   共三種
	a   b  c   d     e      f  


[l]           [r=i-1]  [i]
 a   b  c  d    e        f      [l] + [r] <= [i]  => l++往右邊移動, 往邊長增加的方向移動

//==
int triangleNumber(vector<int>& nums) {
	int res = 0;
	sort(nums.begin(),nums.end());
	for(int i=nums.size()-1; i>=2; ++i){
		int l = 0,r = i-1;
		while(l<r){
			if(nums[l]+nums[r]>nums[i]){
				res += (r-l);//不包含r,r本身
				--r;
			}else{
				++l;
			}
		}
	}
	return res;
}

//===思路2===
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
	    sort(nums.begin(),nums.end());

        for(int i=0; i<n; ++i){
            for(int j = i+1; j<n; ++j){
            int sum = nums[i]+nums[j];
            int left=j+1, right=n;
            while(left<right){
                int mid = left + (right-left)/2;
                if(nums[mid]<sum){//sum:兩邊和
                    left = mid +1;//要計算到nums[mid]是>= sum的情況; 
                }else{//nums[mid]>=sum//邊界, 兩邊和 小於等於第三邊nums[i]
                right = mid;
                }
            }//left = right;
            res = res+right-(j+1);    
            }
        }
        return res;        
    }
};
