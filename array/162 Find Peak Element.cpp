class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        nums.push_back(INT_MIN);
        nums.insert(nums.begin(),INT_MIN);
        for(int i=1;i<nums.size()-1;++i){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                return i-1;
            }
        }
        return -1;
    }
};

//====思路======
1.邊界會發生peak value,所以要在邊界兩端各加上一個節點;節點值為INT_MIN
2.比較 (nums[j-1]<nums[j] && nums[j]<nums[j+1])是否發生
//=================================
int helper(vector<int>& nums){
    int ret;
    int i=0,j=1;
        
    nums.push_back(INT_MIN);//當只有兩個element時
    nums.insert(nums.begin(),INT_MIN);//當只有兩個element時
        
    for(;j<nums.size()-1;){
        if((nums[i]<nums[j]) && (nums[j]>nums[j+1])){
            ret = j;
            break;
        }
        i++;
        j++;
    }
    return ret-1;//新增的點,會造成index多1
}
    
int findPeakElement(vector<int>& nums) {
    if(nums.size()==1) return 0;
    return helper(nums);
}
//====思路====
1.遍歷陣列所有的元素
2.若有數值大於設定的max值, 將當下的值指派給max, 並記錄index
3. 如果過程當中沒有再大於的數, 此數就是peak, 而且是最後一個peak

//====
int helper0(vector<int>& nums){
    int k=0;
    int max = INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(max<nums[i]){
            max = nums[i];
            k = i;
        }
    }
    return k;
}


