//===類似題====
1657. Determine if Two Strings Are Close
2059. Minimum Operations to Convert Number
2171. Removing Minimum Number of Magic Beans

//===思路===
(*)sliding window
(*)反向思考, 不討論兩邊的和為x, 討論window中的數值總和為(total-x);其中total為數列總和

    |<- window和  ->|
o   o   o   o   o   o   o
|                       |
p                       q  
p+q=x; window和 = total-x  

1.計算sliding window, 如果window和等於total-x
-計算window長度, 取max, 取max相對x就會是最少

2.要有一個變數found來判斷是否有找到數值,作為判斷是否滿足題目條件

//=====
int helper0(vector<int>& nums, int x) {
    int total =0;
    int target;
    int sum=0;
    int res = 0;
    int found =0;//要有這一項, 當x等於所有的數值相加, 沒有此項,單用(res==0)做判斷會錯誤
    
    int n = nums.size();
    for(int i=0;i<n;i++){
        total+=nums[i];
    }    
    target = total-x;
    for(int i=0,j=0;i<n;i++){
        sum+=nums[i];
        while(j<=i && sum>target){
            sum-=nums[j];
            j++;
        }
        if(sum==target){
            found=1;
            res = max(res,i-j+1);
        }
    }
    return found?(n-res):-1;
//    return res?(n-res):-1;
}
    int minOperations(vector<int>& nums, int x) {
        return helper0(nums,x);
    }

#===寫法2===
int minOperations(vector<int>& nums, int x) {
    int n=nums.size();
    int total = accumulate(nums.begin(),nums.end(),0);
    int i=0,j=0;
    int sum=0;
    int ret = INT_MAX;

    if(total<x) return -1;

    for(;i<n;++i){
        sum+=nums[i];
        while((total-sum)<x && j<n){//
            sum-=nums[j];
            ++j;
        }
        ret = ((total-sum)==x)?min(ret,n-(i-j+1)):ret;
    }
    return (ret==INT_MAX)?(-1):ret;

}


    
