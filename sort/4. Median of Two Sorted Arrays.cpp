//====類似題===
5. Longest Palindromic Substring
2387. Median of a Row Wise Sorted Matrix

//===思路1===
1.用priority_queue把所有的數字push進去, 由小而大
2.
(pq.size()-1)/2 =>紀錄 first middle出現位置
pq.size()%2 => 判斷是奇數個或偶數個 

2.2 for(int i=0; i<t; i++)迴圈, pop到t=(pq.size()-1)/2索引的前一個

3. pop多餘的element,
若奇數個就回傳1個數值
若偶數的要再pop兩次的數值, 除以2 才是解
/*
0,1,2,3
0+(3-0)/2 = 1 => first middle

0,1,2,3,4
0+(4-0)/2 = 2 =>first middle (odd count)
*/

//====
struct cmp{
    bool operator()(int& a,int& b){
        return a>b;
    }
};
double helper0(vector<int>& nums1, vector<int>& nums2){
    priority_queue<int,vector<int>,cmp> pq;
    for(int i=0;i<nums1.size();i++)
        pq.push(nums1[i]);
    for(int i=0;i<nums2.size();i++)
        pq.push(nums2[i]);
    
    int t = (pq.size()-1)/2;
    int s = pq.size();
    double res=0;
    for(int i=0;i<t;i++){ pq.pop(); }
    if(s%2) res = (double)pq.top();
    else {
        for(int i=0;i<2;i++){
            res+=pq.top();
            pq.pop();
        }
        res/=2;
    }
    return res;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    return helper0(nums1,nums2);
}
//====思路2===
1. quickSort排列
//====
void swap(vector<int>& arr,int i, int j){
    int t = arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}
int partition(vector<int>& nums, int l, int r){
        int pivot = nums[r];
        int i=l;
        for(int j=l; j<r; j++){
            if(nums[j]<=pivot){
                swap(nums,i,j);
                i++;
            }
        }
        swap(nums,i,r);
        return i;
}
void quickSort(vector<int>& nums, int l, int r){
    if(l<r){    
        int p = partition(nums, l, r);
        quickSort(nums,l,p-1);
        quickSort(nums,p+1,r);
    }
}
double helper1(vector<int>& nums1, vector<int>& nums2){
    double res =0;
    for(int i=0;i<nums2.size();i++) nums1.push_back(nums2[i]);
    quickSort(nums1, 0, nums1.size()-1);
    
    if(nums1.size()%2){
        res = (double)nums1[(nums1.size()-1)/2];
    }else{
        int fm = (nums1.size()-1)/2;
        res = (double)(nums1[fm]+nums1[fm+1])/2;
    }
    return res;
}

//===思路3
1.因為兩個數列都已經sorting,所以兩兩比較, 較小的就放到新的陣列中
2.新的陣列就是兩個已經相加的陣列

//===
double helper2(vector<int>& nums1, vector<int>& nums2){
    vector<int> res;
    for(int i=0,j=0;i<nums1.size() || j<nums2.size(); ){
        int n,m;
        if(i>=nums1.size()) n=INT_MAX;
        else { n=nums1[i];}
        if(j>=nums2.size()) m=INT_MAX;
        else { m=nums2[j];}

        if(n<=m){
            res.push_back(n);
            i++;
        }else{
            res.push_back(m);
            j++;
        }
    }
    if(res.size()%2){
       return (double)res[(res.size()-1)/2];
    }else{
        return (double)(res[(res.size()-1)/2]+res[(res.size()-1)/2+1])/2;
    }
}
