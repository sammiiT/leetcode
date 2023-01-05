//====merge sort ====
void merge(vector<int>& arr, int l, int m, int r){
    //獨立的array, 才可以重新把arr的數值覆蓋而不會出錯
    vector<int> left(arr.begin()+l,arr.begin()+m+1);//vector最後要預留一個空間
    vector<int> right(arr.begin()+m+1,arr.begin()+r+1);//vector最後要預留一個空間
    
    left.insert(left.end(),INT_MAX);//多加一個INT_MAX, 作為比較的邊界
    right.insert(right.end(),INT_MAX);
    
    int lidx=0;
    int ridx=0;
    
    //排列arr,從l到r
    for(int i=l;i<=r;i++){
        if(left[lidx]<=right[ridx]){
            arr[i]=left[lidx];
            lidx++;
        }else{//left[lidx]>right[ridx]
            arr[i]=right[ridx];
            ridx++;
        }
    }
}

void mergeSort(vector<int>& arr, int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);//split
        mergeSort(arr,m+1,r);//split
        merge(arr, l, m, r);//sort and combine
    }
}


//==== quick sort=====



