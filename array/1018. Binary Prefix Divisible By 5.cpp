//===類似題===
1019. Next Greater Node In Linked List
2455. Average Value of Even Numbers That Are Divisible by Three
//===思路===
(*)如果array超出32bit或64bit,計算%5會失真
(*)每次運算時都取一次5餘數,做為下一次運算的基準, 就不會有overflow發生
//====
vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> answer;
    int tmp =0;
    for(int i=0;i<nums.size();i++){
        tmp = tmp<<1 | nums[i];
        tmp = tmp%5;
        if(tmp==0) answer.push_back(true);
//            if(tmp%5==0) answer.push_back(true);
//            if((tmp&0xff==0x0a) || (tmp&0xff==0x05)||(tmp==0)) answer.push_back(true);
        else answer.push_back(false);
    }
    return answer;
}
//===寫法2===
vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int val = 0;
        int tmp = 0;
    
        for(int i=0; i<nums.size(); ++i){
            val = (val<<1) + nums[i];
            tmp = val%5;
            if(tmp){
                res.push_back(false);
            } else {
                res.push_back(true);
            }
            val = tmp;
        }
        return res;
}

