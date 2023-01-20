//===類似題===
1274. Number of Ships in a Rectangle
698. Partition to K Equal Sum Subsets
1788. Maximize the Beauty of the Garden
2373. Largest Local Values in a Matrix

//===思路===
題意:找到一個數值, 陣列中大於此數值的改成此數值, 最後將所有的數值相加, 最靠近target的, 即回傳

(*)binary_search
題目是靠index來查找, 也有可能靠數值來查找
靠index來查找, 最後index有很大可能對應到array元素
靠數值查找, 其解不見得會是array中的元素值 ===> 此題用此觀念
int l = 0, r = target;  //靠數值查找

1. 每找出一個middle值, 則判斷(middle)值和(middle+1)所構成的 差值是否滿足題意
- 如果middle的差值>(middle+1)差值 => 往middle+1方向,會越來越靠近target => l = m+1;
- 如果middle差值<=(middle+1)差值=> 往middle方向,會越來越靠近target => r = m;

//=======
int diff(vector<int>& arr, int mid, int target){
    int res = 0;
    for(auto num:arr){
        res = res + min(mid,num);
    }
    return abs(res-target);
}
int helper0(vector<int>& arr, int target){
    int l = 0, r = target;
    while(l<r){
        int m = l + (r-l)/2;
        if(diff(arr,m+1,target)<diff(arr,m,target)) l = m+1;// 如果middle的差值>(middle+1)差值 => 往middle+1方向,會越來越靠近target 
        else// diff(arr,m+1,target)>=diff(arr,m,target) //如果middle差值<=(middle+1)差值=> 往middle方向,會越來越靠近target
            r = m;   
    }
    return r;
}

    int findBestValue(vector<int>& arr, int target) {
        return helper0(arr,target);
    }
