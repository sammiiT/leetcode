//====類似題 ===
2486. Append Characters to String to Make Subsequence
319. Bulb Switcher


int helper0(int n){
        vector<int> sum(n+1,0);
        int ret = 0;
        
        if(n==1) return 1;
        sum[1]=1;
        for(int i=2;i<n+1;i++){
            sum[i]=sum[i-1]+i;
        }

        for(int i=2;i<n+1;i++){
            if(sum[n]-sum[i]+i == sum[i]) return i;
        }
        return -1;
}

int pivotInteger(int n) {
        return helper0(n);     
}

//==思路===
1.一陣列每一個element紀錄當下和前面所有數值的總和
1.1 多建立一個陣列節點,讓index較好運算
2. 在index x的pivot, 須滿足 sum[n]-sum[x]+x = sum[x]
3.若上述相等,則回傳x, 遍歷完不滿足, 回傳-1
