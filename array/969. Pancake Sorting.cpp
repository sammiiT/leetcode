//===類似題===
970. Powerful Integers
2234. Maximum Total Beauty of the Gardens
1505. Minimum Possible Integer After at Most K Adjacent Swaps On Digits
1738. Find Kth Largest XOR Coordinate Value

//===思路===
1. 遍歷數列,找到最大的數值
2. [0:最大數值的位置] 做reverse => (arr.begin(),arr.begin()+(i+1))
3. [0:n] 做reverse  =>  (arr.begin(),arr.begin()+n)
4. n--;//下次最大的數值

(*)如果遇到最大的值在每次新update的最後位置, 則不用做reverse
if(i==(n-1)) continue;

(*)vector的iterator; 範圍必須要在"最後一個數值"的"下一個位置"
//=========
vector<int> pancakeSort(vector<int>& arr) {
    vector<int> res;
    int n = arr.size();
    while(n){
        int i;
        
        for(i=0; i<n; ++i)  if(arr[i]==n) break;
        if(i==(n-1)) { --n; continue;}
        
        res.push_back(i+1);//每次挑選的位置(1st-index)
        reverse(arr.begin(),arr.begin()+(i+1));
        
        res.push_back(n);//每次挑選的位置(1st-index)
        reverse(arr.begin(),arr.begin()+n);
        --n;
    }
    return res;
}
