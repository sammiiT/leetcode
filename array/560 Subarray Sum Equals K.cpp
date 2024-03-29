
//===類似題===
974. Subarray Sums Divisible by K
2090. K Radius Subarray Averages
2219. Maximum Sum Score of Array

//===思路====

int subarraySum(vector<int>& nums, int k){
    int sum =0;
    int res;
    unordered_map<int,int> ump;
    
    for(int i=0; i<nums.size(); ++i){
        sum = sum+nums[i];
        if(sum==k) res++;

        int need = sum-k;
        if(ump.count(need)){
            res = res + ump[need];
            //res++ 會錯誤 [0,0,0,0,0,0] k = 0
        }
        ump[sum]++;
    }
    return res;
}

//===原思路===
(*)現在會發生 Time limited Exceeded
class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> sum(n,0);
        int res = 0;
        sum[0]=nums[0];
        
        for(int i=1;i<n;++i){
            sum[i]=nums[i]+sum[i-1];
        }
        
        for(int i=0; i<n; ++i){
            if(sum[i]==k) res++;
            for(int j=0;j<i;++j){
                if(sum[i]-sum[j]==k) res++;
            }
        }
        return res;
    }
    
    int subarraySum_OK(vector<int>& nums, int k) {
      
        if(nums.empty()) return 0;
        int n = nums.size();
        int res=0;
        vector<int> sum(n,0);
        
        sum[0]=nums[0];
        for(int i=1;i<nums.size();++i){
            sum[i]=sum[i-1]+nums[i];
        }
        
        for(int i=0;i<n;++i){
            if(sum[i]==k) res++;//i計算從0開始
            
            for(int j=i-1; j>=0; --j){//(1)計算從0之後開始：(j>=0)
                                      //(2)數列中若有重複的數值
                if(sum[i]-sum[j]==k) res++;
            }
        }
        return res;
    }
    
};
