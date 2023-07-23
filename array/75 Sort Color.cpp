//===類似題===

//===思路===
(*)用quick sort
(*)用merge sort

//===
int partition(vector<int>& nums,int l,int r){
    int pivot = nums[r];
    int j = l;
    for(int i=l; i<r; ++i){
        if(nums[i]<=pivot){
            swap(nums,j,i);
            ++j;
        }    
    }
    swap(nums,j,r);
    return j;
}

void sort(vector<int>& nums,int l, int r){
    if(l<r){
        int p = partition(nums,l,r);
        sort(nums,l,p-1);
        sort(nums,p+1,r);
    }
}


//===思路2===
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p=0,q=0,r=0;

        for(int i=0;i<nums.size();++i){
                if(nums[i]==0){
                    p++;
                }else if(nums[i]==1){
                    q++;
                }else{//nums[i]==2
                    r++;
                }
        }


        for(int i=0;i<nums.size();++i){
                if(i<p){
                    nums[i]=0;
                }else if(i<(p+q)){
                    nums[i]=1;
                }else{//i<(p+q+r)
                    nums[i]=2;
                }
        }

    }
};
