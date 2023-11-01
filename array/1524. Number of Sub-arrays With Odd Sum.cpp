//===類似題===
2098. Subsequence of Size K With the Largest Even Sum

//===思路===
(*)參考 subarray sum equals to k
        subarray sum multiple to k

even-odd = odd  偶-奇=奇
odd-even = odd  奇-偶=奇


int numOfSubarrays(vector<int>& arr) {
        unordered_map<long long,long long> ump;//even/odd count
        long long sum = 0;
        long long res = 0;
        long long mod = 1e9+7;
        ump[0]=0,ump[1]=0;

        for(int i=0; i<arr.size(); ++i){
            sum=sum+arr[i];
            if(sum%2) res++;//odd
 
            if(sum%2){//sum==odd
                res+=ump[0];  //加上偶數的數量  
            }else{//sum==even
                res+=ump[1];  //加上奇樹的數量
            }
            ump[sum%2]++;
        }
        return (long)res%mod;//沒有對 1e9+7 取餘數, 答案會錯誤.... 通常用在數值很大的情況之下
    }
