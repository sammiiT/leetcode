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