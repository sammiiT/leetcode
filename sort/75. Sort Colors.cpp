//===類似題===
76. Minimum Window Substring
280. Wiggle Sort

//===思路===
(*)使用quick sort
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
