(*) merge_sort和quick_sort差異
-merge_sort是先"拆解到最小單位", 所以要先進入最底層; 然後再做排列的動作
-- split(左區間);
   split(右區間);
   merge(左區間右區間排列);

-quick_sort是"先做排列", 再進入已經排列好的區間,再做下一次排列; 
--已排列好的左右區間, "再拆解"做"排列"
-- partition(排列左右區間);//拆解成左右區間; 左右區間尚未排列
   sort(左區間排列); 
   sort(右區間排列); 
   

//====merge sort ====
void merge(vector<int>& arr, int l, int m, int r){
    vector<int> left(arr.begin()+l, arr.begin()+m+1);
    vector<int> right(arr.begin()+m+1,arr.begin()+r+1);
 
    int i = 0;
    int j = 0;
    int k = l;
    
    while(i<left.size() || j <right.size()){
        long lval = LONG_MAX, rval = LONG_MAX;
        if(i<left.size()) lval = left[i]; 
        if(j<right.size()) rval = right[j];
        
        if(lval<=rval){
            arr[k]=lval;
            i++;
        }
        else{//lval>rval
            arr[k]=rval;
            j++;
        }
        k++;
    }
}

void merge(vector<int>& arr, int l, int m, int r){
    //獨立的array, 才可以重新把arr的數值覆蓋而不會出錯
    vector<int> left(arr.begin()+l,arr.begin()+m+1);//vector最後要預留一個空間
    vector<int> right(arr.begin()+m+1,arr.begin()+r+1);//vector最後要預留一個空間
    
    left.insert(left.end(),INT_MAX);//多加一個INT_MAX, 作為比較的邊界
    right.insert(right.end(),INT_MAX);
    
    int idl=0;
    int idr=0;
    
    //排列arr,從l到r
    for(int i=l;i<=r;i++){
        if(left[idl]<=right[idr]){
            arr[i]=left[idl];
            idl++;
        }else{//left[idl]>right[idr]
            arr[i]=right[idr];
            idr++;
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

//=== merge sort 寫法2 ===
(*)分割到最小的元素, index會相同, 要回傳(i=j)位址的值到上層
(*)到上層之後, 作排列

vector<int> merge_sort(vector<int>& arr, int i, int j){
    if(i==j) return vector<int>(1,arr[i]); //一定會遇到
   
    vector<int> ret;
    int l=0,r=0;
    int m = i+(j-i)/2;
    vector<int> left = merge_sort(arr,i,m);
    vector<int> right = merge_sort(arr,m+1,j);

   do{//sorting
        int nl = l<left.size()? left[l]: INT_MAX; 
        int nr = r<right.size()? right[r]: INT_MAX;
        
        if(nl<=nr){
            ++l;
            ret.push_back(nl);
        }else{//nl>nr
            ++r;
            ret.push_back(nr);
        }
        
    }while(l<left.size() || r<right.size());
    return ret;
}




//==== quick sort=====
(*)每次都找到一個pivot, 經過quick_sort之後:
pivot右邊的數值, 都比pivot大
pivot左邊的數值, 皆比pivot小

(*)再藉由此pivot,分成左右兩邊陣列, 此左右兩邊陣列重複上述步驟計算, 最後可將陣列全部排利完成

   
   
       pivot (選自右邊界 [r])                      pivot(以pivot為基準,[i],[j]對調)   
         |                       [i]<=pivot             |  
 +----+  |  +----+               ======>         +----+ | +----+            
 |[j] |  |  |[i] |                               |[i] | | |[j] |
 +----+  |  +----+                               +----+ | +----+
         |                                           |      | 1.值對調; 2.更新j索引, j++
                                                     \______/   
          
int partition_ascending(vector<int>& arr, int l, int r){
    int pivot = arr[r];
    int j = l;
    for(int i=l; i<r; i++){
        if(arr[i]<=pivot){// arr[i]>pivot  會變成排列"由大至小"
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

//====bubble sort====


