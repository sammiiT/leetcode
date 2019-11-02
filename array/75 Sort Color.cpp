class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p=0,q=0,r=0;

        for(int i=0;i<nums.size();++i){
                if(nums[i]==0){
                    p++;
                }else if(nums[i]==1){
                    q++;
                }else{//nums[i]==2
                    r++;
                }
        }


        for(int i=0;i<nums.size();++i){
                if(i<p){
                    nums[i]=0;
                }else if(i<(p+q)){
                    nums[i]=1;
                }else{//i<(p+q+r)
                    nums[i]=2;
                }
        }

    }
};