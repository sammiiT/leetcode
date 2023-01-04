//===類似題===
216. Combination Sum III
703. Kth Largest Element in a Stream
2146. K Highest Ranked Items Within a Price Range
//===思路===
(*) quicksort概念, 但是sort方式為descending
(*) quick select概念
(*)quick sort輸出是 0-index base; 第4個, 就是 0,1,2,3,4 =>實際上是第5個
依題意, 1-index base, 所以0-index base, 求第k個(1-index base); 要輸入(k-1)
第3個,其實是index=2的位址(0,1,2)
第4個,其實是index=3的位址(0,1,2,3)
第5個,其實是index=4的位址(0,1,2,3,4)
//====
void swap(vector<int>& arr, int x, int y){
    int t = arr[x];
    arr[x]=arr[y];
    arr[y]=t;
}
int partition_descending(vector<int>& arr, int l, int r){
    int pivot = arr[r];
    int j = l;
    for(int i=l; i<r; i++){
        if(arr[i]>=pivot){
            swap(arr,i,j);
            j++;
        }
    }
    swap(arr,j,r);
    return j;
}
void quickSort_descending(vector<int>& arr, int l, int r){
    if(l<r){
        int p = partition_descending(arr,l,r);
        quickSort_descending(arr,l,p-1);
        quickSort_descending(arr,p+1,r);
    }
}
int quickSelect_largest(vector<int>& arr, int l, int r,int k){
    if(l==r) return arr[l];
    int p = partition_descending(arr,l,r);
    if(p==k) return arr[p];
    else if(p<k) return quickSelect_largest(arr,p+1,r,k);//p比k小,所以要往右移, 才會追到k
    else// p>k  p比k大,所以要往左移,才會追到k
        return quickSelect_largest(arr,l,p-1,k);    
}
int helper1(vector<int>& nums, int k){
    return quickSelect_largest(nums,0,nums.size()-1,k-1);
}

//=====ascending===

int partition_ascending(vector<int>& arr, int l, int r){
    int pivot = arr[r];
    int j = l;
    for(int i=l; i<r; i++){
        if(arr[i]<=pivot){
            swap(arr,i,j);
            j++;
        }
    }
    swap(arr,j,r);
    return j;
}
void quickSort_ascending(vector<int>& arr, int l, int r){
    if(l<r){
        int p = partition_ascending(arr,l,r);
        quickSort_ascending(arr,l,p-1);
        quickSort_ascending(arr,p+1,r);
    }
}
