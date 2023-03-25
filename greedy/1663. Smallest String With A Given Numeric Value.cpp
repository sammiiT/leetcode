//===類似題===
1664. Ways to Make a Fair Array
1509. Minimum Difference Between Largest and Smallest Value in Three Moves
2311. Longest Binary Subsequence Less Than or Equal to K
1827. Minimum Operations to Make the Array Increasing
//===思路===
(*) greedy解法
1.宣告一string, 其大小為n, 初始值為aaaaa...
2.因為string的初始值為aaaa... 有n個, 所以k一開始要減去n
3.開始用greedy填入剩下的數值,因為要lexicographically smallest,所以從陣列的後面開始填
- 每次從k裡面取出最大值25, 取出後填入string的最後一位
- 當string的最後一位等於26, 則index往前推一位繼續執行

4.當k==0時,代表lexicographically smallest 字串已完成, 即為解

//====
string getSmallestString(int n, int k) {
    string res(n,'a');
    k-=n;//一開始先放1個在string中 (aaa)
    while(k){//從後面開始放剩下的數字,每次放最大的數字 <=25
        int d = min(k,25);
        res[--n]+=d;
        k-=d;
    }
    return res;
}

//===Time Limited Exceeded===
string getSmallestString(int n, int k) {
    vector<int> nums(n,0);
    string res;
   
    int quotient = k/n;
    int remain = k%n; 
    for(int i=0;i<n;++i) nums[i]=quotient;
    for(int i=n-1;i>=0;--i){
        if(remain==0) break;
        
        int rget = 26-nums[i];
        if(rget<=remain){
             nums[i]+=rget;
             remain-=rget;
        }else{//rget>remain
            nums[i]+=remain;
            remain-=remain;
        }
    }

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
        if(i%20==0) cout<<endl;
    }cout<<endl;
    
    int l=0,r=n-1;
    
    while(l<r){
        int rget=0,lgive=0;
        if(nums[r]>=26) {
            --r;
            continue;
        }
        if(nums[l]<=1) {
            ++l;
            continue;
        }
        
        rget = 26-nums[r];
        lgive = nums[l]-1;
        
        if(rget>lgive){
            nums[r]+=lgive;
            nums[l]-=lgive;
        }else if(rget<lgive){
            nums[r]+=rget;
            nums[l]-=rget;
        }else{//rget==lgive
            nums[r]+=rget;
            nums[l]-=rget;
        }
    }
    for(int i=0;i<nums.size();++i){
        res+=(nums[i]-1)+'a';
    }
    return res;
}
