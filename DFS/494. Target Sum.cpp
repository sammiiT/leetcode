//===類似題===
282. Expression Add Operators
2787. Ways to Express an Integer as Sum of Powers
//===思路===
(*) DFS

void helper(vector<int>& nums, int target, int output, int index, int& res){
    if(index == nums.size()){
        if(output==target) ++res;
        return;
    }
    helper(nums, target, output+nums[index], index+1, res);
    helper(nums, target, output-nums[index], index+1, res);
}

int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        helper(nums,target,0,0,res);
        return res;
}

//====failed===
void helper(vector<int>& nums, int target, int output, int index, int op, int& res){
    if(index == nums.size()){
        if(output==target) ++res;
        return;
    }
    output += (op*nums[index]);
/*  output 帶入 造成解x2 
    應該是  output - nums[i]
           output + nums[i]
*/
    helper(nums, target, output, index+1,  1,res);
    helper(nums, target, output, index+1, -1,res);
}
