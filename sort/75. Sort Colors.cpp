//===類似題===
76. Minimum Window Substring
280. Wiggle Sort

//===思路===
(*)使用quick sort
1.quick sort的每一次計算, 都只是將數列分成"大於pivot區間"和"小於pivot區間"
2.上述兩區間,並沒有再重新作排列, 所以必須分別對這兩區間做quick sort
3.直到區間運算的邊界 不滿足 (l<r) 即停止
//=====
void swap(vector<int>& arr, int x, int y){
    int t = arr[x];
    arr[x]=arr[y];
    arr[y]=t;
}
int partition_ascending(vector<int>& arr, int l, int r){
    int pivot =arr[r];
    int j=l;
    for(int i=l;i<r;i++){
        if(arr[i]<=pivot){
            swap(arr,i,j);
            j++;}
    }
    swap(arr,j,r);
    return j;
}
void sort_ascending(vector<int>& arr, int l, int r){
    if(l<r){
        int p = partition_ascending(arr,l,r);
        sort_ascending(arr,l,p-1);
        sort_ascending(arr,p+1,r);
    }
}
void helper0(vector<int>& nums){
    sort_ascending(nums,0,nums.size()-1);
}
void helper1(vector<int>& nums){
    sort(nums.begin(),nums.end());
}
    void sortColors(vector<int>& nums) {
//        helper1(nums);
        helper0(nums);
    }
};
