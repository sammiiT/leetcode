//===== 相似題 ======
979. Distribute Coins in Binary Tree
1582. Special Positions in a Binary Matrix
1066. Campus Bikes II
1947. Maximum Compatibility Score Sum

    int helper0(vector<int>& arr){
        int n = arr.size();
        int res = 1;
        vector<int> inc(n,1),dec(n,1);
        
        for(int i=1; i<n; i++){
            if(arr[i-1]>arr[i]){
                dec[i]=inc[i-1]+1;
            }else if(arr[i-1]<arr[i]){
                inc[i]=dec[i-1]+1;    
            }
            res = max(res, max(inc[i],dec[i]));
        }
        return res;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        return helper0(arr);
    }
