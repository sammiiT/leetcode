//===類似題===
27. Remove Element
2460. Apply Operations to an Array

//===思路===


//===
int helper1(vector<int>& nums){
    vector<int> t;
    t.push_back(nums[0]);

    for(int i=1; i<nums.size(); i++){
        if(nums[i]!=nums[i-1]) t.push_back(nums[i]);
    }
    nums = t;//將nums remove為題意
    return t.size();
}
int helper0(vector<int>& nums){
    int j=0;
    for(int i=1; i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            j++;//不相等,則update index, 並將值填入
            nums[j]=nums[i];//值填入
        }
    }
    return j+1;//回傳個數
}


//=======
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count=1;
        int pre = 0;
        
        for(int i=1;i<nums.size();++i){
            if(nums[pre]==nums[i]){
                if(count<2){
                   pre++;
                   count+=1;
                   nums[pre] = nums[i];
                }    
            }else{//nums[pre]!=nums[i]
                count=1;
                pre++;
                nums[pre]=nums[i];
            }
        }
        return pre+1;
    }
};
