//===類似題====
1590. Make Sum Divisible by P
1025. Divisor Game
1578. Minimum Time to Make Rope Colorful
1357. Apply Discount Every n Orders

//===思路===
1.奇數個subarry, 奇數(2i-1),i=0,1,2,3... 
1.1 由上述,奇數為 1,3,5,7,....
2.取的個數作遍歷  while(2*i+1<=n)//最多一次取n個;若n為奇數
3.數列遍歷時,從idx_0開始, 判斷每次的subarray結尾會不會超過n
  for(int j=0; j+p<=n; j++)//p為一次取(2*i-1)個
4.做sum
  for(int q=0; q<p; q++)
     res += arr[j+q];//從j開始, 位移q個
  
//======
int helper0(vector<int>& arr){
    int n = arr.size();
    int res=0;
    int i=0;
    while((2*i+1)<=n){
        int p = 2*i+1;
        for(int j=0; j+p<=n; j++){
            for(int q=0; q<p; q++){
                res+=arr[j+q];
            }
        }
        i++;
    }
    return res;
}

int sumOddLengthSubarrays(vector<int>& arr) {
     return helper0(arr);    
}

//========
    int sumOddLengthSubarrays(vector<int>& arr) {
     int final_sum=0;
      for(int i=0;i<arr.size();i++){
        int sm=0;
        for(int j=i;j<arr.size();j++){
            sm+=arr[j];
            if((j-i+1)%2!=0){
                final_sum+=sm;
            }
        }
      }
        
    return final_sum;
      
    }

