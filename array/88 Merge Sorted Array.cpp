//====類似題===
89. Gray Code
977. Squares of a Sorted Array
986. Interval List Intersections
2516. Take K of Each Character From Left and Right
//===思路===
(*)從兩個陣列的"頭"開始比較頭開始比較,會有3種情況
1. 陣列nums1 索引超過m, nums2沒有 => 將nums2[j]放入陣列
2. 陣列nums2 索引超過n, nums1沒有 => 將nums1[i]放入陣列
3. nums1和nums2的索引都沒超過邊界 => 做比較, 將小的放入陣列

//====
void helper1(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i=0,j=0;
    vector<int> res;
    while(i<m||j<n){
        if(i==m && j<n) {
            res.push_back(nums2[j]);
            j++;
        }else if(i<m && j==n){
            res.push_back(nums1[i]);
            i++;
        }else if(i<m && j< n){
            if(nums1[i]<=nums2[j]){
                res.push_back(nums1[i]);
                i++;        
            }else{
                res.push_back(nums2[j]);
                j++;
            }
        }
    }
    nums1 = res;
}

//===思路2===
(*)從後面開始算

1.較大的放在最後一個, 依序排放,最後放到index=0的位置
2.如果其中有一個陣列已經放置完畢, 則設定為INT_MIN

//==
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
      int n1 = nums1.size();
      int n2 = nums2.size();
      int id1= m-1;
      int id2= n-1;
          
      for(int i=(m+n-1); i>=0; --i){
          int val1 = (id1>=0)?nums1[id1]:INT_MIN;
          int val2 = (id2>=0)?nums2[id2]:INT_MIN;
          
          if(val1<val2){
              nums1[i] = val2;
              id2--;
          }else{//val1 >= val2
              nums1[i] = val1;
              id1--;
          }
      } 
    }
    
    
    void merge_OK(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j,k;
        
        i=m-1;
        j=n-1;
        k=m+n-1;
        
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                k--,i--;
            }else{//nums1[i]<=nums2[j]
                nums1[k] = nums2[j];
                k--;j--;
            }
        }
        while(j>=0) {nums1[k]=nums2[j]; k--;j--;}
    }
    
};
