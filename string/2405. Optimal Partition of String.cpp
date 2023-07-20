//===類似題==
1492. The kth Factor of n
915. Partition Array into Disjoint Intervals
2461. Maximum Sum of Distinct Subarrays With Length K

//===思路====
1.用unordered_map<char,bool> 紀錄出現的character
2.遍歷string
3.如果重複出現, 則代表前面的string可以作為一個partition
4.遍歷完之後, 還會剩下一個最後的string, 要加入
5.加入最後一個string, 即為解
//====
int partitionString(string s) {
        unordered_map<char,bool> ump;
        int res = 0;

        for(char c:s){
            if(ump.count(c)){
                res++;
                ump.clear();
            }
            ump[c]=1;
        }
        return res+(ump.size()?1:0);
}
